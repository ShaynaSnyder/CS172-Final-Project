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

//bool gameOver;    //is this ever used?

using namespace std;

int main()
{
    //declares string variable for name
    string name;
    //declares 2 two-dimensional int arrays to store computer and human boards
    int humanBoard[5][5], compBoard[5][5], sunkCompShips, sunkPlayerShips;
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
    cout << "\n   LET'S PLAY " << player1.getName(name) << "!\nThis is your board. It is empty right now. Place your ships on the board.\nTo place ships on the board or make a guess, enter coordinates using a number (1-5) and a letter (a-e)\nExamples: 1d, 3a, 5b, etc.\n";
    //function calls to Human class to print player1's board to the screen
    player1.printBoard(humanBoard);
    //function calls to Human class to place player1's ships on the board (and print board)
    player1.placeShips(humanBoard);
    cout << "This is your opponents board. They have placed their ships in 5 of these squares.\nGuess where their ships are located by entering a coordinate.\n\n";
    //function calls to Computer class to place player2's ships on the board (and print board)
    player2.placeShips(compBoard);
    
    // Each player takes turns guessing
    do
    {
        player2.checkPlayerGuesses();          // Function call to check player guesses
        sunkCompShips = player2.getSunkCompShips();
        if (player2.getSunkCompShips() == 5)
        {
            cout << "You won!!!!!!" << endl;
        }
        //checkCompGuesses(humanBoard);                               // Function call to check computer guesses
        

        
    }while (sunkCompShips <= 5 && sunkPlayerShips != 5);
    return 0;
}

