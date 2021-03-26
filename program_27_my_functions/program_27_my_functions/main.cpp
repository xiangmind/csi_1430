//  Unit tests
//
//  main.cpp
//  program_27_my_functions
//
//  Created by depplenny on 3/25/21.
//

#include <iostream>
#include "myFunctions.h"
using namespace std;

int main(int argc, const char * argv[]) {
    
    double m1[3] = {100,1,223};
    double m2[3] = {100.0,1.0,223.0};
    
    double m3[5] = {5.4,3.2, -2.7, 4.2, 0.0};
    
    cout << max(2, 3) << endl;
    cout << max(2.0, 3.0) << endl;
    cout << max(m1, 3) << endl;
    cout << max(m3, 5) << endl;
    
    cout << min(2, 3) << endl;
    cout << min(2.0, 3.0) << endl;
    cout << min(m1, 3) << endl;
    cout << min(m2, 3) << endl;
    
    cout << absoluteValue(-10) << endl;
    cout << absoluteValue(-10.0) << endl;
    
    cout << "factorial:" << endl;
    cout << factorial(0) << endl;
    cout << factorial(1) << endl;
    cout << factorial(2) << endl;
    cout << factorial(8) << endl;
    
    cout << "combination:" << endl;
    cout << combination(5,3) << endl;
    cout << combination(8,2) << endl;
    
    cout << "permutation:" << endl;
    cout << permutation(5,3) << endl;
    cout << permutation(8,2) << endl;
    
    
    return 0;
}
