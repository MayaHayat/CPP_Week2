#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

using namespace std;
namespace ariel {};
using namespace ariel;

class Player {
    
    //All are private by default, wrote this so it's easier to understand
    private: 
        
    
    public:
        string name;
        //Empty constructor - not default since there's another one
        Player(){};
        // Parametized constructor
        Player(string name);

        void setName(string);

        string getName();

//------------------------ requested functions ---------------------
        // amount of cards left in stack
        int stacksize(); 
        // amount of cards won by the current player
        int cardesTaken(); 
        

        string toString();
        

};

#endif