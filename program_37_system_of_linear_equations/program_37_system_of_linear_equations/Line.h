//Author: Xiang Zhao
//Assignment Title:  Line Class
//Assignment Description:
// Line Class with Point Struct
//Due Date: 4/9/2021
//Date Created: 4/9/2021
//Date Last Modified: 4/9/2021
//Data Abstraction:
//  Point, int double
//Input:
//  x y coordinates of points
//Process:
//  computes slope intercept inetersect
//Output:
//  slope intercept inetersect
//Assumptions:
//  It is assumed that, having been prompted to do so, the user will
//  correctly input data

#ifndef Line_h
#define Line_h


#include <iostream>
#include "Point.h"

using namespace std;


class Line{
    private:
        Point p1, p2;

    public:
        Line(Point=Point(1,1), Point=Point(0,0));
        // description: calculate total price of item with tax
        // return: double
        // precondition: price and tax are valid
        // postcondition: returns sum of price and tax
        void setFirstPoint(const Point&);
        // description: calculate total price of item with tax
        // return: double
        // precondition: price and tax are valid
        // postcondition: returns sum of price and tax
        void setSecondPoint(const Point&);
        // description: calculate total price of item with tax
        // return: double
        // precondition: price and tax are valid
        // postcondition: returns sum of price and tax
        Point getFirstPoint() const;
        // description: calculate total price of item with tax
        // return: double
        // precondition: price and tax are valid
        // postcondition: returns sum of price and tax
        Point getSecondPoint() const;
        // description: calculate total price of item with tax
        // return: double
        // precondition: price and tax are valid
        // postcondition: returns sum of price and tax
        bool   hasSlope() const;
        // description: calculate total price of item with tax
        // return: double
        // precondition: price and tax are valid
        // postcondition: returns sum of price and tax
        double slope() const;
        // description: calculate total price of item with tax
        // return: double
        // precondition: price and tax are valid
        // postcondition: returns sum of price and tax
        double yIntercept() const;
        // description: calculate total price of item with tax
        // return: double
        // precondition: price and tax are valid
        // postcondition: returns sum of price and tax
        bool isParallel(const Line&) const;
        // description: calculate total price of item with tax
        // return: double
        // precondition: price and tax are valid
        // postcondition: returns sum of price and tax
        bool isCollinear(const Line&) const;
        // description: calculate total price of item with tax
        // return: double
        // precondition: price and tax are valid
        // postcondition: returns sum of price and tax
        bool isPerpendicular(const Line&) const;
        // description: calculate total price of item with tax
        // return: double
        // precondition: price and tax are valid
        // postcondition: returns sum of price and tax
        Point intersect(const Line&) const;
        // description: calculate total price of item with tax
        // return: double
        // precondition: price and tax are valid
        // postcondition: returns sum of price and tax
        void display(ostream&) const;
};

#endif /* Line_h */
