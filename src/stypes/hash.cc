/* Copyright 2017, Liyinlong.  All rights reserved.
*
* Use of this source code is governed by GPL v2 license
* that can be found in the License file.
*
* Author: Liyinlong (yinlong.lee at hotmail.com)
*/


int hashObject::getHashObjSize() const {
  return (static_cast<hash>(obj_.ptr))->getHashSize();
}

Hash hashObject::getHashEncoding() const {
  return obj_.getEncoding();
}

bool hashObject::chgHashEncoding(int coding) {
  return obj_.chgEncoding(coding);
}

bool hashObject::decrHashRefCount() {
  return obj_.decrRefCount();
}

bool hashObject::incrHashRefCount() {
  return obj_.incrRefCount();
}

bool hashObject::addHashObjEntry(String& key, String& value) {
  return (static_cast<hash>(obj_.ptr))->hashAddEntry(key, value);
}

bool hashObject::delHashObjEntry(String& key) {
  return (static_cast<hash>(obj_.ptr))->hashDelEntry(key);
}

