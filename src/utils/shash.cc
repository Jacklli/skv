/* Copyright 2017, Liyinlong.  All rights reserved.
*
* Use of this source code is governed by GPL v2 license
* that can be found in the License file.
*
* Author: Liyinlong (yinlong.lee at hotmail.com)
*/


hashEntry::~hashEntry() {
  delete key;
  delete value;
}

hash::hash(size_) {
  table = static_cast<hashEntry **>(malloc(size_*sizeof(hashEntry)));
  size = size_;
}

hash::~hash() {
  unsigned long idx = 0;
  hashEntry *entry = NULL, *nextEntry = NULL;
  while(idx < size) {
    entry = table[idx];
    while(entry != NULL ) {
      nextEntry = entry->next;
      delete entry;
      entry = nextEntry;
    }
    idx++;
  }
  free(table);
}

hashEntry *hash::hashSearchKey(const String& key) {
  unsigned long idx = 0;
  hashEntry *entry = NULL;
  while(idx < size) {
    entry = table[idx];
    if(entry->key == key) {
      return entry;
    }
    idx++;
  }

  return NULL;
}

unsigned int hash::doHashKey(String& key) {
  unsigned int idx = 0, hval;
  std::hash<std::string> h;
  hval = h(key);
  idx = hval & sizeMask;
  return idx;
}


bool hash::hashAddEntry(const String& key, const String& value) {
  unsigned long idx = 0;
  hashEntry *entry = new hashEntry(key, value);

  
  return true;
}

bool hash::hashDelEntry(const String& key) {
  /*
    TODO
  */
}

bool doRehash(hash& oldHt, hash& newHt) {
  unsigned long idx = 0;
  bool ret = true;
  hashEntry *entry = NULL, *nextEntry = NULL;
  while(idx < oldHt.size) {
    entry = (oldHt.table)[idx];
    while(entry != NULL ) {
      nextEntry = entry->next;
      if(!(newHt.hashAddEntry(entry->key, entry->value))) {
        cout<<"reHashing err occured!"<<end;
        return false;
      }
      entry = nextEntry;
    }
    idx++;
  }
  delete oldHt;

  return true;
}

bool hashExpandIfNeeded(hash& ht) {
  unsigned int newSize = 0;
  if(ht.used >= ht.size) {
    newSize = (ht.size)*2
    hash& newHt = new hash(newSize);
    return doRehash(ht, newHt);
  }
  return true;  // no need to expand hash table
}


