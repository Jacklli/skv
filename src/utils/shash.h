/* Copyright 2017, Liyinlong.  All rights reserved.
*
* Use of this source code is governed by GPL v2 license
* that can be found in the License file.
*
* Author: Liyinlong (yinlong.lee at hotmail.com)
*/


#ifndef __SHASH_H__
#define __SHASH_H__

#include <string> 
#include "stdint.h"

namespace skv {

class hash;

typedef class hashEntry {
  public:
    friend class hash;
    explicit hashEntry(std::string *key_,std::string *val)
      : key(key_), 
        value(val) {}
    ~hashEntry();
    hashEntry *hashNextEntry() const { return next; }
    std::string *hashEntryKey() const { return key; }
    std::string *hashEntryValue() const { return value; }

  private:
    std::string *key;
    std::string *value;
    class hashEntry *next;
} hashEntry;

typedef class hash {
  public:
    explicit hash(unsigned long size_);
    ~hash();
    int getHashSize() { return size; }
    hashEntry **getHashTable() { return table; }
    hashEntry *hashSearchKey(std::string *key);
    bool hashAddEntry(std::string *key, std::string *value);
    bool hashDelEntry(const std::string *key);
    std::string *getHashValue(std::string *key);
    unsigned long getHashUsed() { return used; };

  private:
    unsigned int doHashKey(std::string *key);
    bool doExpand(unsigned long size);
    hashEntry **table;
    const static uint32_t hash_function_seed = 5381;  // got from redis
    unsigned long size;
    unsigned long sizeMask;
    unsigned long used;
} hash;


bool doRehash(hash *oldHt, hash *newHt);
bool hashExpandIfNeeded(hash *ht);

}


#endif // __SHASH_H__

