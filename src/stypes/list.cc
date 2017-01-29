/* Copyright 2017, Liyinlong.  All rights reserved.
*
* Use of this source code is governed by GPL v2 license
* that can be found in the License file.
*
* Author: Liyinlong (yinlong.lee at hotmail.com)
*/

int listObject::getListObjectlen() const {
  return lst_.getLen();
}

List listObject::getListEncoding() const {
  return obj_.getEncoding();
}

bool listObject::chgListEncoding(int coding) {
  return obj_.chgEncoding(coding);
}

bool listObject::decrListRefCount() {
  return obj_.decrRefCount();
}

bool listObject::incrListRefCount() {
  return obj_.incrRefCount();
}

bool listObject::listPush(String &entry, int dirtion) {
  return lst_->listPush(lst_, entry, dirtion);
}

bool listObject::listPop(int dirtion) {
  return lst_->listPop(lst_, dirtion);
}

bool listObject::lPush(String &entry) {
  return lst_->listPush(entry, LEFT);
}

bool listObject::rPush(String &entry) {
  return lst_->listPush(entry, RIGHT);
}

String& listObject::lPop() {
  return lst_->listPop(LEFT);
}

String& listObject::rPop() {
  return lst_->listPop(RIGHT);
}

