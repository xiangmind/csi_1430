//Author: Xiang Zhao
//Assignment Title:  Pascal's Triangle
//Assignment Description:
//  Print out Pascal's Triangle with
//  the help of myFunctions.h
//Due Date: 4/2/2021
//Date Created: 4/2/2021
//Date Last Modified: 4/2/2021
//Data Abstraction:
//  int N i j double
//Input:
//  int, the number of rows to print
//Process:
//  find i-th row j-th element of a
//  Pascal's Triangle with combination
//Output:
//  Pascal's Triangle
//Assumptions:
//  It is assumed that, having been prompted to do so, the user will
//  correctly input data

#include <iostream>
#include "myFunctions.h"
using namespace std;

int main(int argc, const char * argv[]) {
    int N;
    int i;
    int j;
    
    cout << "Please Enter The Number of Rows: ";
    cin >> N;
    cout << N << endl; //echo
    
    //Pascal's triangle
    for (i=0; i< N; i++) {
        for (j=0; j < i+1; j++) {
            cout << combination(i, j) << " ";
        }
        cout << endl;
    }
    
    return 0;
}
