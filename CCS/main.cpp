//
//  main.cpp
//  CCS
//
//  Created by Havva Fatma Özbay on 18.06.2022.
//

#include <iostream>
#include "CCS.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    CCS myCCS(0.0,0.0,0.0,0.0,0.0,0.0,0);
    myCCS.printMenu();
    myCCS.setCoordinates();
    myCCS.printCoordinates();
    return 0;
}
