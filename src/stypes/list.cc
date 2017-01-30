/* Copyright 2017, Liyinlong.  All rights reserved.
*
* Use of this source code is governed by GPL v2 license
* that can be found in the License file.
*
* Author: Liyinlong (yinlong.lee at hotmail.com)
*/


bool listObject::listPush(String& entry, int dirtion) {
  if(direction == LEFT) {
    static_cast<list>(obj_.ptr)->listAddNodeHead(entry);
    return true;
  } else if (direction == RIGHT) {
    static_cast<list>(obj_.ptr)->listAddNodeTail(entry);
    return true;
  } else {
    return false;
  }
}

String& listObject::listPop(int dirtion) {
  if(direction == LEFT) {
    return static_cast<list>(obj_.ptr)->listLPop();
  } else if (direction == RIGHT) {
    return static_cast<list>(obj_.ptr)->listRPop();
  } else { // exception, how to hanlde it?
    return NULL;
  }
}

bool listObject::lPush(String& entry) {
  return listPush(entry, LEFT);
}

bool listObject::rPush(String& entry) {
  return listPush(entry, RIGHT);
}

String& listObject::lPop() {
  return listPop(LEFT);
}

String& listObject::rPop() {
  return listPop(RIGHT);
}

int listObject::getListObjectlen() const {
  return (static_cast<list>(obj_.ptr))->getListLen();
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
