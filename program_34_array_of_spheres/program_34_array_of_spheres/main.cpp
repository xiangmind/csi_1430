//Author: Xiang Zhao
//Assignment Title:  Array of Sphere class
//Assignment Description:
//  Array of sphere class
//Due Date: 4/9/2021
//Date Created: 4/9/2021
//Date Last Modified: 4/9/2021
//Data Abstraction:
//  string fname;
//  string line;
//  ifstream ifs;
//  double r;
//  string c;
//  int numRed=0;
//  int numVol215=0;
//  double avgArea=0;
//  Sphere spheres[100];
//Input:
//  spheres in data.txt
//Process:
//  create spheres and computes statistics
//Output:
//  report of the statistics
//Assumptions:
//  It is assumed that, having been prompted to do so, the user will
//  correctly input data


#include <iostream>
#include <string>
#include <fstream>
#include "Sphere.h"
#include <iomanip>

int main(int argc, const char * argv[]) {
    string fname;
    string line;
    ifstream ifs;
    double r;
    string c;
    int numRed=0;
    int numVol215=0;
    double avgArea=0;
    
    Sphere spheres[100];
    
    do {
        cout << "Enter file name: ";
        cin >> fname;
        cout << fname << endl; //echo
        
        ifs.open(fname);
        if(!ifs)
            cout << "Error: File Not Open.\n";
    } while (!ifs);
    
    if (ifs) {
        getline(ifs, line);
        getline(ifs, line);
        int i = 0;
        while(ifs >> r >> c) {
            spheres[i].setRadius(r);
            spheres[i].setColor(c);
            i++;
        }
        ifs.close();
        
        cout << endl;
        cout << fixed << setprecision(2);
        cout << setw(12) << right << "Number";
        cout << setw(12) << right << "Radius";
        cout << setw(12) << right << "Color";
        cout << setw(12) << right << "Area";
        cout << setw(12) << right << "Volume";
        cout << endl;
        
        for (int j = 0; j < i; j++) {
            cout << setw(12) << right;
            cout << j;
            cout << setw(12) << right;
            cout << spheres[j].getRadius();
            cout << setw(12) << right;
            cout << spheres[j].getColor();
            cout << setw(12) << right;
            cout << spheres[j].area();
            cout << setw(12) << right;
            cout << spheres[j].volume();
        
            cout << endl;
            
            
            if (spheres[j].getColor()=="red")
                numRed++;
                
            if (spheres[j].area()>215.0)
                numVol215++;
            
            avgArea+=spheres[j].area();
            
            
        }
        
        cout << endl;
        cout << "Total Number of Spheres = " << i << "." << endl;
        cout << double(numRed)/i*100 << "% of Spheres are red." << endl;
        cout << numVol215 << " Spheres have a Volume over 215." << endl;
        cout << "Average Area = " << avgArea/i << endl;
        
        
    }
    

    
    
    return 0;
}
