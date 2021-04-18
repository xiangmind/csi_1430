/*
Author: Xiang Zhao
Assignment Title: Practicum 10
Assignment Description: Practicum 10 Class
Due Date: 4/9/2021
Date Created: 4/9/2021
Date Last Modified: 4/9/2021
*/

#include "myPoint.h"
#include <cmath>


myPoint::myPoint() {
    x = 3.6;
    y = 4.2;
    
    
}


myPoint::myPoint(double a, double b) {
    x = a;
    y = b;
    
    
}



void myPoint::setX(double a) {
    x = a;
}
void myPoint::setY(double a) {
    y = a;
}
double myPoint::getX() const {
    return x;
}
double myPoint::getY() const {
    return y;
}

double myPoint::distance(const myPoint& mp) const {
    return sqrt( (x-mp.x)*(x-mp.x) + (y-mp.y)*(y-mp.y) );
}
myPoint myPoint::midpoint(const myPoint& mp) const {
    myPoint ret;
    ret.setX((x+mp.x)/2.0);
    ret.setY((y+mp.y)/2.0);
    return ret;
}


void myPoint::display(ostream& os) const {
    os << "(" << x << "," << y << ")";
}
