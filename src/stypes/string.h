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
    explict stringObject() {
      type = S_STRING;    // string type
    }
    ~stringObject();
    bool initStringObject(String &);
    int getStringObjectlen() const;
};


}

#endif // __STRING_H__
