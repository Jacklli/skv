/* Copyright 2017, Liyinlong.  All rights reserved.
*
* Use of this source code is governed by GPL v2 license
* that can be found in the License file.
*
* Author: Liyinlong (yinlong.lee at hotmail.com)
*/

int stringObject::getStringObjectlen() const {
  return strlen(static_cast<char *>(obj_->ptr));
}

String stringObject::getStringEncoding() const {
  return obj_.getEncoding();
}

bool stringObject::chgStringEncoding(int coding) {
  return obj_.chgEncoding(coding);
}

bool stringObject::decrStringRefCount() {
  return obj_.decrRefCount();
}

bool stringObject::incrStringRefCount() {
  return obj_.incrRefCount();
}

