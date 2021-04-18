/*
Author: Xiang Zhao
Assignment Title: Practicum 10
Assignment Description: Practicum 10 Class
Due Date: 4/9/2021
Date Created: 4/9/2021
Date Last Modified: 4/9/2021
*/

#ifndef myPoint_h
#define myPoint_h
#include <iostream>
using namespace std;

class myPoint{

    private:
        double x,y;

    public:
        myPoint();
        myPoint(double xValue, double yValue);
    
    
        //description: setter for data member x
        //return: void
        //precondition: previous x
        //postcondition: updated x
        void setX(double);
    
        
        //description: setter for data member y
        //return: void
        //precondition: previous y
        //postcondition: updated y
        void setY(double);
    
    
        //description: getter for data member x
        //return: x coordinate double
        //precondition:  a object
        //postcondition: same object
        double getX() const;
    
    
        //description: getter for data member x
        //return: y coordinate double
        //precondition:  a object
        //postcondition: same object
        double getY() const;
    
    
        //description: computes distance between two points
        //return: distance double
        //precondition:
        //postcondition:
        double distance(const myPoint&) const;
    
    
        //description: computes midpoint of two points
        //return: midpoint mypoint
        //precondition:
        //postcondition:
        myPoint midpoint(const myPoint&) const;
    
    
        //description: print point as (x,y)
        //return: void
        //precondition:
        //postcondition:
        void display(ostream&) const;

};

#endif /* myPoint_h */
