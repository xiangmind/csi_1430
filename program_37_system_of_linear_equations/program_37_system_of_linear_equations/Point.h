//Author: Xiang Zhao
//Assignment Title:  Point Structure
//Assignment Description:
// A point structure with functions
//Due Date: 4/2/2021
//Date Created: 4/2/2021
//Date Last Modified: 4/2/2021
//Data Abstraction:
// int Point
//Input:
//  two int x y
//Process:
//  Make a struct point
//  Find the distance midPoint
//  Display the point
//Output:
//  the distance midPoint
//Assumptions:
//  It is assumed that, having been prompted to do so, the user will
//  correctly input data

#ifndef Point_h
#define Point_h

#include <iostream>
using namespace std;

struct Point{
    int x, y;
    
    // description: calculate total price of item with tax
    // return: double
    // precondition: price and tax are valid
    // postcondition: returns sum of price and tax
    Point(int = 0, int = 0);

    // description: calculate total price of item with tax
    // return: double
    // precondition: price and tax are valid
    // postcondition: returns sum of price and tax
    void display(ostream&) const;
    // description: calculate total price of item with tax
    // return: double
    // precondition: price and tax are valid
    // postcondition: returns sum of price and tax
    double distance(const Point&) const;
    // description: calculate total price of item with tax
    // return: double
    // precondition: price and tax are valid
    // postcondition: returns sum of price and tax
    Point midPoint(const Point&) const;
};









#endif /* Point_h */
