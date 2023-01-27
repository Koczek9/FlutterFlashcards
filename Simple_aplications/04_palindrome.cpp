#include <iostream>

int main() {
    std::string word;
    bool palindrome = true;
    int i;

    std::cout << "Enter a word: " << std::endl;
    std::cin >> word;

    for(i = 0; i <= word.length()/2; i++){
        if(word[i] != word[word.length() -1 -i]){
             palindrome = false;
             break;
        }
    } 

    std::string is = palindrome ? " is " : " is not ";
    std::cout << word << is << "palindrome" << std::endl;

    return 0;
}