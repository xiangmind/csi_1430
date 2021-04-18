//
//  main.cpp
//  program_35_line_class
//
//  Created by depplenny on 4/9/21.
//

#include <iostream>
#include "Line.h"



// Equality (==) operator for two custom objects
bool operator==(const Point& lhs, const Point& rhs) {
   return (lhs.x == rhs.x) &&
          (lhs.y == rhs.y);
}




int main(int argc, const char * argv[]) {
    //Point a(0,345);
    //Point b(1,331);
    //Point c(0,5);
    //Point d(1,6);
    
    Point a(0,0);
    Point b(1,1);
    Point c(5,500);
    Point d(5,60);
    
    Line l1(a,b);
    Line l2(c,d);
    
    l1.display(cout);
    cout << endl;
    l2.display(cout);
    
    assert(l1.isParallel(l2)==false);
    
    assert(l1.isCollinear(l2)==false);
    
    assert(l1.isPerpendicular(l2)==false);
    
    cout << "\nIntersect: " << l1.intersect(l2).x << " " << l1.intersect(l2).y << endl;
    
    return 0;
}
