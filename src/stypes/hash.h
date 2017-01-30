/* Copyright 2017, Liyinlong.  All rights reserved.
*
* Use of this source code is governed by GPL v2 license
* that can be found in the License file.
*
* Author: Liyinlong (yinlong.lee at hotmail.com)
*/


#ifndef __HASH_H__
#define __HASH_H__

#include "object.h"

namespace stypes {

class hashObject {
  public:
    explicit hashObject()
      : obj_(new sObject(S_HASH, new hash())) {}
    ~hashObject();
    int getHashObjSize() const;
    int getHashObjEncoding() const;
    bool chgHashObjEncoding();
    bool decrHashObjRefCount();
    bool incrHashObjRefCount();
    bool addHashObjEntry(String& key, String& value);
    bool delHashObjEntry(String& key);

  private:
    sObject obj_;
};


}

#endif // __HASH_H__
