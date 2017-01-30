/* Copyright 2017, Liyinlong.  All rights reserved.
*
* Use of this source code is governed by GPL v2 license
* that can be found in the License file.
*
* Author: Liyinlong (yinlong.lee at hotmail.com)
*/


int sObject::getEncoding() const {
  return encoding;
}

bool sObject::chgEncoding(int coding) {
  encoding = coding;
  return true; 
}

bool sObject::decrRefCount() {
  refcount--;
  return true;
}

bool sObject::incrRefCount() {
  refcount++;
  return true;
}

