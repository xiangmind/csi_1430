//Author: Xiang Zhao
//Assignment Title:  Time Class
//Assignment Description:
// Sort a array of Time objects
//Due Date: 4/23/2021
//Date Created: 4/20/2021
//Date Last Modified: 4/20/2021
//Data Abstraction:
// fstream sstream bool int string double
//Input:
//  data file with times hh:mm:ss
//Process:
//  sort the times ascendingly
//Output:
//  the sorted times
//Assumptions:
//  It is assumed that, having been prompted to do so, the user will
//  correctly input data

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;




struct Time{
    int hour;
    int min;
    double second;
};



bool operator<(Time& t1, Time& t2) {
    bool ret;
    double sec1, sec2;
    
    sec1 = t1.hour * 3600 + t1.min * 60 + t1.second;
    sec2 = t2.hour * 3600 + t2.min * 60 + t2.second;
    
    if (sec1 < sec2)
        ret = true;
    else
        ret =false;
    
    return ret;
}

void insertSort(Time times[], int count) {
    int i;
    int j;
    Time tmp;
    
    for (i = 1; i < count; i++) {
        j = i; // the real time index of the element to be inserted
        
        while (j > 0 && times[j] < times[j-1]) {
            tmp = times[j];
            times[j] = times[j-1];
            times[j-1] = tmp;
            
            j--;
        }

    }
}



int main(int argc, const char * argv[]) {
    Time times[100];
    string line;
    ifstream ifs;
    istringstream iss;
    int count;
    
    ifs.open("timeData.txt");
    
    if(!ifs) {
        cout << "Data File Failed To Open.\n";
    }
    else {
        // Input
        getline(ifs, line);
        int i = 0;
        while (getline(ifs, line)) {
            for (size_t j = 0; j < line.size(); j++) {
                if (line[j] == ':')
                    line[j] = 0;
            }
            
            iss.clear();
            iss.str(line);
            iss >> times[i].hour >> times[i].min >> times[i].second;
            
            i++;
        }
        ifs.close();
        
        // Process
        count = i;
        insertSort(times, count);
        
        // Output
        cout  << setfill('0');
        for (int i = 0; i < count; i++) {
            cout << setw(2) << times[i].hour << ":";
            cout << setw(2) << times[i].min << ":";
            cout << setw(2) << times[i].second <<endl;
        }
        
        
    }

    return 0;
}
