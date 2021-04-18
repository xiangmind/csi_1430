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
#include "Line.h"



Line::Line(Point a, Point b) {
    
    p1 = a;
    p2 = b;
}


void Line::setFirstPoint(const Point& a) {
    p1 = a;
}


void Line::setSecondPoint(const Point& a) {
    p2 = a;
}


Point Line::getFirstPoint() const {
    return p1;
}

Point Line::getSecondPoint() const {
    return p2;
}


bool Line::hasSlope() const {
    bool ret = true;
    
    if (p1.x - p2.x == 0)
        ret = false;
    
    return ret;
    
}


double Line::slope() const {
    return (double(p1.y)-p2.y)/(p1.x-p2.x);
}


double Line::yIntercept() const {
    return p1.y - slope() * p1.x;
    
}

bool Line::isParallel(const Line& l) const {
    bool ret = false;
    if (slope() == l.slope())
        ret = true;
    return ret;
}


bool Line::isCollinear(const Line& l) const {
    bool ret = false;
    if (isParallel(l) && yIntercept()==l.yIntercept())
        ret = true;
    return ret;
}

bool Line::isPerpendicular(const Line& l) const {
    bool ret = false;
    if (slope()*l.slope()==-1.0)
        ret = true;
    return ret;
}

Point Line::intersect(const Line& l) const {
    Point p;
    double x,y;
    
    if (l.hasSlope()) {
        x = - (yIntercept() - l.yIntercept()) / (slope() - l.slope());
        y = slope() * x + yIntercept();
    }
    else {
        x = l.getFirstPoint().x;
        y = slope() * x + yIntercept();
    }
    
    p.x = (x - int(x) < 0.5) ? int(x) : int(x)+1;
    p.y = (y - int(y) < 0.5) ? int(y) : int(y)+1;
   
    return p;
}


void Line::display(ostream& os) const {
    if (hasSlope()) {
        if (slope()==1.0) {
            os << "y = x ";
            if (yIntercept()>0.0)
                os << "+ " << yIntercept();
            if (yIntercept()<0.0)
                os << yIntercept();
        }
        else if (slope()==-1.0) {
            os << "y = -x ";
            if (yIntercept()>0.0)
                os << "+ " << yIntercept();
            if (yIntercept()<0.0)
                os << yIntercept();
        }
        else {
            os << "y = " << slope() << "x ";
            if (yIntercept()>0.0)
                os << "+ " << yIntercept();
            if (yIntercept()<0.0)
                os << yIntercept();
        }
    }
    else {
        cout << "x = " << p1.x;
    }
        


}
