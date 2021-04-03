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

#include <iostream>
#include "Point.h"

int main(int argc, const char * argv[]) {
    
    
    Point p1(0, 0);
    Point p2(5, 0);
    Point p3(-2, -10);
    Point p4(3, 45);
    Point p5(-5, 62);
    
    //p1.display(cout);
    //p2.display(cout);
    
    //cout << "p1.distance(p2): " << p1.distance(p2) << endl;
    
    p1.midPoint(p5).display(cout);
    p2.midPoint(p4).display(cout);
    p4.midPoint(p4).display(cout);
    p5.midPoint(p3).display(cout);
    
    return 0;
}
