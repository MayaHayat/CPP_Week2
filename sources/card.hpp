#ifndef CARD_H
#define CARD_H

#define STACK 52
#include <iostream>

using namespace std;
namespace ariel {};
using namespace ariel;

class Card {
    
    //All are private by default, wrote this so it's easier to understand
    private: 
        int number;
        string colour;
        string suit;
    
    public:
        //Empty constructor - not default since there's another one
        Card();
        // Parametized constructor
        Card(int number, string colour, string suit);

        void setNumber(int);
        void setColour(string);
        void setSuit(string);

        int getNumber();
        string getColour();
        string getSuit();

        string toString();
        

};

#endif