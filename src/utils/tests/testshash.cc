
#include "shash.h"
#include <stdlib.h>
#include <iostream>
#include <time.h>

const int keyNums = 5000;

int main() {
  std::string *key[keyNums] =  { NULL };
  std::string *value[keyNums] = { NULL };
  skv::hash *ht = new skv::hash(30);
  bool ret = true;

  srand(time(NULL));
  for(int i=0; i<keyNums; i++) {
    key[i] = new std::string(std::to_string(rand()));
    value[i] = new std::string(std::to_string(rand()));
//    std::cout<<"i = "<<i<<std::endl;
//    std::cout<<"the key[i] we added is:"<<key[i]->data()<<std::endl;
//    std::cout<<"the value[i] we added is:"<<value[i]->data()<<std::endl;

    ht = hashExpandIfNeeded(ht);
    ht->hashAddEntry(key[i], value[i]);
  }
  std::cout<<"the size of hash table is:"<<ht->getHashSize()<<std::endl;
  std::cout<<"the entries used from hash table is:"<<ht->getHashUsed()<<std::endl;
  for(int i=0; i<keyNums; i++) {
//    std::cout<<"i = "<<i<<std::endl;
    std::string *val = NULL;
    val = ht->getHashValue(key[i]);
    if(val) {
//      std::cout<<"the value[i] from key[i] we got is:"<<*val<<std::endl;
    } else {
//      std::cout<<"don't found such key[i]"<<std::endl;
    }
  }

  clearHashResource(ht);
  return 1;
}
