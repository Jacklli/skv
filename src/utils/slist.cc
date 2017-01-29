/* Copyright 2017, Liyinlong.  All rights reserved.
*
* Use of this source code is governed by GPL v2 license
* that can be found in the License file.
*
* Author: Liyinlong (yinlong.lee at hotmail.com)
*/


listNode *list::listSearchKey(const &key) {
  listNode *node = head;
  while(node != NULL) {
    if(strcmp(node->value, key) == 0) {
      return node;
    } else { 
      node = node->next;
    }
  }

  return NULL;
}

bool list::listAddNodeTail(void &key) {
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

bool list::listDelNode(void &key) {
  listNode *node = head;
  while(node != NULL) {
    if(strcmp(node->value, key) == 0) {
      break;
    } else {
      node = node->next;
    }
  }
  if(strcmp(node->value, head->value) == 0) {
    if(1 == listLen()) { // there's only a head node in list
      delete node;
      head = tail = node = NULL;
      len--;
    } else if(2 == listLen()) {
      head = head->next; //it implies head->next is NULL now!
      delete node;
      node = NULL;
      tail = head;
      len--;
    } else if(2 < listLen()) {
      (node->prev)->next = node->next;
      delete node;
      node = NULL;
      len--;
    }
  } 

  return true;
}
