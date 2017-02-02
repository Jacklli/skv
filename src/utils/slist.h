/* Copyright 2017, Liyinlong.  All rights reserved.
*
* Use of this source code is governed by GPL v2 license
* that can be found in the License file.
*
* Author: Liyinlong (yinlong.lee at hotmail.com)
*/


#ifndef __SLIST_H__
#define __SLIST_H__

#include <string>

namespace skv {

class list;

typedef class listNode {
  public:
    friend class list;
    explicit listNode(std::string *val)
      : value(val) {}
    ~listNode() { delete value; }
    listNode *listPrevNode() const { return prev; }
    listNode *listNextNode() const { return next; }
    std::string *listNodeValue() const { return value; }

  private:
    class listNode *prev;
    class listNode *next;
    std::string *value;
} listNode;

typedef class list {
  public:
    explicit list() { len = 0; head = NULL; tail = NULL; } 
    ~list();
    int getListLen() { return len; }
    listNode *listFirst() { return head; }
    listNode *listLast() { return tail; }
    listNode *listSearchKey(const std::string *key);
    bool listAddNodeTail(std::string *key);
    bool listAddNodeHead(const std::string *key);
    bool listDelNode(std::string *key);
    std::string *listLPop();
    std::string *listRPop();

  private:
    listNode *head;
    listNode *tail;
    unsigned long len;
} list;

}

#endif // __SLIST_H__

