//Cheree LaPierre and Shayna Snyder
//CS172-1 Final Project
//Text-Adventure Battleship-esque Game
//15 November 2016

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

const int empty    = 0;  // contains water
const int occupied = 1;  // contains a ship
const int missed   = 2;  // shot into ocean
const int hit      = 3;  // shot and hit

int board[5][5]; // Two-dimensional array for gameboard.

void playerBoard(int array1[5][5]) // Function to initialize the gameboard for player
{
    // create a blank board
    for (int x=0; x<5; x++)
    {
        for (int y = 0; y < 5; y++)
        {
            array1[x][y] = occupied;
        }
    }
}

void computerBoard( int array1[5][5] ) // Function to initialize the gameboard for player
{
    // create a blank board
    for (int x=0; x<5; x++)
    {
        for (int y = 0; y < 5; y++)
        {
            array1[x][y] = occupied;
        }
    }
}

void printPlayerBoard(int array2[5][5])
{
    for(char a = 'A'; a <= 'E'; a++)
    { //letter coordinates
        cout << setw(4) << a;
    }
    cout << endl;
    
    for(int i = 1; i <= 5; i++)
    { //number coordinates
        if(i == 10)
            cout << i;
        else
            cout << " " << i ;
        
        for(int j = 0; j < 5 ; j++)
        {
            
            if(array2[i][j] == occupied || array2[i][j] == empty)
            {
                cout << setw(4) << " |" ;
            }
            else if(array2[i][j] == missed )
            {
                cout << setw(4) << "M|";
            }
            else if(array2[i][j] == hit )
            {
                cout << setw(4) << "X|";
            }
        }
        cout << "\n";
    }
}

void printComputerBoard(int array2[5][5])
{
    for(char a = 'A'; a <= 'E'; a++)
    { //letter coordinates
        cout << setw(4) << a;
    }
    cout << endl;
    
    for(int i = 1; i <= 5; i++)
    { //number coordinates
        if(i == 10)
            cout << i;
        else
            cout << " " << i ;
        
        for(int j = 0; j < 5 ; j++)
        {
            
            if(array2[i][j] == occupied || array2[i][j] == empty)
            {
                cout << setw(4) << " |" ;
            }
            else if(array2[i][j] == missed )
            {
                cout << setw(4) << "M|";
            }
            else if(array2[i][j] == hit )
            {
                cout << setw(4) << "X|";
            }
        }
        cout << "\n";
    }
}

int main()
{
    playerBoard(board);
    printPlayerBoard(board);
    
    
    //Patrol Boat-size 2, Destroyer-size 3, Submarine-size 3, Battleship-size 4, Carrier-size 5
    //declares string array to hold ship names
    string shipNames[5] = {"Patrol Boat", "Destroyer", "Submarine", "Battleship", "Carrier"};
//    //declares int arrays to hold ship sizes and locations
//    int location[5];
    cout << "Background information and rules.\n";
    //prompts user to place their ships using for loop
    for(int i=0; i<5; i++)
    {
            cout << "Place your " << shipNames[i] << ": ";
            cin >> location[i];
        //if location is not in array, while loop runs another iteration
        while(!(location[i] >= 1 && location[i] <= 5))
        {
            cout << "That is not a valid location for your ship.\n";
            cout << "Place your " << shipNames[i] << ": ";
            cin >> location[i];
            //tests whether or not there is already a boat placed in this location
            for(int j=0; j<i; j++)
            {
                if(location[i]==location[j])
                    location[i]=0;
            }
        }
    }
    
    
    
    // Classes for different types of ships
    // cout a 2-d array(?). Use chars to show if ship has been hit (h) or missed (m)
    // Should we output 2 arrays? One for player's ships and one for player's guesses?
    return 0;
}
