/* Copyright 2017, Liyinlong.  All rights reserved.
*
* Use of this source code is governed by GPL v2 license
* that can be found in the License file.
*
* Author: Liyinlong (yinlong.lee at hotmail.com)
*/


#ifndef __SHASH_H__
#define __SHASH_H__

namespace skv {

typedef class hashEntry {
  public:
    friend class hash;
    explicit hashEntry(String& key_, String& val)
      : key(key_), 
        value(val) {}
    ~hashEntry();
    hashEntry *hashNextEntry() const { return next; }
    String& hashEntryValue() const { return value; }

  private:
    String& key;
    String& value;
    class hashEntry *next;
} hashEntry;

typedef class hash {
  public:
    explicit hash() { size = 0; } 
    ~hash();
    int getHashSize() { return size; }
    hashEntry *hashSearchKey(const String& key);
    bool hashAddEntry(const String& key, const String& value);
    bool hashDelEntry(const String& key);

  private:
    hashEntry **table;
    unsigned long size;
    unsigned long sizemask;
    unsigned long used;
} hash;

}

#endif // __SHASH_H__

