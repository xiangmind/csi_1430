/*
Author: Xiang Zhao
Date: 4/26/2021
Description:
  new delete operator should form a pair
*/





#include <iostream>
using namespace std;



class A {
private:
    int data;
    int* intPtr;


public:
    A() {
        data = 1;

        intPtr = new int;
        *intPtr = 2;
    }

    ~A() {
        delete intPtr;
    }


    int getData() {
        return data;
    }

    int* getIntPtr() {
        return intPtr;
    }

    int getInt() {
        return *intPtr;
    }
};




int main() {
    //  new allocates memory for type A and calls A's constructor
    //  returns object's address 
    //  there are two variables in memory now:
    //  aPtr and *aPtr i.e. type A pointer and type A object
    A* aPtr = new A;  

    // print variable aPtr's value i.e. object *aPtr's address
    cout << "aPtr = " << aPtr << endl;

    //  dp sth with aPtr
    cout << "aPtr->getData() = "<< aPtr->getData() << endl;
    cout << "aPtr->getIntPtr() = "<< aPtr->getIntPtr() << endl;
    cout << "aPtr->getInt() = "<< aPtr->getInt() << endl;

    //  delete calls A's destructor and deallocates memory for *aPtr,
    //  memory for aPtr is intact
    delete aPtr; 

    // print variable aPtr's value 
    cout << "aPtr = " << aPtr << endl;

    // since aPtr points to deallocated memory,
    // attempting to use point1 after deletion is a logic error.
    //cout << "aPtr->getData() = "<< aPtr->getData() << endl;  //Error

}