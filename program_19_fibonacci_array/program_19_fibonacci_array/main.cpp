//Author: Xiang Zhao
//Assignment Title:  Fibonacci
//Assignment Description:
//  Compute FIbonacci array
//Due Date: 3/5/2021
//Date Created: 3/5/2021
//Date Last Modified: 3/5/2021
//Data Abstraction:
//  int vector
//Input:
//  # of cases, each case is an int
//Process:
//  computes fibonacci array for each case
//Output:
//  the fibonacci array
//Assumptions:
//  It is assumed that, having been prompted to do so, the user will
//  correctly input data











#include <iostream>
#include <vector>
using namespace std;


int main() {
    int T;
    int inp;
    int max;
    
    vector<int> cases;
    vector<unsigned long long int> fibVec(91, -1);
    
    
    // Input
    cin >> T;
    for (int i=0; i<T; i++) {
        cin >> inp;
        cases.push_back(inp);
    }
    
    // Process
    max = cases.at(0);
    for (unsigned int i = 0; i < cases.size(); i++) {
        if (cases.at(i)>max)
            max = cases.at(i);
    }
    
    fibVec.at(0) = 0;
    fibVec.at(1) = 1;
    for (int i = 2; i <= max; i++) {
        fibVec.at(i) = fibVec.at(i-1) + fibVec.at(i-2);
    }
    
    // Output
    for (unsigned int i = 0 ; i<cases.size(); i++) {
        
        cout << "Case " << i+1 << ": ";
        cout << "Fib(" << cases.at(i) <<") = ";
        cout << fibVec.at(cases.at(i)) << endl;
        
    }
    
    
    
    
    return 0;
}
