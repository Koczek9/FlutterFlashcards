#include <iostream>

int main() {
    std::string name;
    int space;

    std::cout << "What's your full name? " << std::endl;
    std::getline (std::cin, name);

    space = name.find(' ');

    //std::cout<< space << std::endl;

    while(name.empty()){
        std::cout << "Please enter valid name" << std::endl;
        std::getline (std::cin, name);
    }

    if(space==-1){
        std::cout << "Your Id is " << name.append("@gmail.com");
    } 
    else{
        //name.erase(space,1);
        name.replace(space,1,".");
        std::cout << "Your Id is " << name.append("@gmail.com");
    }

    //name.erase(name.find(' '),1);


    return 0;
}