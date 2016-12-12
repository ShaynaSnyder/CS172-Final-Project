//Cheree LaPierre and Shayna Snyder
//CS172-1 Final Project
//Text-Adventure Battleship-esque Game
//15 November 2016

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "Ships.hpp"

using namespace std;

const int hit      = 3;  // hit
const int empty    = 0;  // empty
const int missed   = 2;  // missed
const int occupied = 1;  // contains a ship
void playerBoard(int array1[5][5]); //declares void function to create the player's board
void computerBoard(int array1[5][5]); //declares void function to create the computer's board
void printPlayerBoard(int array2[5][5]); //declares void function to send the player's board to the screen
void printComputerBoard(int array2[5][5]); //declares void function to send the computer's board to the screen
void playerGuesses(int array1[5][5]);
void computerGuesses(int array1[5][5]);

int main()
{
    //to decrease variation, all ships will be modeled as having a size of 1 unit
    //declares string array to hold ship names
    Ships ships[5];
    //declares int arrays to hold ship locations
    int xlocation[5], ylocation[5], xcomputer[5], ycomputer[5], board[5][5], compBoard[5][5], repeat=0;
    char letterlocation[5];
    cout << endl << "                       Welcome to\n";
    cout << "____   ___  _____  _____         ____   ____             ___" << endl;
    cout << "|___) |___|   |      |    |     |___   (___   |___|  |  |___)" << endl;
    cout << "|___) |   |   |      |    |___  |____  ____)  |   |  |  |" << endl;
    cout << "                 ____           ____           ____" << endl;
    cout << "                |    |         |    |         |    |" << endl;
    cout << "                |    |         |    |         |    |" << endl;
    cout << "    ____________|    |_________|    |_________|    |____" << endl;
    cout << "   |              __             __             __     |" << endl;
    cout << "   |             |__|           |__|           |__|    |" << endl;
    cout << "   |                                                   |" << endl;
    cout << "≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈" << endl;
    cout << "\nThe rules of the game are simple. Sink your opponent's ships before they sink yours.\nBoth you and your opponent (the computer) have 5 ships: patrol boat, destroyer, submarine, battleship, and carrier.\nYou and your opponent will alternate guessing where the other player's ships are located.\nIf you guess one of their ships correctly, the ship is sunk. If you guess incorrectly, it will be marked as a miss.\nOnce a player has hit all of their opponent's ships, they win the game!\n";
    cout << "LET'S PLAY!\nThis is your board. It is empty right now. Place your ships on the board.\n";
    playerBoard(board); //calls void function that creates the player's board
    printPlayerBoard(board); //calls void function that outputs the player's board

    //prompts user to place their ships using for loop
    for(int i=0; i<=4; i++)
    {
        do
        {
        repeat=0;
        cout << "\nPlace your " << ships[i].getName(i) << ".\nHorizontal location (1-5): ";
        cin >> xlocation[i];
        cout << "Vertical location (a, b, c, d, or e): ";
        cin >> letterlocation[i];
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
        if(!(ylocation[i]>=0 && ylocation[i]<=4 && xlocation[i]>=1 && xlocation[i]<=5))
            repeat = 1;
        if(repeat == 1)
            cout << "This is not a valid input.\n";
    }while(repeat == 1);
        board[xlocation[i]-1][ylocation[i]]=occupied;
    }
    
    //places computer's ships using for loop and random number generators
    for(int k=0; k<=4; k++)
    {
        do
        {
            repeat=0;
            xcomputer[k] = rand()%5;
            ycomputer[k] = rand()%5;
            //tests whether or not there is already a boat placed in this location
            for(int l = 0; l < k; l++)
            {
                if(ylocation[k] == ylocation[l] && xlocation[k]==xlocation[l])
                    repeat = 1;
            }
        }while(repeat == 1);
        compBoard[xlocation[k]][ylocation[k]]=occupied;
    }
    printComputerBoard(compBoard); //calls void function printComputerBoard
    printPlayerBoard(board); //calls void function printPlayerBoard
    return 0;
}

//defines the function that creates the player's board
void playerBoard(int array1[5][5])
{
    // create a blank board
    for (int x = 0; x <= 4; x++)
    {
        for (int y = 0; y <= 4; y++)
            array1[x][y] = empty;
    }
}

//defines the function that creates the computer's board
void computerBoard(int array1[5][5])
{
    // create a blank board
    for (int x = 0; x <= 4; x++)
    {
        for (int y = 0; y <= 4; y++)
            array1[x][y] = empty;
    }
}

//defines the function that sends the player's board to the screen
void printPlayerBoard(int array2[5][5])
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
            
            if(array2[j][a] == occupied)        //shows that your ship is occupying this space
                cout << setw(4) << "X |";
            if(array2[j][a] == empty)           //leaves this space empty
                cout << setw(4) << " |" ;
            else if(array2[j][a] == missed )    //shows if computer misses your ship
                cout << setw(4) << "M |";
            else if(array2[j][a] == hit )       //shows if computer hits your ship
            {
                cout << setw(4) << "H |";
                //ships[i].hit(array2[5][5], j, a);
            }
        }
        cout << "\n" << "   _____________________" << endl;
    }
}

//defines function that sends the computer's board to the screen
void printComputerBoard(int array2[5][5])
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
            
            if((array2[j][a] == occupied) || (array2[j][a] == empty))   //space appears blank (could be empty or occupied)
                cout << setw(4) << " |" ;
            else if(array2[j][a] == missed )    //shows your missed shots
                cout << setw(4) << "M |";
            else if(array2[j][a] == hit )       //shows your hits
                cout << setw(4) << "H |";
        }
        cout << "\n" << "   _____________________" << endl;
    }
}

void playerGuesses(int array1[5][5])
{
    
}

void computerGuesses(int array1[5][5])
{
    
}
