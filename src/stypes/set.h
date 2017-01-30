/* Copyright 2017, Liyinlong.  All rights reserved.
*
* Use of this source code is governed by GPL v2 license
* that can be found in the License file.
*
* Author: Liyinlong (yinlong.lee at hotmail.com)
*/

#ifndef __SET_H__
#define __SET_H__

#include "object.h"

namespace stypes {

class setObject: sObject {
  public:
    explicit setObject() {
      type = S_SET;    // set type
    }
    ~setObject();
};

}

#endif // __SET_H__
