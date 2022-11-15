#include <iostream>
#include <algorithm>

std::string dot(std::string name, int space);

int main() {
    std::string name;
    int space;

    while(name.empty()){
        std::cout << "Please enter full name" << std::endl;
        std::getline (std::cin, name);
    }

    std::transform(name.begin(), name.end(), name.begin(), ::tolower);
    
    name = dot(name, space);
    std::cout << "Your Id is " << name.append("@gmail.com");

    return 0;
}

std::string dot(std::string name, int space){
    space = name.find(' ');

    if(space==-1){
        return name;
    }
    else{
        name.replace(space,1,".");
        return dot(name, space);
    }
}