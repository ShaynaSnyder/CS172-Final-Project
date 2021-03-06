//  Player.hpp
//  CS172-Final Project
//  Cheree LaPierre and Shayna Snyder

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

//creates Player class
class Player
{
public:
    //declares void function to create game board
    void createBoard(int array[5][5]);
    const int empty    = 0;  // empty
    const int occupied = 1;  // contains a ship
    const int missed   = 2;  // missed
    const int hit      = 3;  // hit
    //declares public int variables for use in functions
    int columns, rows, repeat;

    //declares public char array for user input of letter location
    char letterlocation[5];
    //declares string array of ship names to store the names of each ship

    string shipNames[5] = {"Patrol Boat", "Destroyer", "Submarine", "Battleship", "Carrier"};
};
#endif /* Player_hpp */
