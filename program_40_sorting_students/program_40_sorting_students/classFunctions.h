//
//  classFunctions.hpp
//  program_40_sorting_students
//
//  Created by depplenny on 4/21/21.
//

#ifndef classFunctions_hpp
#define classFunctions_hpp
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

// A student struct
struct Student{
    string firstName, lastName, cls, hometown;
    int zip, age, clsID;
    double gpa;
};



// Print Student object
void print(ostream & os, Student& student, int width);


// Priority: gpa > cls > lastName > firstName
int compare(Student& s1, Student& s2);



// Sort the array
void insertSort(Student students[], int count);




#endif /* classFunctions_hpp */
