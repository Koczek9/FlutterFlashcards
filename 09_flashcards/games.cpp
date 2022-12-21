#include "games.h"
#include "import_read.h"

void shuffle(std::vector<Flashcard> &cards)
{
    auto rd = std::random_device {}; 
    auto rng = std::default_random_engine { rd() };
    std::shuffle(std::begin(cards), std::end(cards), rng);
}

int checkInput(int maxInput, bool isInputANumber = true)
{
    std::string input;
    std::cin >> input;
    int inputNumber;
    bool isValid = false;

    while(!isValid)
    {
        if(input[0] == 'q' || input[0] == 'Q')
        {
            return QUIT_CODE;
        }
        
        if(isInputANumber)
        {
            try
            {
                inputNumber = std::stoi(input) - 1;
            }
            catch(std::invalid_argument)
            {
                // Nothing to do as it is the same as int out of bound.
            }
        }
        else
        {
            if(input[0] >= 'a')
            {
                inputNumber = input[0] - 'a';
            }
            else
            {
                inputNumber = input[0] - 'A';
            }
        }

        if(inputNumber < 0 || inputNumber >= maxInput)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            
            if(isInputANumber)
            {
                std::cout << "Enter a number from 1 to " << maxInput << std::endl;
            }
            else
            {
                char maxLetter = 'A' + maxInput - 1;
                std::cout << "Enter a letter from A to " << maxLetter << std::endl;
            }
            
            std::cin >> input;
        }
        else
        {
            isValid = true;
        }     
    }

    return inputNumber;
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
    writeXML(DATA_BASE_FILE_NAME, cards);
}

/*
* Appends word with spaces so it has desired length.
*
* @param[in] input   original word
* @param[in] length  desired length
*
* @return new word with desired length
*/
std::string nLong(std::string input, int length)
{
    std::string temp = input;
    
    while (temp.length() < length)
    {
        temp += " ";
    }
    
    return temp;
}

/*
* Prints out four english words end four translations.
* You need to find the pairs.
*/
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

    maxLength++;

    int numberOfIterations = 0;
    const int maxNumberOfWords = 6;
    int numberInput;
    int letterInput;


    while((numberOfIterations + 1) * maxNumberOfWords <= cards.size())
    {
        int numberOfWords = maxNumberOfWords;
        int i = 0;
        std::vector<int> indexOfWords;
        std::vector<int> indexOfTranslations;
        srand(time(NULL));

        if(numberInput == QUIT_CODE || letterInput == QUIT_CODE)
        {
            break;
        }

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
            std::string wordsToMatch = "";
            std::string translationsToMatch = "";

            while(i < numberOfWords)
            {
                wordsToMatch = std::to_string(i+1) + 
                                ' ' + 
                                nLong(cards[indexOfWords[i] + numberOfIterations * 4].word, maxLength);
                translationsToMatch = std::string(1,'A'+i) + 
                                        ' ' +
                                        cards[indexOfTranslations[i] + numberOfIterations * 4].translation;

                std::cout << wordsToMatch << translationsToMatch << std::endl;
                i++;
            }

            std::cout << std::endl;

            numberInput = checkInput(numberOfWords, true);
            if(numberInput == QUIT_CODE)
            {
                break;
            }
            letterInput = checkInput(numberOfWords, false);

            if(letterInput == QUIT_CODE)
            {
                break;
            }
            else if(indexOfWords[numberInput] == indexOfTranslations[letterInput])
            {
                std::cout << std::endl << "correct" << std::endl << std::endl;
                indexOfWords.erase(indexOfWords.begin() + numberInput);
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

/*
* Prints out one english words that is not known yet and four translations.
* You need to choose correct translation. After 5 correct guesses in a row marks word as known.
*/
void chooseTranslation(std::vector<Flashcard> cards)
{
    std::cout << "******************************* Choose translation game *******************************" << std::endl;
     std::cout << "Please choose translation" << std::endl << std::endl;

    int maxLength = 0;

    for(int x = 0; x < cards.size(); x++)
    {
        if(cards[x].translation.length() > maxLength)
        {
            maxLength = cards[x].translation.length();
        }
    }
    
    const int numberOfTranslations = 4;
    const int levelOfKnowledgeThreshold = 5;
    std::vector<Flashcard> cardsNotKnown;
    srand(time(NULL));

    std::copy_if(cards.begin(), cards.end(), std::back_inserter(cardsNotKnown), [] (Flashcard card) {return card.getKnown() == 0; });

    while(cardsNotKnown.size() >= numberOfTranslations)
    {
        int i = 0;
        std::vector<int> indexOfTranslations;
        while(i < numberOfTranslations)
        {
            int indexNumber = (rand() % cardsNotKnown.size());
            if(std::find(indexOfTranslations.begin(), indexOfTranslations.end(), indexNumber) == indexOfTranslations.end())
            {
                indexOfTranslations.emplace_back(indexNumber);
                i++;
            }
        }

        int indexNumberWord = (rand() % numberOfTranslations);

        std::cout << cardsNotKnown[indexOfTranslations[indexNumberWord]].word << std::endl;
        i = 0;
        while(i < numberOfTranslations)
        {
            std::string translationsToChoose = std::to_string(i+1) +
                                    ' ' +
                                    nLong(cardsNotKnown[indexOfTranslations[i]].translation, maxLength);
            i++;
            std::cout << translationsToChoose << std::endl;
        }

        int input = checkInput(numberOfTranslations);

        if(input == QUIT_CODE)
        {
            break;
        }
        else if(input == indexNumberWord)
        {
            std::cout << "Correct" << std::endl;

            auto itr = std::find_if(cards.begin(), cards.end(),
                        [cardsNotKnown,indexOfTranslations,indexNumberWord] (Flashcard card)
                        {return card.word == cardsNotKnown[indexOfTranslations[indexNumberWord]].word;});
            auto index = itr - cards.begin();
            cards[index].levelOfKnowledge += 1;

            if(cards[index].levelOfKnowledge == levelOfKnowledgeThreshold)
            {
                cards[index].setKnown(true);
                cardsNotKnown.erase(cardsNotKnown.begin() + indexOfTranslations[indexNumberWord]);
            }
        }
        else
        {
            std::cout << "It is not correct" << std::endl;
            std::cout << "Correct answer is " << cardsNotKnown[indexOfTranslations[indexNumberWord]].translation << std::endl;

            auto index = std::find_if(cards.begin(), cards.end(),
                        [cardsNotKnown,indexOfTranslations,indexNumberWord] (Flashcard card)
                        {return card.word == cardsNotKnown[indexOfTranslations[indexNumberWord]].word;});
            cards[index-cards.begin()].levelOfKnowledge = 0;
        }
    }

    writeXML(DATA_BASE_FILE_NAME, cards);
}
