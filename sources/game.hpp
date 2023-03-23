#ifndef GAME_H
#define GAME_H

#define STACK 52
#include <iostream>
#include "player.hpp"

using namespace std;
namespace ariel {};
using namespace ariel;

class Game {
    
    //All are private by default, wrote this so it's easier to understand
    private: 
        
    
    public:
        Player p1;
        Player p2;

        //Empty constructor - not default since there's another one
        Game(){};
        // Parametized constructor
        Game(Player x, Player y);

        void setPlayers(Player, Player);
        
        int getPlayers();
        
//------------------------ requested functions ---------------------
        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();

        string toString();
        

};

#endif