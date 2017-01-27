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

class hashObject: sObject {
  public:
    explict hashObject() {
      type = S_HASH;    // hash type
    }
    ~hashObject();
};

}

#endif //__HASH_H__
