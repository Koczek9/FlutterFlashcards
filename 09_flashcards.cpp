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

int main() 
{
    std::string line;
    std::vector<Flashcard> cards;

    //Read from the text file
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

    std::string fullFile;
    std::ifstream MyFileRead ("flashcardsJSON.json");
    while (getline (MyFileRead, line))
    {
        fullFile += line;
    }

    MyFileRead.close ();

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

    //std::cout << "Choose one of the following options: " << std::endl;

    learning(cards);

    


    //std::cout << cards[0].serialize();

    return 0;
}

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

void learning(std::vector<Flashcard> cards)
{   
    std::cout << "********************************* Learning *********************************" << std::endl << std::endl;
    
    for(int i = 0; i < cards.size();)
    {
        std::cout << "                                  " << cards[i].word << std::endl << std::endl;
        std::cout << "1 see translation    2 see usage    3 already known   4 next word     Q quit"<< std::endl;

        char choice;
        std::cin >> choice;

        switch (choice)
        {
        case '1':
            std::cout << cards[i].translation << std::endl;
            break;
        case '2':
            std::cout << cards[i].usage << std::endl << std::endl;
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
    
     //Write to the json file
    std::ofstream MyFileWrite ("flashcardsJSON.json");

    for(auto card : cards)
    {
        MyFileWrite << card.serialize();
    }

    MyFileWrite.close ();
}