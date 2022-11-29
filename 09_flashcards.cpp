#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

std::string find(std::string sentence, std::string word);

class Flashcard {
    std::string known = "false";
    public:
    std::string word;
    std::string usage;
    std::string translation;

    Flashcard(std::string word, std::string usage, std::string translation)
    {
        int colon = word.find(':');
        word = word.substr(colon + 1);
        std::transform(word.begin(), word.end(), word.begin(), tolower);
        this->word = word;
        this->usage = usage;
        this->translation = translation;
    }

    Flashcard(std::string word, std::string usage) : Flashcard(word,usage, std::string())
    {

    }

    Flashcard(std::string serializedItem)
    {
        deserialize(serializedItem);
    }

    std::string serialize()
    {
        std::string serialize;
        serialize += "<Flashcard>\n";
        serialize += "    <word>" + word + "</word>\n";
        serialize += "    <usage>" + usage + "</usage>\n";
        serialize += "    <translation>" + translation + "</translation>\n";
        serialize += "    <known>" + known + "</known>\n";
        serialize += "</Flashcard>\n";
        return serialize;
    }

    void deserialize(std::string serialize)
    {
        word = find(serialize, "word");
        usage = find(serialize, "usage");
        translation = find(serialize, "translation");
        known = find(serialize, "known");
    }

    void setKnown(bool isKnown)
    {
        if(isKnown)
        {
            known = "true";
        }
        else 
        {
            known = "false";
        }
    }

    bool getKnown()
    {
        bool isKnown = 0;
        if(known == "true")
        {
            isKnown = 1;
        }
        return isKnown;
    }

};

void learning(std::vector<Flashcard> cards);
void matchingGame(std::vector<Flashcard> cards);

int main() 
{
    std::string line;
    std::vector<Flashcard> cards;

    //Read from the imported text file.
    /* std::ifstream flashcards ("flashcards4.csv");

    while (getline (flashcards, line))
    {
      int position = line.find('\t');
      std::string translation = line.substr(0,position);
      line = line.substr(position + 1);
      position = line.find('\t');
      std::string usage = line.substr(position + 1);
      std::string word = line.substr(0,position);

      cards.emplace_back(Flashcard(word, usage, translation));
    } */


    //Read from json file.
    std::string fullFile;
    std::ifstream MyFileRead ("flashcardsJSON.json");
    while (getline (MyFileRead, line))
    {
        fullFile += line;
    }

    MyFileRead.close ();

    //Making a vector of cards
    bool working = true;
    while(working)
    {
        std::string card = find(fullFile, "Flashcard");
        if (card.empty())
        {
            working = false;
            break;
        }
        cards.emplace_back(Flashcard(card));
        int position2 = fullFile.find("</Flashcard>");
        fullFile = fullFile.substr(position2 +1);
    }

    //shuffle cards
    /* auto rd = std::random_device {}; 
    auto rng = std::default_random_engine { rd() };
    std::shuffle(std::begin(cards), std::end(cards), rng); */


    //learning(cards);
    matchingGame(cards);

    return 0;
}

//Function that finds word keys in read file.
std::string find(std::string sentence, std::string word)
{   
    int position1 = sentence.find("<" + word + ">");
    int position2 = sentence.find("</" + word + ">");

    if (position1 < 0 || position2 < 0)
    {
        return std::string();
    }
    return sentence.substr(position1 + word.length() + 2, position2 - position1 - word.length() - 2);
}

//Flashcard learning function
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

     //Write to the json file.
    std::ofstream MyFileWrite ("flashcardsJSON.json");

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
    std::cout << "******************************* Matching game *******************************" << std::endl << std::endl;

    //Finding the longest word or translation

    int maxLength = 0;

    for(int x = 0; x < cards.size(); x++)
    {
        if(cards[x].word.length() > maxLength)
        {
            maxLength = cards[x].word.length();
            //std::cout << cards[x].word << std::endl;
        }
    }

    for(int x = 0; x < cards.size(); x++)
    {
        if(cards[x].translation.length() > maxLength)
        {
            maxLength = cards[x].translation.length();
            //std::cout << cards[x].translation << std::endl;
        }
    }

    maxLength++;
    
    std::string fourWords;
    std::string fourTranslations;
    int i = 0;
    std::vector<int> fourNum;
    srand(time(NULL));

    while(i < 4)
    {
        int num = (rand() % 4);

        if(std::find(fourNum.begin(), fourNum.end(), num) == fourNum.end())
        {
            fourNum.emplace_back(num);
            fourWords += nLong(cards[i].word, maxLength);
            fourTranslations += nLong(cards[fourNum[i]].translation, maxLength);
            i += 1;
        }  
    }

    std::cout << fourWords << std::endl;
    std::cout << fourTranslations << std::endl;
}