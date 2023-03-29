#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"

#define FULLSTACK 52 //incase some cards were lost for example
#define ROUNDS 3 

using namespace std;

// #1
TEST_CASE("#Cards per player at start of game") {
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);
    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);
}

// #2
TEST_CASE("Total #Cards after N round") {
    //Number of rounds can be changed as used a constant to make easier.
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);
    for (int i = 0  ; i < ROUNDS ; i++) {
    game.playTurn();
   }

    CHECK(p1.stacksize() + p2.stacksize() + p1.cardesTaken() + p2.cardesTaken() == 52 );
}

// #3
TEST_CASE ("Check players"){
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);

    CHECK(game.p1.name == "Alice");
    CHECK(game.p2.name == "Bob");
}

// #4
TEST_CASE ("Make sure someone won at the end"){
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);
    game.playAll();
    if (game.p1.stacksize() > 0){
        CHECK(game.p1.stacksize() == FULLSTACK);
        CHECK(game.p2.stacksize() == 0);
    }
    else{
        CHECK(game.p2.stacksize() == FULLSTACK);
        CHECK(game.p1.stacksize() == 0);
    }
}

// #5
TEST_CASE("Check the amount of cards per player after 5 turns."){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    for (int i = 0; i < 5; i++) {
        game.playTurn();
    }

    CHECK(p1.stacksize() <= 21);
    CHECK(p2.stacksize() <= 21);
}

// #6
TEST_CASE ("Make sure no errors are thrown"){
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);
    CHECK_NOTHROW(game.printLastTurn());
    CHECK_NOTHROW(game.playAll());
    CHECK_NOTHROW(game.printWiner());
    CHECK_NOTHROW(game.printLog());
    CHECK_NOTHROW(game.printStats());
}


// #7
TEST_CASE ("Make sure errors are thrown when game is finished"){
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);
    CHECK_NOTHROW(game.playAll());
    CHECK_NOTHROW(game.printWiner());
    CHECK_THROWS(game.playAll());
    CHECK_THROWS(game.printWiner());
}
