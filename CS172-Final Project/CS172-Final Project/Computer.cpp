//
//  Computer.cpp
//  CS172-Final Project
//
//  Created by Cheree LaPierre on /1211/16.
//  Copyright © 2016 Shayna Snyder. All rights reserved.
//

#include "Computer.hpp"
#include "Player.hpp"
#include <iomanip>
using namespace std;

<<<<<<< HEAD
Computer::Computer()
{
    
}

void Computer::printBoard(int array1[5][5])
=======
void Computer::printBoard(int array[5][5])
>>>>>>> 184513b4e29725ba44a57e2d314161050fac3465
{
    cout << "   Your Opponent's Board\n  ";
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
            
<<<<<<< HEAD
            //if((array[j][a] == occupied) || (array[j][a] == empty))   //space appears blank (could be empty or occupied)
            if(array1[j][a] ==empty)
                cout << setw(4) << " |" ;
            else if(array1[j][a] ==occupied)
                cout << setw(4) << "  X";
            else if(array1[j][a] == missed )    //shows your missed shots
=======
            if((array[j][a] == occupied) || (array[j][a] == empty))   //space appears blank (could be empty or occupied)
            else if(array[j][a] == missed )    //shows your missed shots
>>>>>>> 184513b4e29725ba44a57e2d314161050fac3465
                cout << setw(4) << "M |";
            else if(array1[j][a] == hit )       //shows your hits
                cout << setw(4) << "H |";
        }
        cout << "\n" << "   _____________________" << endl;
    }
}

void Computer::placeShips(int array1[5][5])
{
    //places computer's ships using for loop and random number generators
    for(int k = 0; k <= 4; k++)
    {
        do
        {
            repeat=0;
            xcomputer[k] = rand() % 5;
            ycomputer[k] = rand() % 5;
            //tests whether or not there is already a boat placed in this location
            for(int l = 0; l < k; l++)
            {
<<<<<<< HEAD
                if(ycomputer[k] == ycomputer[l] && xcomputer[k] == xcomputer[l])
                    repeat = 1;
            }
        }while(repeat == 1);
        compBoard[xcomputer[k]][ycomputer[k]] = occupied;
    }
    printBoard(compBoard);
=======
                if(ycomputer[k] == ycomputer[l] && xcomputer[k]==xcomputer[l])
                    repeat = 1;
            }
        }while(repeat == 1);
        compBoard[xcomputer[k]][ycomputer[k]]=occupied;
    }
    
    printBoard(compBoard);
    
>>>>>>> 184513b4e29725ba44a57e2d314161050fac3465
}

//void makeGuess()
//{
//    
//}
