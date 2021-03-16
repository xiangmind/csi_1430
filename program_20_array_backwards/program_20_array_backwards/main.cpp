//Author: Xiang Zhao
//Assignment Title:  Array backwards
//Assignment Description:
//  Manipulate array/vector
//Due Date: 3/5/2021
//Date Created: 3/5/2021
//Date Last Modified: 3/5/2021
//Data Abstraction:
//  int vect
//Input:
//  10 integers
//Process:
//  reverse the oder of vector, find the duplicate number
//Output:
//  vector max min duplicate number
//Assumptions:
//  It is assumed that, having been prompted to do so, the user will
//  correctly input data






#include <iostream>
#include <vector>

using namespace std;


bool contains(vector<int> vec, int x) {
    bool re=false;
    for (unsigned int i=0; i <vec.size(); i++) {
        if (vec.at(i)==x){
            re = true;
            break;
        }
    }
    return re;
}



int main () {
    int num;
    int inp;
    int sum=0;
    int numDup=0;
    int min;
    int max;
    vector<int> vec;
    vector<int> vecReverse;
    vector<int> dup;
    
    //Input
    cout << "Input the number of elements to store in the array: ";
    cin >> num;
    cout << num << endl; //echo input
    
    cout << "Input "<< num <<" integers:" << endl;
    for (int i = 0; i < num; i++) {
        cout << "integer - " << i << " : ";
        cin >> inp;
        cout << inp << endl; //echo input
        vec.push_back(inp);
    }
    
    cout << endl << endl;
    
    
    
    
    
    //Process
    //Reverse
    vecReverse = vec;
    for (int i = 0; i < num/2; i++) {
        swap(vecReverse.at(i), vecReverse.at(vecReverse.size()-i-1));
    }
    
    //Sum
    for (int i = 0; i < num; i++) {
        sum+=vec.at(i);
    
    }
    
    //Duplicate
    for (int i = 0; i < num ; i++) {
        if (contains(dup, vec.at(i)))
            continue;
        
        for (int j = i+1; j < num ; j++) {
            if (vec.at(i)==vec.at(j)) {
                numDup++;
                dup.push_back(vec.at(i));
                break;
            }
        }
    }
    
    //Min/Max
    min = vec.at(0);
    max = vec.at(0);
    for (int i = 0; i < num ; i++) {
        if(vec.at(i)<min)
            min = vec.at(i);
        if(vec.at(i)>max)
            max = vec.at(i);
    }
        

    
    
    //Output
    cout << "The values stored into the array are :"
    << endl;
    for (int i = 0; i < num; i++) {
        cout << vec.at(i) << " ";
    }
    
    cout << endl << endl;
    
    cout << "The values stored into the array in reverse are :"
    << endl;
    for (int i = 0; i < num; i++) {
        cout << vecReverse.at(i) << " ";
    }
    
    cout << endl << endl;
    
    cout << "The sum of all elements of the array is "
    << sum << endl;
    
    cout << "The total number of duplicate elements in the array is "
    << numDup << endl;
    
    cout << "The maximum and minimum element in the array are "
    << min << " , " << max << endl;
    
    
    
    return 0;
}
