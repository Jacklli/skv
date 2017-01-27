/* Copyright 2017, Liyinlong.  All rights reserved.
*
* Use of this source code is governed by GPL v2 license
* that can be found in the License file.
*
* Author: Liyinlong (yinlong.lee at hotmail.com)
*/


#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <boost/noncopyable.hpp>

namespace stypes {

const S_STRING =   1;  // string data type 
const S_LIST   =   2;  // list data type
const S_SET    =   3;  // set data type
const S_SSET   =   4;  // sorted set data type
const S_HASH   =   5;  // hash data type

class sObject: boost::noncopyable {
  public:
    explict sObject() {};
    ~sObject() {};
    decrRefCount();
    incrRefCount();
    
  private:
    unsigned type:4;
    unsigned encoding:4;
    int refcount;
    void *ptr;
};


#endif //__OBJECT_H__
