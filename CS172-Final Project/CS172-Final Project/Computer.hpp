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
    int  xcomputer[5], ycomputer[5];
public:
    void printBoard(int array[5][5]);
    void placeShips(int array[5][5]);
    void makeGuessH(int array[5][5]);
};

#endif /* Computer_hpp */
