//Author: Xiang Zhao
//Assignment Title:  System of linear equations
//Assignment Description:
// read a system of linear equations and
// computes solutions
//Due Date: 4/16/2021
//Date Created: 4/16/2021
//Date Last Modified: 4/16/2021
//Data Abstraction:
// Line Point istringstream int char
//Input:
//  two strings stands for eqns
//Process:
//  parse string to numbers
//Output:
//  the intersection point
//Assumptions:
//  It is assumed that, having been prompted to do so, the user will
//  correctly input data

#include <iostream>
#include "Line.h"
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
using namespace std;


/*
 eqn format 1:  y = -ax + c (b = 1)
 eqn format 2:  x = c (b = 0, a = 1)
 eqn format 3:  by = -ax + c
 eqn format 4:  by + ax = c
 */
Line parseLine(string eqn) {
    Point p1, p2;
    double a, b, c;
    vector<string> parts;
    istringstream iss(eqn);
    string str;
    
    while(iss >> str) {
        parts.push_back(str);
    }
    
    if (parts.at(0)=="y") {
        //  eqn format 1
        b = 1.0;
        
        str = parts.at(2).substr(0, parts.at(2).size()-1);
        a =  -1.0 * stod(str);
        
        if (parts.size()==3) {
            c = 0.0;
        }
        else {
            if (parts.at(3) == "+")
                c = stod(parts.at(4));
            else
                c = -1.0 * stod(parts.at(4));
        }
    }
    else if (parts.at(0)=="x") {
        //  eqn format 2
        b = 0.0;
        a = 1.0;
        c = stod(parts.at(2));
    }
    else {
        if (parts.at(1)=="=") {
            //  eqn format 3
            str = parts.at(0).substr(0, parts.at(0).size()-1);
            b = stod(str);
            
            str = parts.at(2).substr(0, parts.at(2).size()-1);
            a = -1.0 * stod(str);
            
            if (parts.size()==3) {
                c = 0.0;
            }
            else {
                if (parts.at(3) == "+")
                    c = stod(parts.at(4));
                else
                    c = -1.0 * stod(parts.at(4));
            }
        }
        else {
            //  eqn format 4
            str = parts.at(0).substr(0, parts.at(0).size()-1);
            b = stod(str);
            
            str = parts.at(2).substr(0, parts.at(2).size()-1);
            a = stod(str);
            
            c = stod(parts.at(4));
        }
        
    }
    
    if (b!=0.0) {
        
        p1.x = 0 ;
        p1.y = c/b;
        
        p2.x = 1;
        p2.y = (c-a)/b;
 
    }
    else {
        
        p1.x = c/a;
        p1.y = 0;
        
        p2.x = c/a;
        p2.y = 1;
    }
    
    return Line(p1, p2);
}



int main(int argc, const char * argv[]) {
    string eqn1;
    string eqn2;
    
    getline(cin, eqn1);
    getline(cin, eqn2);

    Line line1 = parseLine(eqn1);
    Line line2 = parseLine(eqn2);
    
    if (line1.isParallel(line2) || line1.isCollinear(line2)) {
        cout << "NO SOLUTION" << endl;
    }
    else {
        cout << "SOLUTION: ";
        line1.intersect(line2).display(cout);
    }


    
   


    
    return 0;
}
