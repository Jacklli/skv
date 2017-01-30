/* Copyright 2017, Liyinlong.  All rights reserved.
*
* Use of this source code is governed by GPL v2 license
* that can be found in the License file.
*
* Author: Liyinlong (yinlong.lee at hotmail.com)
*/

~list::list() {
  listNode *node = head;
  while(node != NULL) {
    delete node;
    node = node->next;
  }
}

listNode *list::listSearchKey(const String& key) {
  listNode *node = head;
  while(node != NULL) {
    if(node->value == key) {
      return node;
    } else { 
      node = node->next;
    }
  }

  return NULL;
}

bool list::listAddNodeTail(const String& key) {
  if(0 == len) {
    head = tail = new listNode(key);
    head->next = NULL;
    tail->next = NULL;
    len++;
  }

  if(0 < len) {
    listNode *node = tail;
    listNode *newNode = new listNode(key);
    node->nextNode = newNode;
    tail = node->nextNode;
    len++;
  }

  return true;
}

bool listAddNodeHead(const String& key) {
  /*
    TO DO
  */
 
  return true;
}

bool list::listDelNode(const String& key) {
  if(0 == len) {
    return false;
  } else {
    listNode *node = head;
    while(node != NULL) {
      if(node->value == key) {
        break;
      } else {
        node = node->next;
      }
    }
    if(node->value == head->value) {
      if(1 == getListLen()) { // there's only a head node in list
        delete node;
        head = tail = node = NULL;
        len--;
      } else if(2 == getListLen()) {
        head = head->next; //it implies head->next is NULL now!
        delete node;
        node = NULL;
        tail = head;
        len--;
      } else if(2 < getListLen()) {
        (node->prev)->next = node->next;
        delete node;
        node = NULL;
        len--;
      }
    } 
    return true;
  }
}

String& list::listLPop() {
  String& val = new String(head->value);
  if(listDelNode(val) {
    return val;
  } else {
    return NULL;
  }
}

String& list::listRPop() {
  String& val = new String(tail->value);
  if(listDelNode(val)) {
    return val;
  } else {
    return NULL;
  }
}



