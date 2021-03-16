//Author: Xiang Zhao
//Assignment Title:  Caesar Cipher
//Assignment Description:
//  Encode or decode string by shift the integer value
//Due Date: 2/26/2021
//Date Created: 2/25/2021
//Date Last Modified: 2/25/2021
//Data Abstraction:
//  int cahr bnool string ifstream ofstream
//Input:
//  txt file containing lines which are to be encoded or decoded
//Process:
//  read the file char by char, shift it by 3,
//  and count specific letters freq
//Output:
//  transformed message, and freq
//Assumptions:
//  It is assumed that, having been prompted to do so, the user will
//  correctly input data




#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

int main() {
    string ifName;
    string modeStr;
    ifstream iFile;
    ofstream oFile;
    bool has_report=false;
    char c;
    int freqA=0;
    int freqE=0;
    int freqI=0;
    int freqO=0;
    int freqU=0;
    int freqY=0;
    
    

    
    // Input
    
    cout << "Enter File Name: ";
    cin >> ifName;
    cout << ifName << endl;
    
    cout << "Enter encrypt or decrypt: ";
    cin >> modeStr;
    cout << modeStr << endl;
    
        
    if (modeStr!="encrypt" && modeStr!="decrypt")
        cout << "Error: Bad Command.\n";
    
    iFile.open(ifName);
    
    if (!iFile.is_open())
        cout << "Error: File did NOT open.";
        
    cout << endl;

    // Process
    
    if(iFile.is_open() && modeStr=="encrypt") {
        
        has_report = true;
        
        oFile.open("message");
        
        while (iFile.get(c)) {
            
            if (c=='A' || c=='a')
                freqA++;
            if (c=='E' || c=='e')
                freqE++;
            if (c=='I' || c=='i')
                freqI++;
            if (c=='O' || c=='o')
                freqO++;
            if (c=='U' || c=='u')
                freqU++;
            if (c=='Y' || c=='y')
                freqY++;
            
            
            //if (isalpha(c))
            c = c + 3;
            
            cout << c;
            
            oFile << c;
            
            
        }
        
        iFile.close();
        oFile.close();
        
        cout << endl;
        
    }
    
    
    if(iFile.is_open() && modeStr=="decrypt") {
        
        has_report = true;
        
        oFile.open("message");
        
        while (iFile.get(c)) {
            
            if (c=='A' || c=='a')
                freqA++;
            if (c=='E' || c=='e')
                freqE++;
            if (c=='I' || c=='i')
                freqI++;
            if (c=='O' || c=='o')
                freqO++;
            if (c=='U' || c=='u')
                freqU++;
            if (c=='Y' || c=='y')
                freqY++;
            
            
            //if (isalpha(c))
            c = c - 3;
            
            cout << c;
            
            oFile << c;
        }
        
        iFile.close();
        oFile.close();
        
        cout << endl;
        
    }
    
    
    
    
    //Output
    
    if (has_report) {
        
        cout << "\nLetter Frequency\n";
        
        cout << right << setfill(' ')
            << setw(4) << "A"
            << setw(7) << freqA << endl;
        
        cout << right << setfill(' ')
            << setw(4) << "E"
            << setw(7) << freqE << endl;
        
        cout << right << setfill(' ')
            << setw(4) << "I"
            << setw(7) << freqI << endl;
        
        cout << right << setfill(' ')
            << setw(4) << "O"
            << setw(7) << freqO << endl;
        
        cout << right << setfill(' ')
            << setw(4) << "U"
            << setw(7) << freqU << endl;
        
        cout << right << setfill(' ')
            << setw(4) << "Y"
            << setw(7) << freqY << endl;

    }
    
    
    return 0;
}
