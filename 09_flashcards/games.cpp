#include "games.h"

void shuffle(std::vector<Flashcard> &cards)
{
    auto rd = std::random_device {}; 
    auto rng = std::default_random_engine { rd() };
    std::shuffle(std::begin(cards), std::end(cards), rng);
}

void learning(std::vector<Flashcard> cards)
{   
    std::cout << "********************************* Learning *********************************" << std::endl << std::endl;
    
    bool showWord = true;
    for(int i = 0; i < cards.size();)
    {   
        if(cards[i].getKnown())
        {
            i++;
            continue;
        }
        
        if(showWord)
        {
            std::cout << "                                  " << cards[i].word << std::endl << std::endl;
        }
        
        std::cout << "1 see translation    2 see usage    3 already known   4 next word     Q quit"<< std::endl;

        char choice;
        std::cin >> choice;
        showWord = true;

        switch (choice)
        {
        case '1':
            std::cout << cards[i].translation << std::endl;
            showWord = false;
            break;
        case '2':
            std::cout << cards[i].usage << std::endl << std::endl;
            showWord = false;
            break;
        case '3':
            cards[i].setKnown(true);
            i++;
            break;
        case '4':
            i++;
            break;
        case 'q':
        case 'Q':
            i = cards.size();
            break;
        default:
            break;
        }
    }

    std::ofstream MyFileWrite ("flashcardsXML.xml");

    for(auto card : cards)
    {
        MyFileWrite << card.serialize();
    }

    MyFileWrite.close ();
}

std::string nLong(std::string input, int length)
{
    std::string temp = input;
    
    while (temp.length() < length)
    {
        temp += " ";
    }
    
    return temp;
}

void matchingGame(std::vector<Flashcard> cards)
{
    std::cout << "******************************* Matching game *******************************" << std::endl;
    std::cout << "Please choose english word and its translation" << std::endl << std::endl;

    int maxLength = 0;

    for(int x = 0; x < cards.size(); x++)
    {
        if(cards[x].word.length() > maxLength)
        {
            maxLength = cards[x].word.length();
        }
    }

    for(int x = 0; x < cards.size(); x++)
    {
        if(cards[x].translation.length() > maxLength)
        {
            maxLength = cards[x].translation.length();
        }
    }

    maxLength++;

    int numberOfIterations = 0;

    while((numberOfIterations + 1) * 4 <= cards.size())
    {
        std::string wordsToMatch;
        std::string translationsToMatch;
        int numberOfWords = 4;
        int i = 0;
        std::vector<int> indexOfWords;
        std::vector<int> indexOfTranslations;
        srand(time(NULL));

        while(i < numberOfWords)
        {
            int num = (rand() % numberOfWords);

            if(std::find(indexOfTranslations.begin(), indexOfTranslations.end(), num) == indexOfTranslations.end())
            {
                indexOfTranslations.emplace_back(num);
                indexOfWords.emplace_back(i);
                i += 1;
            }  
        }

        while(numberOfWords > 0)
        {
            i = 0;
            wordsToMatch = "";
            translationsToMatch = "";

            while(i < numberOfWords)
            {
                wordsToMatch += std::to_string(i+1) + 
                                ' ' + 
                                nLong(cards[indexOfWords[i] + numberOfIterations * 4].word, maxLength);
                translationsToMatch += std::string(1,'A'+i) + 
                                        ' ' +
                                        nLong(cards[indexOfTranslations[i] + numberOfIterations * 4].translation, maxLength);
                i++;
            }

            std::cout << wordsToMatch << std::endl;
            std::cout << translationsToMatch << std::endl << std::endl;

            int numberInput;
            char letterInput;

            std::cin >> numberInput;
            std::cin >> letterInput;

            if(letterInput >= 'a')
            {
                letterInput = letterInput - 'a';
            }
            else
            {
                letterInput = letterInput - 'A';
            }

            if(indexOfWords[numberInput -1] == indexOfTranslations[letterInput])
            {
                std::cout << "correct" << std::endl;
                indexOfWords.erase(indexOfWords.begin() + numberInput - 1);
                indexOfTranslations.erase(indexOfTranslations.begin() + letterInput);

                numberOfWords -= 1;
            }
            else
            {
                std::cout << "not correct" << std::endl;
            }
        }

        numberOfIterations += 1;
    } 
}