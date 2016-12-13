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

using namespace std;

int main()
{
    //declares string variable for name
    string name;
    //declares 2 two-dimensional int arrays to store computer and human boards
    int humanBoard[5][5], compBoard[5][5], sunkCompShips=0, sunkPlayerShips=0, xGuessH[25] = {5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5}, yGuessH[25] = {}, xGuessC[25]= {5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5}, yGuessC[25] = {} ;
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

        for(int g = 0; g < 25; g++)
        {

            player2.checkPlayerGuesses(xGuessH, yGuessH);          // Function call to check player guesses
            player1.checkCompGuesses(xGuessC, yGuessC);            // Function call to check computer guesses
            xGuessH[g] = player2.getxGuessH();
            yGuessH[g] = player2.getyGuessH();
            xGuessC[g] = player1.getxGuessC();
            yGuessC[g] = player1.getyGuessC();

            sunkCompShips = player2.getSunkCompShips();
            // If all of computer's ships are sunk, game is over, program ends. If not game keeps going.
            if (player2.getSunkCompShips() == 5)
            {
                cout << "Congratulations! You beat the computer!" << endl;
                return 0;
            }
            sunkPlayerShips = player1.getSunkPlayerShips();
            // If all of player's ships are sunk, game is over, program ends. If not game keeps going.
            if (player1.getSunkPlayerShips() == 5)
            {
                cout << "Oh no! You lost. The computer sunk all of your ships." << endl;
                return 0;
            }
            }
    }while (sunkCompShips < 5 && sunkPlayerShips < 5);
    return 0;
}

