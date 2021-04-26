//Author: Xiang Zhao
//Assignment Title:  Snowman
//Assignment Description:
// Sort a array of Snowman objects
//Due Date: 4/23/2021
//Date Created: 4/22/2021
//Date Last Modified: 4/22/2021

//Data Abstraction:
// fstream bool int string double Snowman
//Input:
//  data file with Snowman's records
//Process:
//  sort the Snowmans based on color and tmp
//Output:
//  the sorted Snowmans
//Assumptions:
//  It is assumed that, having been prompted to do so, the user will
//  correctly input data

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Snowman.h"



int readDataFromFile(ifstream& openFileStream, Snowman data[]);

void sortSnowmanByScarfColor(Snowman data[], const int n);

void sortSnowmanByTemperature(Snowman data[], const int n);

int countScarves(const Snowman data[], const int n, const string color);

int countHats(const Snowman data[], const int n);

void displaySnowman(const Snowman snowmans[], const int n, ostream& os);



int main(int argc, const char * argv[]) {
    Snowman snowmans[100];
    Snowman snowmansBlue[100];
    Snowman snowmansGreen[100];
    Snowman snowmansRed[100];
    string fName;
    ifstream ifs;
    string line;
    int count;
    int countBlue;
    int countGreen;
    int countRed;
    double avgVol;
    
    
    do {
        cout << "Enter Name of Data File: ";
        cin >> fName;
        cout << fName << endl; //  echo

        ifs.open(fName);
        if (!ifs.is_open()) {
            cout << "Error: File Not Open.\n";
        }
    } while (!ifs.is_open());
    
    if(ifs.is_open()) {
        //  Input
        getline(ifs, line);
        getline(ifs, line);
        count = readDataFromFile(ifs, snowmans);
        ifs.close();
        
 
        //  Process
        sortSnowmanByScarfColor(snowmans, count);
        
        countBlue = countScarves(snowmans, count, "BLUE");
        countGreen = countScarves(snowmans, count, "GREEN");
        countRed = countScarves(snowmans, count, "RED");
        
        for (int i = 0; i < countBlue; i++) {
            snowmansBlue[i] = snowmans[i];
        }
        for (int i = countBlue; i < countBlue+countGreen; i++) {
            snowmansGreen[i-countBlue] = snowmans[i];
        }
        for (int i = countBlue+countGreen; i < count; i++) {
            snowmansRed[i-countBlue-countGreen] = snowmans[i];
        }
        
        sortSnowmanByTemperature(snowmansBlue, countBlue);
        sortSnowmanByTemperature(snowmansGreen, countGreen);
        sortSnowmanByTemperature(snowmansRed, countRed);
        
        for (int i = 0; i < countBlue; i++) {
            snowmans[i] = snowmansBlue[i];
        }
        for (int i = countBlue; i < countBlue+countGreen; i++) {
            snowmans[i] = snowmansGreen[i-countBlue];
        }
        for (int i = countBlue+countGreen; i < count; i++) {
            snowmans[i] = snowmansRed[i-countBlue-countGreen];
        }
        
        
        avgVol = 0;
        for (int i = 0; i < count; i++) {
            avgVol += snowmans[i].Volume();
        }
        avgVol /= count;
        
        
         
         
        //  Output
        cout << fixed << setprecision(2);
        displaySnowman(snowmans, count, cout);
        cout << countHats(snowmans, count) << " Snowmen have a hat.\n";
        
        cout << countRed << " Snowmen have a RED scarf.\n";
        cout << "The average volume of a snowman is ";
        cout << avgVol << endl;
        
        
        
        
    }

    
    
    
    return 0;
}









int readDataFromFile(ifstream& openFileStream, Snowman data[]) {
    double height;
    double weight;
    double temperature;
    bool   hasHat;
    string scarfColor;
    int count;
    
    int i = 0;
    while (!openFileStream.eof()) {
        openFileStream >> height >> weight;
        openFileStream >> temperature;
        openFileStream >> hasHat;
        openFileStream >> scarfColor;
        
        if (!openFileStream.fail()) {
            data[i].setHeight(height);
            data[i].setWeight(weight);
            data[i].setTemperature(temperature);
            data[i].setHasHat(hasHat);
            data[i].setScarfColor(scarfColor);
            i++;
        }
    }
    count = i;
        
    return count;
}


void sortSnowmanByScarfColor(Snowman data[], const int n) {
    int i;
    int j;
    Snowman tmp;
    
    for (i = 1; i < n; i++) {
        j=i;
        while (j > 0 && data[j].getScarfColor() < data[j-1].getScarfColor()) {
            tmp = data[j];
            data[j] = data[j-1];
            data[j-1] = tmp;
            j--;
        }
    }
}


void sortSnowmanByTemperature(Snowman data[], const int n) {
    int i;
    int j;
    Snowman tmp;
    
    for (i = 1; i < n; i++) {
        j=i;
        while (j > 0 && data[j].getTemperature() < data[j-1].getTemperature()) {
            tmp = data[j];
            data[j] = data[j-1];
            data[j-1] = tmp;
            j--;
        }
    }
}



int countScarves(const Snowman data[], const int n, const string color) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (data[i].getScarfColor() == color)
            count++;
    }
    return count;
}


int countHats(const Snowman data[], const int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (data[i].getHasHat())
            count++;
    }
    return count;
}


void displaySnowman(const Snowman snowmans[], const int n, ostream& os) {
    os << setw(10) << "Height";
    os << setw(10) << "Weight";
    os << setw(10) << "Temp";
    os << setw(10) << "Hat";
    os << setw(10) << "Scarf";
    os << endl;
    for (int i = 0; i < n; i++) {
        os << setw(10);
        os << snowmans[i].getHeight();
        os << setw(10);
        os << snowmans[i].getWeight();
        os << setw(10);
        os << snowmans[i].getTemperature();
        os << setw(10);
        os << snowmans[i].getHasHat();
        os << setw(10);
        os << snowmans[i].getScarfColor();
        os << endl;
    }
}
