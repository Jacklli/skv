
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include "shash.h"


int main() {
  std::string *key =  NULL;
  std::string *value = NULL;
  skv::hash *ht = new skv::hash(3);
  bool ret = true;

  srand(time(NULL));
  for(int i=0; i<10; i++) {
    key = new std::string(std::to_string(rand()));
    value = new std::string(std::to_string(rand()));
    std::cout<<"i = "<<i<<std::endl;
    std::cout<<"the key we added is:"<<key->data()<<std::endl;
    std::cout<<"the value we added is:"<<value->data()<<std::endl;

    ht->hashAddEntry(key, value);
    std::string *val = NULL;
    val = ht->getHashValue(key);
    if(val) {
      std::cout<<"the value from key we got is:"<<*val<<std::endl;
    } else {
      std::cout<<"don't found such key"<<std::endl;
    }
    ht = hashExpandIfNeeded(ht);
  }
  std::cout<<"the entries used from hash table is:"<<ht->getHashUsed()<<std::endl;

  return 1;
}
