/* Copyright 2017, Liyinlong.  All rights reserved.
*
* Use of this source code is governed by GPL v2 license
* that can be found in the License file.
*
* Author: Liyinlong (yinlong.lee at hotmail.com)
*/

#include "shash.h"
#include <stdlib.h>
#include <stdint.h>
#include <iostream>
#include <string>
#include <functional>


using namespace skv;

hashEntry::~hashEntry() {
  delete key;
  key = NULL;
  delete value;
  value = NULL;
}

hash::hash(unsigned long size_) {
  table = static_cast<hashEntry **>(malloc(size_*sizeof(hashEntry)));
  for(int i=0; i<size_; i++) {
    table[i] = NULL;
  }
  size = size_;
  sizeMask = size - 1;
  used = 0;
}

hash::~hash() {
  free(table);
}

/*
 * idx function is mainly copyed from redis, there may be 
 * some hash key conflict problems, will check it in the future.
*/
unsigned int hash::doHashKey(std::string *key) {
  unsigned int idx = 0;
  unsigned int len = key->length();

  // Mix 4 bytes at a time into the hash 
  const char *data = key->c_str();

  // 'm' and 'r' are mixing constants generated offline.
  //  They're not really 'magic', they just happen to work well.  
  uint32_t seed = hash_function_seed;
  const uint32_t m = 0x5bd1e995;
  const int r = 24;

  // Initialize the hash to a 'random' value 
  uint32_t h = seed ^ len;

  while(len >= 4) {
    uint32_t k = *(uint32_t*)data;
    
    k *= m;
    k ^= k >> r;
    k *= m;
    
    h *= m;
    h ^= k;
    
    data += 4;
    len -= 4;
  }   

  // Handle the last few bytes of the input array  
  switch(len) { 
    case 3: h ^= data[2] << 16;
    case 2: h ^= data[1] << 8;
    case 1: h ^= data[0]; h *= m;
  };

  // Do a few final mixes of the hash to ensure the last few
  //   bytes are well-incorporated. 
  h ^= h >> 13;
  h *= m;
  h ^= h >> 15;

  idx = (unsigned int)h & sizeMask; // & operator to get idx

  return idx;
}

bool hash::hashAddEntry(std::string *key, std::string *value) {
  unsigned long idx = 0;
  hashEntry *entry = new hashEntry(key, value);
  idx = doHashKey(key);
  hashEntry *tmpEntry = table[idx];
  if(tmpEntry != NULL) {
    while(tmpEntry->next != NULL) {
      tmpEntry = tmpEntry->next;
    }
    tmpEntry->next = entry;
  } else {
    table[idx] = entry;
  }
  used++;
  
  return true;
}

bool hash::hashDelEntry(const std::string *key) {

// todo

}

hashEntry *hash::hashSearchKey(std::string *key) {
  unsigned long idx = 0;
  hashEntry *entry = NULL;
  idx = doHashKey(key);
  entry = table[idx];
  while(entry != NULL) {
    if(*(entry->key) == *key) {
      return entry;
    } else if(entry->next) {
      entry = entry->next;
    } else {
      return NULL;
    }
  }
}

std::string *hash::getHashValue(std::string *key) {
  hashEntry *entry = NULL;
  if((entry = hashSearchKey(key))) {
    return entry->hashEntryValue();
  }
  return NULL;
}

bool clearHashResource(hash *ht) {
  unsigned long idx = 0;
  hashEntry *entry = NULL, *nextEntry = NULL;

  while(idx < ht->getHashSize()) {
    entry = (ht->getHashTable())[idx];
    while(entry != NULL) {
      if(entry->hashNextEntry()) {
        nextEntry = entry->hashNextEntry();
      }
      std::cout<<"do delete "<<*(entry->hashEntryKey())<<std::endl;
      delete entry;
      entry = nextEntry;
      nextEntry = NULL;
      ht->decrHashUsed();
    }
    idx++;
  }
  std::cout<<"do delete ht"<<std::endl;
  delete ht;
}

hash *skvdoRehash(hash *oldHt, hash *newHt) {
  unsigned long idx = 0;
  bool ret = true;
  hashEntry *entry = NULL;
  while(idx < oldHt->getHashSize()) {
    entry = (oldHt->getHashTable())[idx];
    while(entry != NULL ) {
      if(!(newHt->hashAddEntry(entry->hashEntryKey(), entry->hashEntryValue()))) {
        std::cout<<"reHashing err occured!"<< std::endl;
        return NULL;
      }
      entry = entry->hashNextEntry();
    }
    idx++;
  }
  delete oldHt;

  return newHt;
}

hash *hashExpandIfNeeded(hash *ht) {
  unsigned int newSize = 0;
  if(ht->getHashUsed() >= ht->getHashSize()) {
    newSize = ht->getHashSize() * 2;
    hash *newHt = new hash(newSize);
    return skvdoRehash(ht, newHt); // return newHt
  }

  return ht;  // no need to expand hash table
}
