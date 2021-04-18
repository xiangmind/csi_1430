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

#include "Point.h"
#include <cmath>

Point::Point(int a, int b) {
    x = a;
    y = b;
}



void Point::display(ostream& os) const {
    
    os << "(" << x << ", " << y << ")\n";
    
}


double Point::distance(const Point& p2) const {
    return sqrt(pow(x-p2.x,2) + pow(y-p2.y,2));
}


Point Point::midPoint(const Point& p2) const {
    Point mP;
    mP.x = (x+p2.x)/2;
    mP.y = (y+p2.y)/2;
    
    if (mP.x < 0)
        mP.x = mP.x - 1;
    
    if ((y+p2.y) % 2 !=0)
        mP.y  = mP.y + 1;
    
    return mP;
}
