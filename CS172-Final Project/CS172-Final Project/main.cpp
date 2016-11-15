//Cheree LaPierre and Shayna Snyder
//CS172-1
//Final Project
//Text-Adventure Battleship

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main()
{
    //Patrol Boat-size 2, Destroyer-size 3, Submarine-size 3, Battleship-size 4, Carrier-size 5
    string ships[5] = {"Patrol Boat", "Destroyer", "Submarine", "Battleship", "Carrier"};
    int location[5];
    cout << "Background information and rules.\n";
    for(int i=0; i<5; i++)
    {
        cout << "Place your " << ships[i] << ": ";
        cin >> location[i];
    }
    return 0;
}
