#include <iostream>

int main() {
  std::string *abc = new std::string("abc");
  delete abc;
  std::cout<<"hello world!"<<std::endl;
  return 1;
}
