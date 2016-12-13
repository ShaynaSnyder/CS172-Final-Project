//  Computer.cpp
//  CS172-Final Project
//  Cheree LaPierre and Shayna Snyder

#include "Computer.hpp"
#include "Player.hpp"
#include <iomanip>
using namespace std;

void Computer::printBoard(int array[5][5])
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
            
            if((array[j][a] == occupied) || (array[j][a] == empty))   //space appears blank (could be empty or occupied)
                cout << setw(4) << " |";
            else if(array[j][a] == missed )    //shows your missed shots
                cout << setw(4) << "M |";
            else if(array[j][a] == hit )       //shows your hits
                cout << setw(4) << "H |";
        }
        cout << "\n" << "   _____________________" << endl;
    }
    cout << endl;
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
                if(ycomputer[k] == ycomputer[l] && xcomputer[k] == xcomputer[l])
                    repeat = 1;
            }
        }while(repeat == 1);
        compBoard[xcomputer[k]][ycomputer[k]] = occupied;
    }
    printBoard(compBoard);

}

//defines void function to check human's guesses

void Computer::checkPlayerGuesses()
{
    char a;
<<<<<<< HEAD
    int x, y = 5, hit = 0;
=======
    int x, y, hit=0;
>>>>>>> 88f6d5d10eec6e54c515aa7b4762416831f348e5
    x=x-1;
    //prompts human guess and reads it in
    cout << "Make your guess: ";
    cin >> x >> a;
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
    if(y==5)
        cout << "Invalid guess.\n";
    //uses for loop and if statement to determine if the guess is a hit or a miss
    for(int i = 0; i <= 4; i++)
    {
        if (x == xcomputer[i] && y == ycomputer[i])
        {
            cout << "You sunk the computer's (name of ship)!\n\n";
            sunkCompShips++;
            hit++;
        }
    }
    if(hit==0)
        cout << "You missed!\n\n";
}

int Computer::getSunkCompShips()
{
    return sunkCompShips;
}
