//
//  Human.cpp
//  CS172-Final Project
//
//  Created by Cheree LaPierre on /1211/16.
//  Copyright © 2016 Shayna Snyder. All rights reserved.
//

#include "Human.hpp"
#include <iomanip>
#include "Player.hpp"
#include "Computer.hpp"
using namespace std;

Human::Human(string name)
{
    name = name;
}

string Human::getName(string name)
{
    name = name;
    return name;
}

void Human::printBoard(int array[5][5])
{
    cout << "\n        Your Board\n  ";
    for(int i = 1; i <= 5; i++)                     //outputs column names
    { //number coordinates
        cout << setw(4) << i;
    }
    cout << "\n" << "   _____________________" << endl;
    for(int a = 0; a <= 4; a++)
    { //letter coordinates
        cout << " " << (char) (a + 65) << " |";   //outputs row names
        for(int j = 0; j <= 4; j++)
        {
            
            if(array[j][a] == occupied)        //shows that your ship is occupying this space
                cout << setw(4) << "X |";
            if(array[j][a] == empty)           //leaves this space empty
                cout << setw(4) << " |" ;
            else if(array[j][a] == missed )    //shows if computer misses your ship
                cout << setw(4) << "M |";
            else if(array[j][a] == hit )       //shows if computer hits your ship
                cout << setw(4) << "H |";
        }
        cout << "\n" << "   _____________________" << endl;
    }}

void Human::placeShips(int array[5][5])
{
    //prompts user to place their ships using for loop
    for(int i = 0; i <= 4; i++)
    {
        do
        {
            repeat=0;
            cout << "\nPlace your " << shipNames[i] << ".\nEnter a number (1-5) and a letter (a-e): ";
            cin >> xlocation[i] >> letterlocation[i];
            switch (letterlocation[i])
            {
                case 'a':
                    ylocation[i] = 0;
                    break;
                case 'b':
                    ylocation[i] = 1;
                    break;
                case 'c':
                    ylocation[i] = 2;
                    break;
                case 'd':
                    ylocation[i] = 3;
                    break;
                case 'e':
                    ylocation[i] = 4;
            }
            //tests whether or not there is already a boat placed in this location
            for(int j = 0; j < i; j++)
            {
                if(ylocation[i] == ylocation[j] && xlocation[i]==xlocation[j])
                {
                    cout << "You have already placed a ship here.\n";
                    repeat = 1;
                }
            }
            // If location is not between 1 and 5, repeat variable is set equal to 1
            if(!(ylocation[i] >= 0 && ylocation[i] <= 4 && xlocation[i] >= 1 && xlocation[i] <= 5))
                repeat = 1;
            if(repeat == 1)
                cout << "This is not a valid input.\n";
        }while(repeat == 1);
        board[xlocation[i] - 1][ylocation[i]] = occupied;
    }
    printBoard(board);
}

void Human::makeGuess()
{
    cout << "Make your guess: ";
    int x;
    char y;
    cin >> x >> y;
    for (int i = 0; i <= 4; i++)
    {
        if (x == xcomputer[i] && y == ycomputer[i])
        {
            cout << "You hit a ship" << endl;
            // Space = 'H';
        }
        else
            cout << "You missed" << endl;
            // Space = 'M';
    }
}

