//
//  Ships.hpp
//  CS172-Final Project
//
//  Created by Cheree LaPierre on /1115/16.
//  Copyright © 2016 Shayna Snyder. All rights reserved.
//

#ifndef Ships_hpp
#define Ships_hpp

#include <stdio.h>
#include <string>
using namespace std;
class Ships
{
private:
    int shipN, size, x, y;
    string name;
    int refBoard[5][5];

public:
    Ships();
    Ships(int shipN);
    string getName(int shipN);
    void hit(int refBoard[5][5], int x, int y);
    void miss();
    void sunkenShips(string name);
};

// Template to check guesses

#endif /* Ships_hpp */
