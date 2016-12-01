//Cheree LaPierre and Shayna Snyder
//CS172-1 Final Project
//Text-Adventure Battleship-esque Game
//15 November 2016

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

const int empty    = 0;  // empty
const int occupied = 1;  // contains a ship
const int missed   = 2;  // missed
const int hit      = 3;  // hit

int board[5][5]; // Two-dimensional array for gameboard.

void playerBoard(int array1[5][5]) // Function to initialize the gameboard for player
{
    // create a blank board
    for (int x=0; x<5; x++)
    {
        for (int y = 0; y < 5; y++)
        {
            array1[x][y] = empty;
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
            array1[x][y] = empty;
        }
    }
}

void printPlayerBoard(int array2[5][5])
{
    for(int i=1; i<=5; i++)
    { //letter coordinates
        cout << setw(4) << i;
    }
    cout << endl;
    
    for(int a=0; a<=4; a++)
    { //number coordinates
        if(a == 10)
            cout << (char) (a+65);
        else
            cout << " " << (char) (a+65) ;
        
        for(int j = 0; j <=4 ; j++)
        {
            
            if(array2[a][j] == occupied)
            {
                cout << setw(4) << "X |";
            }
            if(array2[a][j] == empty)
            {
                cout << setw(4) << " |" ;
            }
            else if(array2[a][j] == missed )
            {
                cout << setw(4) << "M |";
            }
            else if(array2[a][j] == hit )
            {
                cout << setw(4) << "H |";
            }
        }
        cout << "\n" << "______________________" << endl;
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
    
    //to decrease variation, all ships will be modeled as having a size of 1 unit
    //declares string array to hold ship names
    string shipNames[5] = {"Patrol Boat", "Destroyer", "Submarine", "Battleship", "Carrier"};
    //declares int arrays to hold ship locations
    int xlocation[5], ylocation[5], yourBoard[5][5]={}, repeat=0;
    char letterlocation[5];
    cout << "\nBackground information and rules.\n";
    //prompts user to place their ships using for loop
    
    for(int i=0; i<=4; i++)
    {
        do
        {
        repeat=0;
        cout << "Place your " << shipNames[i] << ".\nHorizontal location (1-5): ";
        cin >> xlocation[i];
        cout << "Vertical location (a, b, c, d, or e): ";
        cin >> letterlocation[i];
        switch (letterlocation[i])
        {
                case 'a':
                ylocation[i]=1;
                break;
                case 'b':
                ylocation[i]=2;
                break;
                case 'c':
                ylocation[i]=3;
                break;
                case 'd':
                ylocation[i]=4;
                break;
                case 'e':
                ylocation[i]=5;
        }
        //tests whether or not there is already a boat placed in this location
        for(int j=0; j<i; j++)
        {
            if((ylocation[i]==ylocation[j]) && xlocation[i]==xlocation[j])
            {
                cout << "You have already placed a ship here.\n";
                repeat = 1;
            }
        }
        //if location is not between 1 and 5, repeat variable is set equal to 1
        if(!(ylocation[i]>=1 && ylocation[i]<=5 && xlocation[i]>=1 && xlocation[i]<=5))
            repeat = 1;
        if(repeat == 1)
            cout << "This is not a valid input.\n";
    }while(repeat==1);
        yourBoard[xlocation[i]][ylocation[i]]=occupied;
    }
    printPlayerBoard(yourBoard);
    // Classes for different types of ships
    // cout a 2-d array(?). Use chars to show if ship has been hit (h) or missed (m)
    // Should we output 2 arrays? One for player's ships and one for player's guesses?
   
    return 0;
}
