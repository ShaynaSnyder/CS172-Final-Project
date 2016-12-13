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

//creates Human class that is in the Player class
class Human: public Player
{
private:
    //declares private int variables and arrays
    int humanBoard[5][5], x, y, xhuman[5], yhuman[5], sunkPlayerShips=0;
public:
    //creates Human object using string variable
    Human(string);
    //declares string function that gets user's name
    string getName(string);
    //declares void functions to print user's board and place user's ships
    void printBoard(int array[5][5]);
    void placeShips(int array[5][5]);
    //declares void function to check the computer's guesses against the player's ship locations
    void checkCompGuesses(int xGuessC[25], int yGuessC[25]);
    //declares int functions to get int values of sunkPlayerShips, x, and y
    int getSunkPlayerShips();
    int getxGuessC();
    int getyGuessC();
};
#endif /* Human_hpp */
