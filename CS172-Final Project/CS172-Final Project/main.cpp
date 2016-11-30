//Cheree LaPierre and Shayna Snyder
//CS172-1 Final Project
//Text-Adventure Battleship-esque
//15 November 2016

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main()
{
    //      //Patrol Boat-size 2, Destroyer-size 3, Submarine-size 3, Battleship-size 4, Carrier-size 5
    //to decrease variation, all ships will be modeled as having a size of 1 unit
    //declares string array to hold ship names
    string shipNames[5] = {"Patrol Boat", "Destroyer", "Submarine", "Battleship", "Carrier"};
    //declares int arrays to hold ship locations
    int xlocation[5], ylocation[5];
    char letterlocation[5];
    cout << "Background information and rules.\n";
    //prompts user to place their ships using for loop
    for(int i=0; i<5; i++)
    {
        cout << "Place your " << shipNames[i] << ".\nHorizontal location (1-5): ";
        cin >> xlocation[i];
        cout << "Vertical location (a, b, c, d, or e): ";
        cin >> letterlocation[i];
        switch (letterlocation[i])
        {
                case 'a':
                ylocation[i]=1;
                break;
                case 'b':
                ylocation[i]=2;
                break;
                case 'c':
                ylocation[i]=3;
                break;
                case 'd':
                ylocation[i]=4;
                break;
                case 'e':
                ylocation[i]=5;
        }
        int sameplace = 0;
        //tests whether or not there is already a boat placed in this location
        for(int j=0; j<i; j++)
        {
            if((ylocation[i]==ylocation[j]) && xlocation[i]==xlocation[j])
            {
                cout << "You have already placed a ship here.\n";
                sameplace = 1;
            }
        }
        //if location is not between 1 and 5, while loop runs another iteration
        while(!(xlocation[i]>=1 && xlocation[i]<=5 && ylocation[i]>=1 && ylocation[i]<=5 && sameplace==0))
        {
            int xinput, yinput;
            cout << "That is not a valid location for your ship.\n";
            cout << "Place your " << shipNames[i] << ".\nHorizontal location (1-5): ";
            cin >> xinput;
            xlocation[i]=xinput;
            cout << "Vertical location (a, b, c, d, or e):";
            cin >> yinput;
            ylocation[i]=yinput;
            //tests whether or not there is already a boat placed in this location
            for(int j=0; j<i; j++)
            {
                if((ylocation[i]==ylocation[j]) && (xlocation[i]==xlocation[j]))
                {
                    cout << "You have already placed a ship here.";
                    sameplace = 1;
                }
                else
                    sameplace = 0;
            }
        };
    }
    return 0;
}
