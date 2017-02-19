#include <stdlib.h>
#include <iostream>

#include "shash.h"

int main() {
  std::string *key =  new std::string("abc");
  std::string *value = new std::string("efg");
  skv::hash *ht = new skv::hash(10);

  ht->hashAddEntry(key, value);

  std::cout<<key->data()<<std::endl;
  std::cout<<value->data()<<std::endl;
  std::cout<<ht->getHashValue(key)<<std::endl;

  return 1;
}
