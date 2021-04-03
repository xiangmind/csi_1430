//Author: Xiang Zhao
//Assignment Title:  Closest Pair
//Assignment Description:
// Find the closest points
//Due Date: 4/2/2021
//Date Created: 4/2/2021
//Date Last Modified: 4/2/2021
//Data Abstraction:
//  Pair double vector int
//Input:
//  An array P of n (n >= 2) Points P1 = (x1,y1) … Pn = (xn, yn)
//Process:
//  Find the dists between points
//  Find the smallest dist
//  Find the point index with the smallest dist
//Output:
//  The pair with the smallest dist
//Assumptions:
//  It is assumed that, having been prompted to do so, the user will
//  correctly input data

#ifndef ClosestPair_h
#define ClosestPair_h


struct Point{
     double x;
     double y;

     Point(double a = 0, double b = 0){
        x = a;
        y = b;
     }
};

struct Pair{
     int indexPointOne;
     int indexPointTwo;
};


Pair Closest_Pair(Point P[ ], int n);

double dist(Point p1, Point p2);

#endif /* ClosestPair_h */
