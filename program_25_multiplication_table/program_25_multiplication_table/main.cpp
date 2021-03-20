//Author: Xiang Zhao
//Assignment Title:  Mutiplication Table
//Assignment Description:
//  Mutiplication Table
//Due Date: 3/19/2021
//Date Created: 3/19/2021
//Date Last Modified: 3/19/2021
//Data Abstraction:
//  int
//Input:
//  row min, row max, col min, col max
//Process:
//  generate Mutiplication Table
//Output:
//  Mutiplication Table
//Assumptions:
//  It is assumed that, having been prompted to do so, the user will
//  correctly input data



#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    int r1, r2, c1, c2;
    vector<int> rowVals;
    vector<int> colVals;
    
    cout << "Please Enter Four Integers R1 R2 C1 C2: ";
    cin >> r1 >> r2 >> c1 >> c2;
    cout << r1 << " " << r2 << " "
    << c1 << " " << c2 << endl;
    
    if (r1 < r2) {
        for (int i=r1; i <= r2; i++) {
            rowVals.push_back(i);
        }
    }
    else {
        for (int i=r1; i >= r2; i--) {
            rowVals.push_back(i);
        }
    }
    
    if (c1 < c2) {
        for (int j=c1; j <= c2; j++) {
            colVals.push_back(j);
        }
    }
    else {
        for (int j=c1; j >= c2; j--) {
            colVals.push_back(j);
        }
    }
    
    // Header
    cout << "      ";
    for (unsigned int j = 0; j < colVals.size(); j++) {
        cout << "  ";
        cout << left << setw(4);
        cout << colVals.at(j);
    }
    cout << endl;
    for (unsigned int j = 0; j <= colVals.size(); j++) {
        cout << "-----|";
    }
    cout << endl;
        
    for (unsigned int i=0; i < rowVals.size(); i++) {
        cout << left << setw(6);
        cout << rowVals.at(i);
        
        for (unsigned int j = 0; j < colVals.size(); j++)  {
            cout << "  ";
            cout << left << setw(4);
            cout << rowVals.at(i)*colVals.at(j);
        }
        cout << endl;
        
        for (unsigned int j = 0; j <= colVals.size(); j++) {
            cout << "-----|";
        }
        cout << endl;
    }
    
    
    return 0;
}
