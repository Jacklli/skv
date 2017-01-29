/* Copyright 2017, Liyinlong.  All rights reserved.
*
* Use of this source code is governed by GPL v2 license
* that can be found in the License file.
*
* Author: Liyinlong (yinlong.lee at hotmail.com)
*/


int stringObject::getStringObjectlen() const {
  return strlen(static_cast<char *>(ptr));
}

int tringObject::getStringEncoding() const {
  return encoding;
}

bool stringObject::chgStringEncoding(int coding) {
  encoding = coding;
  return true; 
}

bool stringObject::decrStringRefCount() {
  refcount--;
  return true;
}

bool stringObject::incrStringRefCount() {
  refcount++;
  return true;
}

