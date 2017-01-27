/* Copyright 2017, Liyinlong.  All rights reserved.
*
* Use of this source code is governed by GPL v2 license
* that can be found in the License file.
*
* Author: Liyinlong (yinlong.lee at hotmail.com)
*/

#ifndef __LISTOBJECT_H__
#define __LISTOBJECT_H__

#include "object.h"

namespace stypes {

class listObject: sObject {
  public:
    explict listObject() {
      type = S_LIST;    // list type
    }
    ~listObject();
};
}

#endif // __LISTOBJECT_H__
