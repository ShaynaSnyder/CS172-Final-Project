//  Computer.hpp
//  CS172-Final Project
//  Cheree LaPierre and Shayna Snyder

#ifndef Computer_hpp
#define Computer_hpp

#include <stdio.h>
#include "Player.hpp"

using namespace std;

//creates Computer class that is in the Player class
class Computer: public Player
{
private:
    //declares private int variables and arrays
    int  compBoard[5][5], x, y, xcomputer[5], ycomputer[5], sunkCompShips = 0;
public:
    //declares void functions to print computer board and place computer's ships
    void printBoard(int array[5][5]);
    void placeShips(int array[5][5]);
    //declares void function to make guesses for the computer
    void makeGuessH(int array[5][5]);
    //declares void function to check human's guesses against computer's ship locations
    void checkPlayerGuesses(int xGuessH[25], int yGuessH[25]);
    //declares int functions to get int values of sunkCompShips, x, and y
    int getSunkCompShips();
    int getxGuessH();
    int getyGuessH();
};
#endif /* Computer_hpp */
