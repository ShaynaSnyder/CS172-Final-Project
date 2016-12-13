//  Cheree LaPierre and Shayna Snyder
//  CS172-1 Final Project
//  Text-Adventure Battleship-esque Game
//  13 December 2016

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "Human.hpp"
#include "Computer.hpp"
#include "Player.hpp"

int sunkPlayerShips = 0, sunkCompShips = 0;
//bool gameOver;    //is this ever used?
//declares void functions for checking guesses
template <typename T>
void checkPlayerGuesses(T array[5][5]);
void checkCompGuesses(int array[5][5]);

using namespace std;

int main()
{
    //declares string variable for name
    string name;
    //declares 2 two-dimensional int arrays to store computer and human boards
    int humanBoard[5][5], compBoard[5][5];
    //creates Human object player1
    Human player1(name);
    //creates Computer object player2
    Computer player2;
    //function calls to Human and Computer classes to create boards using board arrays
    player1.createBoard(humanBoard);
    player2.createBoard(compBoard);
    //outputs game instructions and set-up
    cout << endl << "                          Welcome to\n";
    cout << "____   ___  _____  _____         ____   ____             ___" << endl;
    cout << "|___) |___|   |      |    |     |___   (___   |___|  |  |___)" << endl;
    cout << "|___) |   |   |      |    |___  |____  ____)  |   |  |  |\n" << endl;
    cout << "                 ____           ____           ____" << endl;
    cout << "                |    |         |    |         |    |" << endl;
    cout << "                |    |         |    |         |    |" << endl;
    cout << "    ____________|    |_________|    |_________|    |_____" << endl;
    cout << "    \\             __             __             __      /" << endl;
    cout << "     \\           (__)           (__)           (__)    /" << endl;
    cout << "      \\                                               /" << endl;
    cout << "≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈" << endl;
    cout << "\nThe rules of the game are simple--sink your opponent's ships before they sink yours.\n\nBoth you and your opponent (the computer) have 5 ships:\n   patrol boat, destroyer, submarine, battleship, and carrier.\n\nYou and your opponent will alternate guessing where the other player's ships are located.\nIf you guess one of their ships correctly, the ship is sunk. If you guess incorrectly, it will be marked as a miss.\n\nOnce a player has hit all of their opponent's ships, \bthey win the game!\b So, let's get started!\n\n   Enter your name: ";
    //getline reads in player's name
    getline(cin, name);
    cout << "\nLET'S PLAY " << player1.getName(name) << "!\n   This is your board. It is empty right now. Place your ships on the board.\n   To place ships on the board or make a guess, enter coordinates using a number (1-5) and a letter (a-e)\n   Examples: 1d, 3a, 5b, etc.\n";
    //function calls to Human class to print player1's board to the screen
    player1.printBoard(humanBoard);
    //function calls to Human class to place player1's ships on the board
    player1.placeShips(humanBoard);
    //function calls to Compuer class to place player2's ships on the board
    player2.placeShips(compBoard);
    
    // Each player takes turns guessing
    do
    {
        checkPlayerGuesses(compBoard);                              // Function call to check player guesses
        checkCompGuesses(humanBoard);                               // Function call to check computer guesses
        
    }while (sunkCompShips != 5 || sunkPlayerShips != 5);
    return 0;
}

//defines void function to check human's guesses
template <typename T>
void checkPlayerGuesses(T array[5][5])
{
    int x, y, xcomputer[5], ycomputer[5];
    //prompts human guess and reads it in
    cout << "Make your guess: ";
    cin >> x >> y;
    //uses for loop and if statement to determine if the guess is a hit or a miss
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

//defines void function to check computer's guessses
void checkCompGuesses(int array[5][5])
{
    int x, y, xhuman[5], yhuman[5];
    cout << "It is the computer's turn to guess." << endl;
    //uses random number generators to randomly generate a guess for the computer
    x = rand() % 5;
    y = rand() % 5;
    //uses for loop and if statement to determine if the guess is a hit or a miss
    for(int i = 0; i <= 4; i++)
    {
        if (x == xhuman[i] && y == yhuman[i])
        {
            cout << "The computer sunk your (name of ship)!\n\n";
            sunkPlayerShips++;
            // Space = 'H';
        }
    }
    cout << "You missed" << endl;
}

