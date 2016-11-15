//Cheree LaPierre and Shayna Snyder
//CS172-1 Final Project
//Text-Adventure Battleship
//15 November 2016

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main()
{
    //Patrol Boat-size 2, Destroyer-size 3, Submarine-size 3, Battleship-size 4, Carrier-size 5
    //declares string array to hold ship names
    string shipNames[5] = {"Patrol Boat", "Destroyer", "Submarine", "Battleship", "Carrier"};
    //declares int arrays to hold ship sizes and locations
    int shipSize[5] = {2, 3, 3, 4, 5};
    int location[5];
    cout << "Background information and rules.\n";
    //prompts user to place their ships using for loop
    for(int i=0; i<5; i++)
    {
        do
        {
            cout << "Place your " << shipNames[i] << ": ";
            cin >> location[i];
            cout << "That is not a valud location for your ship.\n";
        } while(!(location[i]>=1 && location[i]<=50));
    }
    return 0;
}
