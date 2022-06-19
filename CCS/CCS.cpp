//
//  CCS.cpp
//  CCS
//
//  Created by Havva Fatma Özbay on 18.06.2022.
//

#include "CCS.hpp"
#include <cmath>
using namespace std;

CCS::CCS(double cs11, double cs12, double cs13, double cs21, double cs22, double cs23, int c){
    setCs1_item1(cs11);
    setCs1_item2(cs12);
    setCs1_item3(cs13);
    
    setCs2_item1(cs21);
    setCs2_item2(cs22);
    setCs2_item3(cs23);
    
    setChoice(c);
}


void CCS::setCs1_item1(double cs11){
    cs1_item1 = cs11;
}
void CCS::setCs1_item2(double cs12){
    cs1_item2 = cs12;
}
void CCS::setCs1_item3(double cs13){
    cs1_item3 = cs13;
}
void CCS::setCs2_item1(double cs21){
    cs2_item1 = cs21;
}
void CCS::setCs2_item2(double cs22){
    cs2_item2 = cs22;
}
void CCS::setCs2_item3(double cs23){
    cs2_item3 = cs23;
}

void CCS::setChoice(int choice){
    choice = choice;
}

double CCS::getCs1_item1(){
    return cs1_item1;
}

double CCS::getCs1_item2(){
    return cs1_item2;
}
double CCS::getCs1_item3(){
    return cs1_item3;
}

double CCS::getCs2_item1(){
    return cs2_item2;
}

double CCS::getCs2_item2(){
    return cs2_item2;
}

double CCS::getCs2_item3(){
    return cs2_item3;
}

int CCS::getChoice(){
    return choice;
}

void CCS::printMenu(){
    
    do{
        
    
    cout <<"*******************************"<<endl;
    cout<<"1. Cartesian to Spherical"<<endl;
    cout<<"2. Cartesian to Cylindrical"<<endl;
    cout<<"3. Spherical to Cartesian"<<endl;
    cout<<"4.Cylindricsl to Cartesian"<<endl;
    cout<<"5. Exit"<<endl;
    cout <<"*******************************"<<endl;
    
    cout <<"Enter your choice"<<endl;
    cin >> choice;
    
        if(choice>5 || choice <0){
            cout<<"Wrong Choice Enter Again"<<endl;
        }
    
    }while(choice<0 || choice>6);

}

void CCS::setCoordinates(){
    double a,b,c;
    switch(choice){
        case 1:
            cout<<"Enter x,y,z coordinates"<<endl;
            cin >>a >>b>>c;
            break;
        case 2:
            cout<<"Enter x,y,z coordinates"<<endl;
            cin >>a >>b>>c;
            break;
        case 3:
            cout<<"Enter r,theta,phi coordinates"<<endl;
            cin >>a >>b>>c;
            break;
        case 4:
            cout<<"Enter rho,phi,z coordinates"<<endl;
            cin >>a >>b>>c;
            break;
        case 5:
            cout <<"Bye Bye!"<<endl;
            
            
    }
    setCs1_item1(a);
    setCs2_item2(b);
    setCs1_item3(c);
            
}

void CCS::printCoordinates(){
    switch(choice){
        case 1:
            carToSph();
            conversionType = "Cartesian to Spherical";
            cout <<"P"<<getCs1_item1()<<","<<getCs1_item2()<<","<<getCs1_item3()<<")"
            <<"------"<<getConversionType()<<"---->"<<
            "PCON("<<getCs2_item1()<<","<<getCs2_item2()<<","<<getDegreeFromRadian( getCs2_item3())<<")"<<endl;
            break;
        case 2:
            carToCyl();
            conversionType = "Cartesian to Cylindrical";
            cout <<"P"<<getCs1_item1()<<","<<getCs1_item2()<<","<<getCs1_item3()<<")"
            <<"------"<<getConversionType()<<"---->"<<
            "PCON("<<getCs2_item1()<<","<<getDegreeFromRadian( getCs2_item2())<<","<<getCs2_item3()<<")"<<endl;
            break;
            
        case 3:
            sphToCar();
            conversionType = "Spherical to Cartesian";
            cout <<"P"<<getCs1_item1()<<","<<getCs1_item2()<<","<<getCs1_item3()<<")"
            <<"------"<<getConversionType()<<"---->"<<
            "PCON("<<getCs2_item1()<<","<< getCs2_item2()<<","<<getCs2_item3()<<")"<<endl;
            break;
        case 4:
            cyltoCar();
            conversionType = "Cylindrical to Cartesian";
            cout <<"P"<<getCs1_item1()<<","<<getCs1_item2()<<","<<getCs1_item3()<<")"
            <<"------"<<getConversionType()<<"---->"<<
            "PCON("<<getCs2_item1()<<","<< getCs2_item2()<<","<<getCs2_item3()<<")"<<endl;
            break;
            
    }
}

void CCS::carToSph(){
    cs2_item1=sqrt((pow(cs1_item1,2)+pow(cs1_item2,2)+pow(cs1_item3,2)));
    cs2_item2=atan2(sqrt(pow(cs1_item1,2)+pow(cs1_item2,2)),cs1_item3);
    cs2_item3=atan2(cs1_item2,cs1_item1);
}

void CCS::carToCyl(void){

     cs2_item1=sqrt(pow(cs1_item1,2)+pow(cs1_item2,2));
     cs2_item2=atan2(cs1_item2,cs1_item1);
     cs2_item3=cs1_item3;

}
void CCS::sphToCar(void){

     cs2_item1=cs1_item1*sin(getRadianFromDegree(cs1_item3))*cos(getRadianFromDegree(cs1_item2));
     cs2_item2=cs1_item1*sin(getRadianFromDegree(cs1_item2))*sin(getRadianFromDegree(cs1_item3));
     cs2_item3=cs1_item1*cos(getRadianFromDegree(cs1_item3));

}
void CCS::cyltoCar(void){

     cs2_item1=cs1_item1*cos(getRadianFromDegree(cs1_item2));
     cs2_item2=cs1_item1*sin(getRadianFromDegree(cs1_item2));
     cs2_item3=cs1_item3;

}
double CCS::getRadianFromDegree(double value){

     return value*M_PI/180;

}


double CCS::getDegreeFromRadian(double value){

    return value*180/M_PI;

}

string CCS::getConversionType(void){

     return conversionType;

}
