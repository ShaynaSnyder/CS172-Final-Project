//Cheree LaPierre and Shayna Snyder
//CS172-1 Final Project
//Text-Adventure Battleship-esque Game
//15 November 2016

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "Human.hpp"
#include "Computer.hpp"
#include "Player.hpp"


int x, y, xlocation[5], ylocation[5], xcomputer[5], ycomputer[5], sunkPlayerShips = 0, sunkCompShips = 0;
bool gameOver;
template<typename T>
void checkPlayerGuesses(T array[5][5])
{
    cout << "Make your guess: ";
    cin >> x >> y;
    for(int i = 0; i <=4; i++)
    {
        if (x == xcomputer[i] && y == ycomputer[i])
        {
            cout << "You sunk the computer's (name of ship)!\n\n";
            sunkCompShips++;
        }
    }
    cout << "You missed" << endl;
}
void checkCompGuesses(int array[5][5]);


using namespace std;

int main()
{
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
    cout << "\nThe rules of the game are simple. Sink your opponent's ships before they sink yours.\nBoth you and your opponent (the computer) have 5 ships: patrol boat, destroyer, submarine, battleship, and carrier.\nYou and your opponent will alternate guessing where the other player's ships are located.\nIf you guess one of their ships correctly, the ship is sunk. If you guess incorrectly, it will be marked as a miss.\nOnce a player has hit all of their opponent's ships, they win the game! So, let's get started!\n";
    
    int board[5][5];
    int compBoard[5][5];
    string name;
    cout << "Enter your name: ";
    getline(cin, name);
    Human player1(name);
    cout << "\nLET'S PLAY " << player1.getName(name);
    cout << "!\nThis is your board. It is empty right now. Place your ships on the board.\nTo place ships on the board or make a guess, enter coordinates like 1d, 3a, 5b, etc.\n";

    player1.createBoard(board);
    player1.printBoard(board);
    player1.placeShips(board);
    
    Computer player2;
    player2.createBoard(compBoard);
    player2.placeShips(compBoard);
    
    // Each player takes turns guessing
    do
    {
        checkPlayerGuesses(compBoard);                              // Function call to check player guesses
        checkCompGuesses(board);                                    // Function call to check computer guesses
        
    }while (sunkCompShips != 5 || sunkPlayerShips != 5);

    
    return 0;
}


void checkCompGuesses(int array[5][5])
{
    cout << "It is the computer's turn to guess." << endl;
    x = rand() % 5;
    y = rand() % 5;
    for(int i = 0; i <= 4; i++)
    {
        if (x == xlocation[i] && y == ylocation[i])
        {
            cout << "The computer sunk your (name of ship)!\n\n";
            sunkPlayerShips++;
            // Space = 'H';
        }
    }
    cout << "You missed" << endl;
}

