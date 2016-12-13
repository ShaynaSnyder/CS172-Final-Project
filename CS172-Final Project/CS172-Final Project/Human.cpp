//  Human.cpp
//  CS172-Final Project
//  Cheree LaPierre and Shayna Snyder

#include "Human.hpp"
#include <iomanip>
#include "Player.hpp"
#include "Computer.hpp"

using namespace std;

//defines Human object that sets name equal to name
Human::Human(string name)
{
    name = name;
}
//defines string function to get name of Human
string Human::getName(string name)
{
    name = name;
    return name;
}
//defines void function to print Human board
void Human::printBoard(int array[5][5])
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
            
            if(array[j][a] == occupied)        //shows that your ship is occupying this space
                cout << setw(4) << "O |";
            if(array[j][a] == empty)           //leaves this space empty
                cout << setw(4) << " |" ;
            else if(array[j][a] == missed )    //shows if computer misses your ship
                cout << setw(4) << "M |";
            else if(array[j][a] == hit )       //shows if computer hits your ship
                cout << setw(4) << "X |";
        }
        cout << "\n" << "   _____________________" << endl;
    }
    cout << endl;
}
//defines void funtion that places the human's ships on the board
void Human::placeShips(int array[5][5])
{
    //prompts user to place their ships using for loop
    for(int i = 0; i <= 4; i++)
    {
        do
        {
            //declares temp int variable to hold a temporary value from user input
            int temp;
            //sets repeat equal to 0 at the beginning ot each do-while loop iteration
            repeat=0;
            cout << "Place your " << shipNames[i] << ": ";
            cin >> temp >> letterlocation[i];
            xhuman[i] = temp - 1;
            //uses switch statements to set user-inputted char value equal to integer value
            switch (letterlocation[i])
            {
                case 'a':
                    yhuman[i] = 0;
                    break;
                case 'b':
                    yhuman[i] = 1;
                    break;
                case 'c':
                    yhuman[i] = 2;
                    break;
                case 'd':
                    yhuman[i] = 3;
                    break;
                case 'e':
                    yhuman[i] = 4;
            }
            //tests whether or not there is already a boat placed in this location
            for(int j = 0; j < i; j++)
            {
                if(yhuman[i] == yhuman[j] && xhuman[i] == xhuman[j])
                {
                    cout << "You have already placed a ship here.\n";
                    repeat = 1;
                }
            }
            // If location is not between 1 and 5, repeat variable is set equal to 1
            if(!(yhuman[i] >= 0 && yhuman[i] <= 4 && xhuman[i] >= 0 && xhuman[i] <= 4))
                repeat = 1;
            if(repeat == 1)
                cout << "This is not a valid input.\n";
        }while(repeat == 1); //do-while loop runs another iteration if repeat is equal to 1
        //user-inputted location is set equal to occupied in humanBoard array
        humanBoard[xhuman[i]][yhuman[i]] = occupied;
    }

    cout << "\nThese are you ships.\n";
    //calls to printBoard function to print the user's board to the screen
    printBoard(humanBoard);

}

//defines void function to check computer's guesses
void Human::checkCompGuesses(int xGuessC[25], int yGuessC[25])
{
    //initializes int hits to 0
    int hits=0, repeat;
    cout << "It's the computer's turn to guess.\n";
    do
    {
        //repeat is set equal to 0 at the beginning of each do-while loop iteration
        repeat = 0;
        //uses random number generators to randomly generate a guess for the computer
        x = rand() % 5;
        y = rand() % 5;
        //tests whether or not the computer has already guessed this location
        for(int a = 0; a < 25; a++)
        {
            if(y == yGuessC[a] && x == xGuessC[a])
                repeat++;
        }
    }while(repeat!=0); //while loop iterates again if repeat is not equal to 0

    //uses for loop and if statement to determine if the guess is a hit or a miss
    for(int i = 0; i <= 4; i++)
    {
        //if computer guess is equal to a human ship location
        if (x == xhuman[i] && y == yhuman[i])
        {
            cout << "The computer sunk your " << shipNames[i] << "!\n\n";
            //guess location is set equal to hit
            humanBoard[x][y] = hit;
            //sunkPlayerShips and hits are incremented by 1
            sunkPlayerShips++;
            hits++;
        }
    }
    //if the guess matches none of the ship locations
    if(hits == 0)
    {
        cout << "The computer missed!\n\n";
        //guess location is set equal to missed
        humanBoard[x][y] = missed;
    }
    printBoard(humanBoard);          //calls function to print human board
}

//defines int function to get value of sunkPlayerShips

int Human::getSunkPlayerShips()
{
    return sunkPlayerShips;
}
//defines int function to get value of x
int Human::getxGuessC()
{
    return x;
}
//defines int function to get value of y
int Human::getyGuessC()
{
    return y;
}
