/* Copyright 2017, Liyinlong.  All rights reserved.
*
* Use of this source code is governed by GPL v2 license
* that can be found in the License file.
*
* Author: Liyinlong (yinlong.lee at hotmail.com)
*/


#ifndef __LIST_H__
#define __LIST_H__

#include "object.h"

namespace stypes {

class listObject: sObject {
  public:
    explict listObject(void *ptr)
      : obj_(new sObject(S_list, ptr)) {}
    ~listObject();
    int getListObjectlen() const;
    int getListEncoding() const;
    bool chgListEncoding();
    bool decrListRefCount();
    bool incrListRefCount();
    bool lPush(String &entry);
    bool rPush(String &entry);
    String& lPop();
    String& rPop();
  private:
    bool listPush(String &entry, int dirtion);
    String& listPop(int dirtion);
    sObject obj_;
    list *lst_;
};


}

#endif // __list_H__
