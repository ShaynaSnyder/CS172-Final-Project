//  Computer.cpp
//  CS172-Final Project
//  Cheree LaPierre and Shayna Snyder

#include "Computer.hpp"
#include "Player.hpp"
#include <iomanip>
using namespace std;

//defines void function to print the computer's game board
void Computer::printBoard(int array[5][5])
{
    //uses for loops to set up rows and columns of game board
    cout << "     Opponent's Board\n  ";
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
            
            if((array[j][a] == occupied) || (array[j][a] == empty))   //space appears blank (could be empty or occupied)
                cout << setw(4) << " |";
            else if(array[j][a] == missed )    //shows your missed shots
                cout << setw(4) << "M |";
            else if(array[j][a] == hit )       //shows your hits
                cout << setw(4) << "X |";
        }
        cout << "\n" << "   _____________________" << endl;
    }
    cout << endl;
}
//defines void function to place the computer's ships
void Computer::placeShips(int array1[5][5])
{
    //places computer's ships using for loop and random number generators
    for(int k = 0; k <= 4; k++)
    {
        do
        {
            //sets repeat equal to 0 at the beginning of each do-while loop iteration
            repeat=0;
            //uses random number generators to generate coordinates for computer ship locations
            xcomputer[k] = rand() % 5;
            ycomputer[k] = rand() % 5;
            //tests whether or not there is already a boat placed in this location
            for(int l = 0; l < k; l++)
            {
                //if ship location is equal to previous ship location, repeat is set equal to 1
                if(ycomputer[k] == ycomputer[l] && xcomputer[k] == xcomputer[l])
                    repeat = 1;
            }
        }while(repeat == 1); //do-while loop iterates again while repeat is equal to 1
        //randomly generated ship location is set equal to occupied in compBoard array
        compBoard[xcomputer[k]][ycomputer[k]] = occupied;
    }
    //calls function to print the computer board to the screen
    printBoard(compBoard);

}
//defines void function to check human's guesses
void Computer::checkPlayerGuesses(int xGuessH[25], int yGuessH[25])
{
    char a;
    int hits = 0, repeat;
    do
    {
        repeat = 0;
        //prompts human guess and reads it in
        cout << "Make your guess: ";
        cin >> x >> a;
        x = x-1;
        switch (a)
        {
            case 'a':
                y = 0;
                break;
            case 'b':
                y = 1;
                break;
            case 'c':
                y = 2;
                break;
            case 'd':
                y = 3;
                break;
            case 'e':
                y = 4;
                break;
            default:
                y = 5;
                break;
        }
        if(y == 5)
        {
            cout << "Invalid guess.\n\n";
                repeat++;
        }
        //tests whether or not the user has already guessed this location
        for(int j = 0; j < 25; j++)
        {
            if(y == yGuessH[j] && x == xGuessH[j])
            {
                cout << "You have already guessed this location.\n\n";
                repeat++;
            }
        }
    }while(repeat != 0);
    //uses for loop and if statement to determine if the guess is a hit or a miss
    for(int i = 0; i <= 4; i++)
    {
        if (x == xcomputer[i] && y == ycomputer[i])
        {
            cout << "You sunk the computer's " << shipNames[i] << "!\n\n";
            compBoard[x][y] = hit;
            sunkCompShips++;
            hits++;
        }
    }
    if(hits == 0)
    {
        cout << "You missed!\n\n";
        compBoard[x][y] = missed;
    }
    printBoard(compBoard);
}
//defines int function to get value of sunkCompShips
int Computer::getSunkCompShips()
{
    return sunkCompShips;
}
//defines int function to get value of x
int Computer::getxGuessH()
{
    return x;
}
//defines int function to get value of y
int Computer::getyGuessH()
{
    return y;
}
