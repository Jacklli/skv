/* Copyright 2017, Liyinlong.  All rights reserved.
*
* Use of this source code is governed by GPL v2 license
* that can be found in the License file.
*
* Author: Liyinlong (yinlong.lee at hotmail.com)
*/

#include "slist.h"

using namespace skv;

list::~list() {
  listNode *node = head;
  while(node != NULL) {
    delete node;
    node = node->next;
  }
}

listNode *list::listSearchKey(const std::string *key) {
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

bool list::listAddNodeTail(std::string *key) {
  if(0 == len) {
    head = tail = new listNode(key);
    head->next = tail;
    tail->next = NULL;
    len++;
  } else if (0 < len) {
    listNode *node = tail;
    listNode *newNode = new listNode(key);
    node->next = newNode;
    tail = node->next;
    len++;
  } else {
    return false;
  }

  return true;
}

bool listAddNodeHead(std::string *key) {
  /*
    TO DO
  */
 
  return true;
}

bool list::listDelNode(std::string* key) {
  if(0 == len) {
    return false;
  } else {
    listNode *node = head;
    while(node != NULL) {
      if(*(node->value) == *key) {
        break;
      } else {
        node = node->next;
      }
    }

/*
  two kinds of cases, delete head-node or other node.
*/
    if(*(node->value) == *(head->value)) { // willl delete head-node
      if(1 == getListLen()) { // there's only one head-node in list
        delete node;
        head = tail = node = NULL;
        len--;
      } else if(1 < getListLen()) {
        head = node->next;
        delete node;
        node = NULL;
        len--;
      }
    } else if(1 < getListLen()) { // delete other node
      (node->prev)->next = node->next;
      delete node;
      node = NULL;
      len--;
    }
    return true;
  }
}

std::string *list::listLPop() {
  std::string *val = new std::string((head->value)->c_str());
  if(listDelNode(val)) { // this type will delete the node that has the same value of val
    return val;
  } else {
    return NULL;
  }
}

std::string* list::listRPop() {
  std::string *val = new std::string((tail->value)->c_str());
  if(listDelNode(val)) { // this type will delete the node that has the same value of val
    return val;
  } else {
    return NULL;
  }
}



