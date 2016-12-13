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
public:
    Human(string);
    string getName(string);
    void printBoard(int array[5][5]);
    void placeShips(int array[5][5]);
};


#endif /* Human_hpp */
