#include <iostream>
#include <vector>

int main() 
{
    for(int i = 2; i <= 10; i++) 
    {
        bool is_prime = true;
        for(int j = 2; j < i; j++){
            if(i % j == 0){
                is_prime = false;
                break;
            }
        }

        if(is_prime == false){
            //std::cout << i << "is not a prime number" << std::endl;
        }
        else{
            std::cout << i << " is a prime number" << std::endl;
        }
    }

    return 0;
}
