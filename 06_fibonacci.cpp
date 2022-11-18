#include <iostream>

int fibonacciloop(int number);
int fibonaccirec(int number);

int main() {
   
    int number;

    std::cout << "Enter a number of terms" << std::endl;
    std::cin >> number;


    std::cout << fibonaccirec(number) << std::endl;

    return 0;
}

int fibonacciloop(int number){
    
    int a = 0;
    int b = 1;
    int c;

    if(number == 0){
        return 0;
    }
    else if(number == 1){
        return 1;
    }
    else{
        for(int i = 2; i <=number; i++){
        c = a + b;

        a = b;
        b = c;
        }
        return c;
    }
    
}

int fibonaccirec(int number){
    if(number == 0){
        return 0;
    }
    else if(number == 1){
        return 1;
    }
    else{
        return fibonaccirec(number - 1) + fibonaccirec(number-2);
    }
}