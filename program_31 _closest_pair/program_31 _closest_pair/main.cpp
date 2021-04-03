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
#include "ClosestPair.h"
using namespace std;

int main(int argc, const char * argv[]) {
    const int N = 4;
    Pair pair;
    
    Point p0(443.73, 31.22);
    Point p1(43.72, 31.22);
    Point p2(0.0, 30.0);
    Point p3(0.0, -3.0);

    Point P[N] = {p0, p1, p2, p3};
  
    pair = Closest_Pair(P, N);
    
    cout << "Closest Pair: (" << pair.indexPointOne << ", "
        << pair.indexPointTwo << ")\n";
    

    
    return 0;
}
