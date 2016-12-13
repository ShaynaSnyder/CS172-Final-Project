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
    int humanBoard[5][5], x, y, xhuman[5], yhuman[5], sunkPlayerShips=0;
public:
    Human(string);
    string getName(string);
    void printBoard(int array[5][5]);
    void placeShips(int array[5][5]);
    void checkCompGuesses(int xGuessC[25], int yGuessC[25]);
    int getSunkPlayerShips();
    int getxGuessC();
    int getyGuessC();
};


#endif /* Human_hpp */
