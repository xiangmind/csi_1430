//Author: Xiang Zhao
//Assignment Title:  My Functions
//Assignment Description:
//  Learn how to define functions in seperate files in cpp
//Due Date: 3/26/2021
//Date Created: 3/25/2021
//Date Last Modified: 3/25/2021
//Data Abstraction:
//  int double array
//Input:
//  int double array
//Process:
//  find the min max absoluteValue
//  factorial combination permutation
//Output:
//  the min max absoluteValue
//  factorial combination permutation
//Assumptions:
//  It is assumed that, having been prompted to do so, the user will
//  correctly input data


#include "myFunctions.h"




int max(int m, int n) {
    if (n > m)
        m = n;
    return m;
}


double max(double m, double n) {
    if (n > m)
        m = n;
    return m;
}

int max (const int m[], int n) {
    int ret = m[0];
    for (int i = 0; i < n; i++) {
        if (m[i]>ret)
            ret = m[i];
    }
    return ret;
}

double max (const double m[], int n) {
    double ret = m[0];
    for (int i = 0; i < n; i++) {
        if (m[i]>ret)
            ret = m[i];
    }
    return ret;
    
}


int min (int m, int n){
    if (n < m)
        m = n;
    return m;
    
}

double min (double m, double n){
    if (n < m)
        m = n;
    return m;
}

//Function returns the value of the smallest integer in an array
int min (const int m[], int n){
    int ret = m[0];
    for (int i = 0; i < n; i++) {
        if (m[i]<ret)
            ret = m[i];
    }
    return ret;
}

//Function returns the value of the smallest double in an array
double min (const double m[], int n){
    double ret = m[0];
    for (int i = 0; i < n; i++) {
        if (m[i]<ret)
            ret = m[i];
    }
    return ret;
}


int absoluteValue (int m) {
    int ret = m;
    if (m < 0) {
        ret = -m;
    }
    
    return ret;
}


double absoluteValue (double m) {
    double ret = m;
    if (m < 0) {
        ret = -m;
    }
    
    return ret;
}


double factorial(int m) {
    double ret;
    if (m==0) {
        ret = 1;
    }
    else {
        ret = (double) m;
        while (m!=1) {
            ret = ret * (m-1);
            m--;
        }
    }
    return ret;
}


double combination( int M, int N) {
    return factorial(M) / factorial(M-N) / factorial(N);
}


double permutation( int M, int N) {
    return factorial(M) / factorial(M-N);
}
