//  Human.cpp
//  CS172-Final Project
//  Cheree LaPierre and Shayna Snyder

#include "Human.hpp"
#include <iomanip>
#include "Player.hpp"
#include "Computer.hpp"
using namespace std;

Human::Human(string name)
{
    name = name;
}

string Human::getName(string name)
{
    name = name;
    return name;
}

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
                cout << setw(4) << "X |";
            if(array[j][a] == empty)           //leaves this space empty
                cout << setw(4) << " |" ;
            else if(array[j][a] == missed )    //shows if computer misses your ship
                cout << setw(4) << "M |";
            else if(array[j][a] == hit )       //shows if computer hits your ship
                cout << setw(4) << "H |";
        }
        cout << "\n" << "   _____________________" << endl;
    }
    cout << endl;
}

void Human::placeShips(int array[5][5])
{
    //prompts user to place their ships using for loop
    for(int i = 0; i <= 4; i++)
    {
        do
        {
            repeat=0;
            cout << "Place your " << shipNames[i] << ": ";
            cin >> xhuman[i] >> letterlocation[i];
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
            if(!(yhuman[i] >= 0 && yhuman[i] <= 4 && xhuman[i] >= 1 && xhuman[i] <= 5))
                repeat = 1;
            if(repeat == 1)
                cout << "This is not a valid input.\n";
        }while(repeat == 1);
        humanBoard[xhuman[i] - 1][yhuman[i]] = occupied;
    }
    printBoard(humanBoard);
}

