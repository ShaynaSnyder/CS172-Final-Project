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

void playerBoard(int array1[5][5]) //function initializes gameboard for player
{
    // create a blank board
    for (int x = 0; x <= 4; x++)
    {
        for (int y = 0; y <= 4; y++)
        {
            array1[x][y] = empty;
        }
    }
}
void computerBoard(int array1[5][5]) //function initializes gameboard for computer
{
    // create a blank board
    for (int x=1; x<=5; x++)
    {
        for (int y = 1; y <= 5; y++)
        {
            array1[x][y] = empty;
        }
    }
}

void printPlayerBoard(int array2[5][5])         //function outputs the player's board
{
    cout << "  ";
    for(int i=1; i<=5; i++)                     //outputs column names
    { //number coordinates
        cout << setw(4) << i;
    }
    cout << "\n" << "   _____________________" << endl;    for(int a=1; a<=5; a++)
    { //letter coordinates
        cout << " " << (char) (a+64) << " |";   //outputs row names
        for(int j = 1; j <=5; j++)
        {
            
            if(array2[j][a] == occupied)        //shows that your ship is occupying this space
            {
                cout << setw(4) << "X |";
            }
            if(array2[j][a] == empty)           //leaves this space empty
            {
                cout << setw(4) << " |" ;
            }
            else if(array2[j][a] == missed )    //shows if computer misses your ship
            {
                cout << setw(4) << "M |";
            }
            else if(array2[j][a] == hit )       //shows if computer hits your ship
            {
                cout << setw(4) << "H |";
            }
        }
        cout << "\n" << "   _____________________" << endl;
    }
}

void printComputerBoard(int array2[5][5])
{
    cout << "  ";
    for(int i=1; i<=5; i++)                     //outputs column names
    { //number coordinates
        cout << setw(4) << i;
    }
    cout << "\n" << "   _____________________" << endl;    for(int a=1; a<=5; a++)
    { //letter coordinates
        cout << " " << (char) (a+64) << " |";   //outputs row names
        for(int j = 1; j <=5; j++)
        {
            
            if((array2[j][a] == occupied) || (array2[j][a] == empty))   //space appears blank (could be empty or occupied)
            {
                cout << setw(4) << " |" ;
            }
            else if(array2[j][a] == missed )    //shows your missed shots
            {
                cout << setw(4) << "M |";
            }
            else if(array2[j][a] == hit )       //shows your hits
            {
                cout << setw(4) << "H |";
            }
        }
        cout << "\n" << "   _____________________" << endl;
    }
}

int main()
{
    //to decrease variation, all ships will be modeled as having a size of 1 unit
    //declares string array to hold ship names
    string shipNames[5] = {"Patrol Boat", "Destroyer", "Submarine", "Battleship", "Carrier"};
    //declares int arrays to hold ship locations
    int xlocation[5], ylocation[5], board[5][5], repeat=0;
    char letterlocation[5];
    cout << "\nBackground information and rules.\n";
    playerBoard(board);
    printPlayerBoard(board);
    //prompts user to place their ships using for loop
    
    for(int i=1; i<=5; i++)
    {
        do
        {
        repeat=0;
        cout << "\nPlace your " << shipNames[i-1] << ".\nHorizontal location (1-5): ";
        cin >> xlocation[i];
        cout << "Vertical location (a, b, c, d, or e): ";
        cin >> letterlocation[i];
        switch (letterlocation[i])
        {
                case 'a':
                ylocation[i] = 1;
                break;
                case 'b':
                ylocation[i] = 2;
                break;
                case 'c':
                ylocation[i] = 3;
                break;
                case 'd':
                ylocation[i] = 4;
                break;
                case 'e':
                ylocation[i] = 5;
        }
        //tests whether or not there is already a boat placed in this location
        for(int j=1; j<i; j++)
        {
            if(ylocation[i]==ylocation[j] && xlocation[i]==xlocation[j])
            {
                cout << "You have already placed a ship here.\n";
                repeat = 1;
            }
        }
        // If location is not between 1 and 5, repeat variable is set equal to 1
        if(!(ylocation[i]>=1 && ylocation[i]<=5 && xlocation[i]>=1 && xlocation[i]<=5))
            repeat = 1;
        if(repeat == 1)
            cout << "This is not a valid input.\n";
    }while(repeat==1);
        board[xlocation[i]][ylocation[i]]=occupied;
    }
    printPlayerBoard(board);
    // Classes for different types of ships
    // cout a 2-d array(?). Use chars to show if ship has been hit (h) or missed (m)
    // Should we output 2 arrays? One for player's ships and one for player's guesses?
   
    return 0;
}
