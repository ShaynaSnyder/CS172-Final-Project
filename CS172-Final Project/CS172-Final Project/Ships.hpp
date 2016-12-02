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
public:
    Ships();
    void hit();
    void miss();
    void sunkenShips(string name);
    
    // We should have getHit and getMiss I think
    // Or maybe make them bools?
    
    // Yeah I don't know what these do...
    
    
private:
    int size;
    string name;
    
};

// Template to check guesses

#endif /* Ships_hpp */
