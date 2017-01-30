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
}

hashEntry *hash::hashSearchKey(const String& key) {
  /*
    TODO 
  */

  return NULL;
}

bool hash::hashAddEntry(const String& key, const String& value) {
  /*
    TODO
  */

  return true;
}

bool hash::hashDelEntry(const String& key) {
  /*
    TODO
  */
}

