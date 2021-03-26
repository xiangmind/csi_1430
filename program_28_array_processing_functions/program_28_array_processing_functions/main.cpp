//
//  main.cpp
//  program_28_array_processing_functions
//
//  Created by depplenny on 3/25/21.
//

#include <iostream>
#include <vector>
#include "arrayCount.h"

using namespace std;

int main(int argc, const char * argv[]) {
 
    int arrInt[4] = {1,1,2,3};
    double arrDouble[4] = {1.0,1.0,2.0,3.0};
    string arrString[4] = {"hello", "bye", "nice", "m87"};
    char arrChar[40] = "byennnn";
    vector<int> vecInt = {1, 2, 3, 4, 1, 1};
    vector<string> vecStr = {"hello", "bye", "nice", "m87", "nice"};
    vector<double> vecDouble = {1.0, 2.0, 3.0, 4.0, 1.0, 1.0};
    vector<char> vecChar = {'a','b','b','c'};
    
    
    cout << arrayCount(arrInt, 4, 1) << endl;
    
    cout << arrayCount(arrDouble, 4, 1.0) << endl;
    
    cout << arrayCount(arrString, 4, "nice") << endl;
    
    cout << arrayCount(arrChar, 'n') << endl;
    
    cout << arrayCount(vecInt, 1) << endl;
    
    cout << arrayCount(vecStr, "nice") << endl;
    
    
    cout << arrayCount(vecChar, 'b') << endl;
    
    
    return 0;
}
