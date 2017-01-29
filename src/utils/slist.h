/* Copyright 2017, Liyinlong.  All rights reserved.
*
* Use of this source code is governed by GPL v2 license
* that can be found in the License file.
*
* Author: Liyinlong (yinlong.lee at hotmail.com)
*/


#ifndef __SLIST_H__
#define __SLIST_H__

namespace skv {

typedef class listNode {
  public:
    friend class list;
    explicit listNode(void *val)
      : value(val) {}
    ~listNode();
    listNode *listPrevNode() { return prev; }
    listNode *listNextNode() { return next; }
    void *listNodeValue() { return value; }

  private:
    class listNode *prev;
    class listNode *next;
    void *value;
} listNode;

typedef class list {
  public:
    explicit list() { len = 0; head = NULL; tail = NULL: } 
    ~list();
    int listLen() { return len; }
    listNode *listFirst() { return head; }
    listNode *listLast() { return tail; }
    listNode *listSearchKey(void &key);
    bool listAddNodeTail(void &key);
    bool listDelNode(void *key);

  private:
    listNode *head;
    listNode *tail;
    unsigned long len;
} list;

}

#endif // __SLIST_H__

