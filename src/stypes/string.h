/* Copyright 2017, Liyinlong.  All rights reserved.
*
* Use of this source code is governed by GPL v2 license
* that can be found in the License file.
*
* Author: Liyinlong (yinlong.lee at hotmail.com)
*/


#ifndef __STRING_H__
#define __STRING_H__

#include "object.h"

namespace stypes {

class stringObject: sObject {
  public:
    explicit stringObject(void *ptr)
      : obj_(new sObject(S_STRING, ptr)) {}
    ~stringObject();
    int getStringObjectlen() const;
    int getStringEncoding() const;
    bool chgStringEncoding();
    bool decrStringRefCount();
    bool incrStringRefCount();

  private:
    sObject obj_;
};


}

#endif // __STRING_H__
