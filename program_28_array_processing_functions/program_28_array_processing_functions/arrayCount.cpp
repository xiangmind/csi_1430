//Author: Xiang Zhao
//Assignment Title:  Array Count
//Assignment Description:
//  Count a value in the array/vector for different data type
//Due Date: 3/26/2021
//Date Created: 3/25/2021
//Date Last Modified: 3/25/2021
//Data Abstraction:
//  int double char string array vector
//Input:
//  int double char string array vector
//Process:
//  Count a value in the array/vector for different data type
//Output:
//  frequency
//Assumptions:
//  It is assumed that, having been prompted to do so, the user will
//  correctly input data


#include "arrayCount.h"
#include <string>
#include <vector>
#include <cstring>
using namespace std;


int arrayCount(int a[], int s, int v) {
    int freq = 0;
    for (int i = 0; i < s; i++) {
        if(v == a[i])
            freq++;
    }
    return freq;
}



int arrayCount(double a[], int s, double v) {
    int freq = 0;
    for (int i = 0; i < s; i++) {
        if(v == a[i])
            freq++;
    }
    return freq;
}


int arrayCount(string a[], int s, string v) {
    int freq = 0;
    for (int i = 0; i < s; i++) {
        if(v == a[i])
            freq++;
    }
    return freq;
}


int arrayCount(char a[], char v) {
    int freq = 0;
    for (unsigned int i = 0; i < strlen(a); i++) {
        if(v == a[i])
            freq++;
    }
    return freq;
    
    
    
}


int arrayCount(vector<int> a, int v) {
    int freq = 0;
    for (unsigned int i = 0; i < a.size(); i++) {
        if(v == a[i])
            freq++;
    }
    return freq;
    
}


int arrayCount(vector<string> a, string v) {
    int freq = 0;
    for (unsigned int i = 0; i < a.size(); i++) {
        if(v == a[i])
            freq++;
    }
    return freq;
    
    
}


int arrayCount(vector<double> a, double v) {
    int freq = 0;
    for (unsigned int i = 0; i < a.size(); i++) {
        if(v == a[i])
            freq++;
    }
    return freq;
    

}


int arrayCount(vector<char> a, char v) {
    int freq = 0;
    for (unsigned int i = 0; i < a.size(); i++) {
        if(v == a[i])
            freq++;
    }
    return freq;
    
    
}
