//
//  classFunctions.cpp
//  program_40_sorting_students
//
//  Created by depplenny on 4/21/21.
//

#include "classFunctions.h"




void print(ostream& os, Student& student, int width) {
    os << setw(width);
    os << student.firstName;
    os << setw(width);
    os << student.lastName;
    os << setw(width);
    os << student.cls;
    os << setw(width);
    os << student.zip;
    os << setw(width);
    os << student.age;
    os << setw(width);
    os << student.hometown;
    os << setw(width);
    os << student.gpa;
    os << endl;
}




int compare(Student& s1, Student& s2) {
    int ret;
    int arr[4];
    
    if (s1.gpa < s2.gpa)
        arr[0] = -1;
    else if (s1.gpa > s2.gpa)
        arr[0] =  1;
    else
        arr[0] =  0;
    
    if (s1.clsID < s2.clsID)
        arr[1] = -1;
    else if (s1.clsID > s2.clsID)
        arr[1] =  1;
    else
        arr[1] =  0;
    
    if (s1.lastName < s2.lastName)
        arr[2] = -1;
    else if (s1.lastName > s2.lastName)
        arr[2] =  1;
    else
        arr[2] =  0;
    
    if (s1.firstName < s2.firstName)
        arr[3] = -1;
    else if (s1.firstName > s2.firstName)
        arr[3] =  1;
    else
        arr[3] =  0;
    
    int i = 0;
    while(i < 4 && arr[i] == 0) {
        i++;
    }
    
    if (i==4)
        ret = 0;
    else
        ret = arr[i];
    
    return ret;
}






void insertSort(Student students[], int count) {
    
    int i;
    int j;
    Student tmp;
    
    for (i = 1; i < count; i++) {
        j = i;
        
        while (j > 0 && compare(students[j], students[j-1]) == -1) {
            
            tmp = students[j];
            students[j] = students[j-1];
            students[j-1] = tmp;
            j--;
        }

    }

}
