//  Human.hpp
//  CS172-Final Project
//  Cheree LaPierre and Shayna Snyder


#ifndef Human_hpp
#define Human_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include "Player.hpp"
using namespace std;
class Human: public Player
{
private:
    int xhuman[5], yhuman[5], sunkPlayerShips=0;
public:
    Human(string);
    string getName(string);
    void printBoard(int array[5][5]);               // Prints board
    void placeShips(int array[5][5]);               // Places ships
    void checkCompGuesses();                        // Checks computer guesses on player board
    int getSunkPlayerShips();                       // Returns number of player ships sunk
};


#endif /* Human_hpp */
