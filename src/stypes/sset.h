/* Copyright 2017, Liyinlong.  All rights reserved.
*
* Use of this source code is governed by GPL v2 license
* that can be found in the License file.
*
* Author: Liyinlong (yinlong.lee at hotmail.com)
*/

#ifndef __SSETOBJECT_H__
#define __SSETOBJECT_H__

#include "object.h"

namespace stypes {

class ssetObject: sObject {
  public:
    expict ssetObject() {
      type = S_SSET;    // zset type
    }
    ~ssetObject();
};

}

#endif //__SSETOBJECT_H__
