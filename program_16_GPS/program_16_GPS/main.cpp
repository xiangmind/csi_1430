//Author: Xiang Zhao
//Assignment Title:  GPS
//Assignment Description:
//  Computes distances based on 2D GPS data
//Due Date: 2/26/2021
//Date Created: 2/25/2021
//Date Last Modified: 2/25/2021
//Data Abstraction:
//  int string ifstream double bool
//Input:
//  txt file containing lines which are GPS data
//Process:
//  read the file line by line
//  and computes distances
//Output:
//  all kinds of distances
//Assumptions:
//  It is assumed that, having been prompted to do so, the user will
//  correctly input data

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    bool done = false;
    string fileName;
    string line;
    ifstream iFile;
    string cmd;
    
    bool tripStarts = false;
    double x, y;
    double xPre = 0.0, yPre = 0.0;
    double xStart = 0.0, yStart = 0.0, xStop = 0.0, yStop = 0.0;
    double dist2StartPointSum = 0.0;
    double totalDist= 0.0;
    int n = 0;
    double dist2StartPoint;
    double dist2StartPointAvg;
    
    
    
    
    //Input
    
    do {
        
        cout << "Please Enter The Name Of The Data File: ";
        cin >> fileName;
        cout << fileName << endl;
        
        iFile.open(fileName);
        
        if (!iFile.is_open())
            cout << "Error: File failed to open.\n";
        
    } while (!iFile.is_open());
    
    
    // Process
    //getline(iFile, line);
    //getline(iFile, line);
    
    while (!done && getline(iFile, line)) {
        
        
        istringstream iss(line);
        if(!(iss >> cmd >> x >> y))
            continue;
        

        
        if (tripStarts) {
            dist2StartPointSum += sqrt((x-xStart)*(x-xStart)
                                       + (y-yStart)*(y-yStart));
            totalDist += sqrt((x-xPre)*(x-xPre)
                              + (y-yPre)*(y-yPre));
            
            n++;
        }
        
        
        if (tripStarts && cmd == "STOP") {
            done = true;
            
            xStop = x;
            yStop = y;
        }
        
        
        if (cmd == "START") {
            tripStarts = true;
            
            xStart = x;
            yStart = y;
        }
        
        xPre = x;
        yPre = y;
         
        
        
    }
    iFile.close();
    
    
    dist2StartPoint = sqrt((xStop-xStart)*(xStop-xStart)
                           + (yStop-yStart)*(yStop-yStart));
    
    dist2StartPointAvg = dist2StartPointSum / n;
    
    
    //Output

    cout << fixed << setprecision(1);
    cout << endl;
    cout << "Final Location: " << "(" << xStop << ", " << yStop << ")" << endl;
    cout << "Total distance traveled " << totalDist << endl;
    cout << "Distance to starting point " << dist2StartPoint << endl;
    cout << "Average distance to start point = " << dist2StartPointAvg << endl;
    
    
    
}
