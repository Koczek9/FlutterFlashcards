#include <iostream>
#include <vector>

int main() 
{
    std::vector<int> primes;

    for(int i = 2; i <= 100000; i++) 
    {
        bool is_prime = true;
        for(int prime : primes){
            if(i % prime == 0)
            {
                is_prime = false;
                break;
            }
        }

        if(is_prime)
        { 
            primes.emplace_back(i);
            std::cout << i << " is a prime number" << std::endl;
        }
    }

    return 0;
}
