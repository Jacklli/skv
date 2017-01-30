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
    ~listNode() { free(value); }
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
    int getListLen() { return len; }
    listNode *listFirst() { return head; }
    listNode *listLast() { return tail; }
    listNode *listSearchKey(const void& key);
    bool listAddNodeTail(const void& key);
    bool listAddNodeHead(const void& key);
    bool listDelNode(const void& key);
    String& listLPop();
    String& listRPop();

  private:
    listNode *head;
    listNode *tail;
    unsigned long len;
} list;

}

#endif // __SLIST_H__

