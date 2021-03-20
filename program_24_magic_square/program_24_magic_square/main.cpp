//Author: Xiang Zhao
//Assignment Title:  Magic Square
//Assignment Description:
//  2d array manipulations
//Due Date: 3/19/2021
//Date Created: 3/19/2021
//Date Last Modified: 3/19/2021
//Data Abstraction:
//  int string  bool
//Input:
//  the oder of matrix, matrix
//Process:
//  check if matrix does not have duplicate entry
//  check if the sum of any col, any row,
//  or any diag equals n*(n*n+1)/2
//Output:
//  magic or not
//Assumptions:
//  It is assumed that, having been prompted to do so, the user will
//  correctly input data


#include <iostream>


using namespace std;



int main() {

    int numOfMatrices=0;
    int n=0;
    bool isUnique;
    bool isMagic;
    int sum;
    


    cin >> numOfMatrices;

    for (int k = 0; k < numOfMatrices; k++) {
        
        isUnique = true;
        isMagic = true;
        
        
        // Read a matrix
        cin >> n;

        int mat[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> mat[i][j];
                
                
            }
        }
        
        // Uniqueness
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                
                for (int ii = 0; ii < n; ii++) {
                    for (int jj = 0; jj < n; jj++) {
                        
                        if ((i!=ii && j!=jj)) {
                            if (mat[i][j]==mat[ii][jj])
                                isUnique = false;
                        }
                        
                    }
                }
                
            }
        }
        
        if (isUnique) {
            // Any col
            for (int j = 0; j < n; j++) {
                sum = 0;
                for (int i = 0; i < n; i++) {
                    sum+=mat[i][j];
                }
                if( sum != n*(n*n+1)/2)
                    isMagic = false;
            }
            // Any row
            for (int i = 0; i < n; i++) {
                sum = 0;
                for (int j = 0; j < n; j++) {
                    sum+=mat[i][j];
                }
                if( sum != n*(n*n+1)/2)
                    isMagic = false;
            }
            
            // Any diag
            sum = 0;
            for (int i = 0; i < n; i++) {
                sum+=mat[i][i];
            }
            if(sum != n*(n*n+1)/2)
                isMagic = false;

            sum = 0;
            for (int i = 0; i < n; i++) {
                sum+=mat[i][n-1-i];
            }
            if(sum != n*(n*n+1)/2)
                isMagic = false;

            if(isMagic)
                cout << "Magic\n";
            else
                cout << "Not Magic\n";
        }
        else {
            cout << "Not Magic\n";
        }
        
    }

    return 0;
}
