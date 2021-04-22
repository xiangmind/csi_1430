//Author: Xiang Zhao
//Assignment Title:  Sorting Students
//Assignment Description:
// Sort a array of Student objects
//Due Date: 4/23/2021
//Date Created: 4/22/2021
//Date Last Modified: 4/22/2021
//Data Abstraction:
// fstream bool int string double
//Input:
//  data file with student's records
//  First Name      Last Name
//  Class    Zip       Age    HomeTown             GPA
//Process:
//  sort the students ascendingly
//Output:
//  the sorted students
//Assumptions:
//  It is assumed that, having been prompted to do so, the user will
//  correctly input data

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "classFunctions.h"
using namespace std;

int main() {
    
    Student students[100];
    ifstream ifs("stDATA.txt");
    string line;
    int count;
    
    
    if (!ifs) {
        cout << "No such file\n";
    }
    else {
        
        // Input
        getline(ifs, line);
        int i = 0;
        while (!ifs.eof()) {
            ifs >> students[i].firstName;
            ifs >> students[i].lastName;
            ifs >> students[i].cls;
            ifs >> students[i].zip;
            ifs >> students[i].age;
            ifs >> students[i].hometown;
            ifs >> students[i].gpa;
            


            i++;
        }
        ifs.close();
        
        
        // Process
        count = i;
        
        for (int i = 0; i < count; i++) {
            if(students[i].cls == "FR")
                students[i].clsID = 1;
            else if (students[i].cls == "SO")
                students[i].clsID = 2;
            else if (students[i].cls == "JR")
                students[i].clsID = 3;
            else if (students[i].cls == "SR")
                students[i].clsID = 4;
        }
        
        insertSort(students, count);
        
        
        
        // Output
        cout << left;
        cout << "First Name      Last Name       ";
        cout << "Class           Zip             Age             ";
        cout << "HomeTown        GPA\n";
        for (int i = 0; i < count; i++) {
            if (i == 0) {
                print(cout, students[i], 16);
            }
            else {
                if (compare(students[i], students[i-1]) == 0)
                    cout << "I THINK THIS IS A DUPLICATE RECORD" << endl;
                else
                    print(cout, students[i], 16);
            }
        }
    }

    return 0;
}
