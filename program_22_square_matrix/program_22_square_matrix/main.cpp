//Author: Xiang Zhao
//Assignment Title:  Square Matrix
//Assignment Description:
//  get familar with square matrix
//Due Date: 3/12/2021
//Date Created: 3/12/2021
//Date Last Modified: 3/12/2021
//Data Abstraction:
//  int vector
//Input:
//  an integer number N (0 ≤ N ≤ 100) that
//  corresponds to the order of a matrix
//Process:
//  generate matrix based on order integer
//Output:
//  generated matrix
//Assumptions:
//  It is assumed that, having been prompted to do so, the user will
//  correctly input data








#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    vector<int> v;
    int inp;
    int N; // full matrix dim
    int n; // center matrix dim
    int x; // matrix entry
    int start;
    
    
    do{
        cin >> inp;
        v.push_back(inp);
        
    } while (inp!=0);
    
    // Get rid of 0
    v.pop_back();
    
    
    for (unsigned int k = 0; k < v.size(); k++) {
        
        N = v.at(k);
        int mat[N][N];
        start=0;
        x=1;
        
        if (N % 2 == 0)
            n = 2;
        else
            n = 1;
        
        while (N >= n) {

            for (int i = start; i < N; i++) {
                for (int j = start; j < N; j++) {
                    mat[i][j] = x;
                }
            }
            
            N-=1;
            start+=1;
            x+=1;
        }
        
        
        
        
        for (int i = 0; i < v.at(k); i++) {
            for (int j = 0; j < v.at(k); j++) {
                cout << right << setw(3);
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
        
        cout << endl;
        
    }
    
    return 0;
}
