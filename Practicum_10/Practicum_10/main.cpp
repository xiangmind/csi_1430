/*
Author: Xiang Zhao
Assignment Title: Practicum 10
Assignment Description: Practicum 10 Class
Due Date: 4/9/2021
Date Created: 4/9/2021
Date Last Modified: 4/9/2021
*/

/*
Data Abstraction: myPoint class
Input: double x y coordinates
Process:
 create myPoint objects,
 find the distance and the midpoint
Output: distance and the midpoint
Assumptions: user enters valid inputs
*/


#include <iostream>
#include "myPoint.h"

int main(int argc, const char * argv[]) {
    myPoint p1,p2;
    double x1,y1,x2,y2;
    
    cout << "Please enter two points: ";
    cin >> x1 >> y1 >> x2 >> y2;
    cout << x1 << " " << y1 << " ";
    cout << x2 << " " << y2 << endl;
    
    p1.setX(x1);
    p1.setY(y1);
    p2.setX(x2);
    p2.setY(y2);
    
    p1.display(cout);
    p2.display(cout);
    
    cout << endl;
    
    cout << "Distance = " << p1.distance(p2);
    
    cout << endl;
    
    cout << "Midpoint = ";
    p1.midpoint(p2).display(cout);
    
    cout << endl;
    
    
    
    return 0;
}
