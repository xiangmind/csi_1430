//Author: Xiang Zhao
//Assignment Title:  Weatehr Data
//Assignment Description:
// Read Weatehr Data and analyze it
//Due Date: 4/16/2021
//Date Created: 4/16/2021
//Date Last Modified: 4/16/2021
//Data Abstraction:
// fstream sstream vector string double
//Input:
//  data file and the target state
//Process:
//  computes avgTemp for the cities in target state
//Output:
//  cities temps
//Assumptions:
//  It is assumed that, having been prompted to do so, the user will
//  correctly input data

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;


int main(int argc, const char * argv[]) {
    
    double d, minTemp, maxTemp, avgTemp;
    char c;
    ifstream ifs;
    istringstream iss;
    string line;
    string token;
    string fName;
    string targetState;
    string state_id;
    string state;
    string city;

    
    cout << "Enter Data File Name and State (fileName, State): " ;
    getline(cin, line);
    cout << line << endl; //echo
    
    fName = line.substr(0, line.find(","));
    targetState = line.substr(line.find(",")+1);

    
    ifs.open(fName);
    
    if(ifs.is_open()) {

        
        
        getline(ifs, line);
        while (getline(ifs, line)) {
            iss.clear();
            iss.str(line);
            getline(iss, city, ',');
            getline(iss, state_id, ',');
            getline(iss, state, ',');
            
            if ( state_id == targetState || state == targetState) {
                for (int i = 0; i < 3; i++) {
                    getline(iss, token, ',');
                }
                vector<double> temps;
                while (!iss.eof()) {
                    iss >> d;
                    if (!iss.fail())
                        temps.push_back(d);
                    else {
                        iss.clear();
                        iss >> c;
                    }
                }

                minTemp = temps[0];
                maxTemp = temps[0];
                avgTemp = 0.0;
                for (size_t i = 0; i < temps.size(); i++) {
                    if (temps[i] < minTemp)
                        minTemp = temps[i];
                    if (temps[i] > maxTemp)
                        maxTemp = temps[i];
                    avgTemp += temps[i];
                }
                avgTemp /= temps.size();
                
                cout << city << ", " << state_id << ", ";
                cout << setprecision(2) << fixed;
                cout << minTemp << " " << maxTemp << " " << avgTemp << endl;
            }
        }
        
        
        
        ifs.close();
    }
    else {
        cout << "Error: File Failed to open." << endl;
        
    }

    return 0;
}
