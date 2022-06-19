//
//  CCS.hpp
//  CCS
//
//  Created by Havva Fatma Özbay on 18.06.2022.
//

#ifndef CCS_hpp
#define CCS_hpp

#include <stdio.h>
#include<iostream>
using namespace std;

class CCS {
private:
    double cs1_item1;
    double cs1_item2;
    double cs1_item3;
    
    double cs2_item1;
    double cs2_item2;
    double cs2_item3;
    
    int choice;
    string conversionType;
    
    void carToSph();
    void carToCyl();
    void sphToCar();
    void cyltoCar();
    
    double getRadianFromDegree(double);
    double getDegreeFromRadian(double);
    
    string getConversionType();
    
    
    
    
public:
    CCS(double, double , double, double, double, double, int );
    void setCoordinates();
    void setCs1_item1(double);
    void setCs1_item2(double);
    void setCs1_item3(double);
    
    void setCs2_item1(double);
    void setCs2_item2(double);
    void setCs2_item3(double);
    
    void setChoice(int);
    
    double getCs1_item1();
    double getCs1_item2();
    double getCs1_item3();
    
    double getCs2_item1();
    double getCs2_item2();
    double getCs2_item3();
    
    int getChoice();
    
    void printMenu();
    
    void printCoordinates();
    
    
    
};

#endif /* CCS_hpp */
