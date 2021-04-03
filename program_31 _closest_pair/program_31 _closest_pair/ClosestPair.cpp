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

#include <iostream>
#include <cmath>
#include <vector>
#include "ClosestPair.h"

using namespace std;

Pair Closest_Pair(Point P[ ], int n) {
    Pair pair;
    double closestDist;
    vector<Pair> pairs;
    int avg;
    
    //Find the closestDist
    closestDist = dist(P[0], P[1]);
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (dist(P[i], P[j]) < closestDist) {
                closestDist = dist(P[i], P[j]);
            }
        }
    }
    
    //Find all pairs with the closestDist
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if ( dist(P[i], P[j]) == closestDist) {
                pair.indexPointOne = i;
                pair.indexPointTwo = j;
                pairs.push_back(pair);
            }
        }
    }
    
    //Find the pair of points with the smallest average index
    if (pairs.size()==1) {
        pair = pairs[0];
    } else {
        
        avg = pairs.at(0).indexPointOne
            + pairs.at(0).indexPointTwo;
        pair = pairs.at(0);
        for (unsigned int i = 0; i < pairs.size(); i++) {
            
            if (pairs.at(i).indexPointOne+pairs.at(i).indexPointTwo < avg) {
                avg = pairs.at(i).indexPointOne
                    + pairs.at(i).indexPointTwo;
                pair = pairs.at(i);
            }
        }
    }
    
    return pair;
    
}


double dist(Point p1, Point p2) {
    return sqrt( pow(p1.x-p2.x, 2) + pow(p1.y-p2.y, 2) );
}
