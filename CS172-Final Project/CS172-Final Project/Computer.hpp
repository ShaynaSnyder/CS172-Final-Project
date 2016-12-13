//  Computer.hpp
//  CS172-Final Project
//  Cheree LaPierre and Shayna Snyder

#ifndef Computer_hpp
#define Computer_hpp

#include <stdio.h>
#include "Player.hpp"

using namespace std;
class Computer: public Player
{
private:
    int  compBoard[5][5], x, y, xcomputer[5], ycomputer[5], sunkCompShips = 0;
public:
    void printBoard(int array[5][5]);                           // Prints board
    void placeShips(int array[5][5]);                           // Places ships
    void checkPlayerGuesses(int xGuess[25], int yGuess[25]);    // Declares void functions for checking guesses
    int getSunkCompShips();                                     // Returns number of computer ships sunk
    int getxGuess();
    int getyGuess();
};

#endif /* Computer_hpp */
