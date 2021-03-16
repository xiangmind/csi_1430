//Author: Xiang Zhao
//Assignment Title:  Class Average
//Assignment Description:
//  Computes avg score of the class from
//  data files
//Due Date: 3/5/2021
//Date Created: 3/4/2021
//Date Last Modified: 3/4/2021
//Data Abstraction:
//  int string ifstream double bool vector
//Input:
//  .dat file containing lines which are names and scores
//Process:
//  read the file line by line
//  and computes avg scores
//Output:
//  avg score for each student and for class
//Assumptions:
//  It is assumed that, having been prompted to do so, the user will
//  correctly input data








#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
using namespace std;


int main () {
    bool hasOpened=false;
    string nameDataFile;
    ifstream streamDataFile;
    string lastName;
    string firstName;
    string middleName;
    // name1 is "fistName middleName lastName"
    // name2 is "fisrtNameLastName.dat"
    string name1;
    string name2;
    vector<string> names1;
    vector<string> names2;
    vector<double> avgScores;
    
    double classAvg=0.0;
    double classSum=0.0;
    int n=0;
    double classMin=1.0e10;
    double classMax=-1.0e10;
    
    ifstream streamScores;
    int score;
    double avg;
    
    

    
    
    
    // Read all names into vector names1 & names2
    cout << "Enter Name of Data File: ";
    cin >> nameDataFile;
    cout << nameDataFile << endl; //echo print

    streamDataFile.open(nameDataFile);
    if (streamDataFile.is_open()) {
        while (streamDataFile >> lastName >> firstName >> middleName) {
            name1 = firstName + " " + middleName + " " + lastName;
            name2 = firstName+lastName+".dat";
            
            names1.push_back(name1);
            names2.push_back(name2);
        }
        streamDataFile.close();
        // Data has opened
        hasOpened = true;
        
    }
    
    // Read all scores for a student
    // and make sure every student has an avg grade
    // -999.0 means student has no "grades file"
    // -888.0 means student has an empty "grades file"
    if (!hasOpened) {
        cout << "ERROR: File Not Open." << endl;
    }
    else {
        // Iterate through each student's grades file
        for (unsigned int i = 0; i < names2.size(); i++) {
            vector<int> scores;

            streamScores.open(names2.at(i));
            
            if(!streamScores.is_open()) {
                //cout << "No Data File" << endl;
                avgScores.push_back(-999.0);
            }
            else {
                // Read all scores of a student to the vector scores
                while (streamScores >> score) {
                    scores.push_back(score);
                }
                streamScores.close();
                
                // Analyze the scores of a student
                // and keep the result in the vector avgScores
                if (scores.size()==0) {
                    //cout << "No Grades" << endl;
                    avgScores.push_back(-888.0);
                }
                else {
                    int sum = 0;

                    for (unsigned int i = 0; i < scores.size(); i++) {
                        classSum+=scores.at(i);
                        n++;
                        
                        if (scores.at(i) < classMin)
                            classMin = scores.at(i);
                        
                        if (scores.at(i) > classMax)
                            classMax = scores.at(i);
                        
                        sum+=scores.at(i);
                    }
                    avg = static_cast<double>(sum)/scores.size();
                    avgScores.push_back(avg);
                }
            }
        }
        // Computes class avg
        classAvg = classSum / n;
        
        
        // Output
        cout << endl;
        cout << fixed << setprecision(2);
        cout << left << setfill(' ')
        << setw(25) << "Student";
        cout << "Average" << endl;
        
        for (unsigned int i = 0; i < names1.size(); i++) {
            cout << left << setfill(' ')
            << setw(25) << names1.at(i);
            if (avgScores.at(i)<-900.0)
                cout << "No Data File" << endl;
            else if (avgScores.at(i)<-800.0)
                cout << "No Grades" << endl;
            else
                cout << avgScores.at(i) << endl;
        }
        cout << endl;

        cout << "Class Average: " << classAvg << endl;
        cout << "Max Score: " << classMax << endl;
        cout << "Min Score: " << classMin << endl;
        
    }
    
    return 0;
}
