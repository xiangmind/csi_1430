//Author: Xiang Zhao
//Assignment Title:  Matrix Arithmetic
//Assignment Description:
//  Matrix add sub mul
//Due Date: 3/19/2021
//Date Created: 3/19/2021
//Date Last Modified: 3/19/2021
//Data Abstraction:
//  ifstream string int array
//Input:
//  2 2d array
//Process:
//  read the files into 2d arrays
//  add, subtract, multiply two 2d arrays
//Output:
//  resultant 2d array
//Assumptions:
//  It is assumed that, having been prompted to do so, the user will
//  correctly input data



#include <iostream>
#include <fstream>
#include <string>
using namespace std;




int main() {
    string fn1, fn2, op;
    ifstream ifs1, ifs2;
    int r1, r2;
    int c1, c2;
    
    cin >> fn1 >> fn2 >> op;

    
    ifs1.open(fn1);
    ifs2.open(fn2);
    if(ifs1.is_open() && ifs2.is_open()) {
        ifs1 >> r1;
        ifs1 >> c1;
        ifs2 >> r2;
        ifs2 >> c2;
        
        int mat1[r1][c1];
        int mat2[r2][c2];
        
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c1; j++) {
                ifs1 >> mat1[i][j];
            }
        }
        ifs1.close();
        
        for (int i = 0; i < r2; i++) {
            for (int j = 0; j < c2; j++) {
                ifs2 >> mat2[i][j];
            }
        }
        ifs2.close();
     
        
        if (op=="add") {
            if (r1==r2 && c1==c2) {
                for (int i = 0; i < r1; i++) {
                    for (int j = 0; j < c1; j++) {
                        cout << mat1[i][j]+mat2[i][j] << " ";
                    }
                    cout << endl;
                }
            }
            else {
                cout << "NO COMPATIBLE\n";
            }
            
        }
        
        if (op=="subtract") {
            if (r1==r2 && c1==c2) {
                for (int i = 0; i < r1; i++) {
                    for (int j = 0; j < c1; j++) {
                        cout << mat1[i][j]-mat2[i][j] << " ";
                    }
                    cout << endl;
                }
            }
            else {
                cout << "NO COMPATIBLE\n";
            }
            
        }
        
        if (op=="multiply") {
            
            if (c1 == r2) {
                for (int i = 0; i < r1; i++) {
                    for (int j = 0; j < c2; j++) {
                        int sum = 0;
                        for (int k =0; k < c1; k++) {
                            sum += mat1[i][k]*mat2[k][j];
                        }
                        cout <<  sum << " ";
                    }
                    cout << endl;
                }
            }
            else {
                cout << "NO COMPATIBLE\n";
            }
            
        }
        
        
        
    }
    return 0;
}
