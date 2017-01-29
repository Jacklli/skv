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

const ENCOD_RAW  =  1; // no encoding
const ENCOD_ZIP  =  2; // zip encoding

class sObject: boost::noncopyable {
  public:
    explict sObject(unsigned type, char *ptr)
      : type(type),
        encoding(ENCOD_RAW),
        refcount(0),
        ptr(ptr) {}
    ~sObject() {}
    int getLen();
    int getEncoding();
    bool chgEncoding(int coding);
    bool decrRefCount();
    bool incrRefCount();
    
  private:
    unsigned type:4;
    unsigned encoding:4;
    int refcount;
    void *ptr;
};


#endif //__OBJECT_H__
