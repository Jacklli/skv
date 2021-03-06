#include "slist.h"
#include <iostream>
#include <stdlib.h>
#include <jemalloc/jemalloc.h>


int main() {
  std::string *str_ =  new std::string("abcDDDJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJDDDDDDDDDDDDDDDD");
  std::string *str_1 = new std::string("efgkKKKKKKKKKKIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIKKKKKKKKkk");
  std::string *str_2 = new std::string("hijIIIIIIIIIIIIIIIIIIIIIIIIIIISDFFFFFFDDDDDDDDDDDDDDDDDDDDDDDDDDDdII");
  skv::list *lst = new skv::list();

  lst->listAddNodeTail(str_);
  lst->listAddNodeTail(str_1);
  lst->listAddNodeTail(str_2);

  std::cout<<std::endl<<"now list len is:"<<lst->getListLen()<<std::endl;

  std::string *str = lst->listLPop();
  std::string *str1 = lst->listLPop();
  std::string *str2 = lst->listLPop();

  std::cout<<*str<<std::endl;
  std::cout<<*str1<<std::endl;
  std::cout<<*str2<<std::endl;
  std::cout<<"now list len is:"<<lst->getListLen()<<std::endl;
  delete str;
  delete str1;
  delete str2;
  delete lst;

  return 1;
}
