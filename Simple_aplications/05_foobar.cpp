#include <iostream>

int main() {

    int value;
    int i;
    std::string two = "foo";
    std::string five = "bar";

    std::cout << "Please enter value:" << std::endl;
    std::cin >> value;

    for(i = 1; i <= value; i++){

      if(i % 2 == 0 && i % 5 ==0){
        std::cout << two << five << std::endl;
      }
      else if(i % 2 == 0){
        std::cout << two << std::endl;
      }
      else if(i % 5 == 0){
        std::cout << five << std::endl;
      }
      else{
        std::cout << i << std::endl;
      }
    }

    return 0;
}