//Author: Xiang Zhao
//Assignment Title:  C String
//Assignment Description:
//  manipulate c string (char array)
//  tokenization by iterating thorugh the array
//Due Date: 3/12/2021
//Date Created: 3/11/2021
//Date Last Modified: 3/11/2021
//Data Abstraction:
//  char array string int bool vector ifstream
//Input:
//  txt file contains string seperated by comma
//Process:
//  open the file, read line by line, tokenize each line,
//  *get unique token*
//Output:
//  unique tokens in reverse order
//Assumptions:
//  It is assumed that, having been prompted to do so, the user will
//  correctly input data






#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    char del;
    string nameFile;
    ifstream ifs;
    int chances = 0;
    char line[100];
    vector<string> tokens;
    vector<string> uniqueTokens;

    
    
    
    
    cout << "Enter the character used to delineate tokens: ";
    cin >> del;
    cout << del << endl; //echo
    
    do {
        
        cout << "Enter File Name: ";
        cin >> nameFile;
        cout << nameFile << endl; //echo
        
        ifs.open(nameFile);
        chances++;
        
        if (!ifs.is_open()) {
            cout << "Error: File Not Open." << endl;
        }
        
    } while (!ifs.is_open() && chances <=3);
    
    
    if (ifs.is_open() && chances <=3) {
        
        while(ifs.getline(line, 100)) {
            string token="";
            for (unsigned int i = 0; i < strlen(line); i++) {

                if (line[i]!=del) {
                    token+=line[i];
                }
                else {
                    tokens.push_back(token);
                    token="";
                }
            }
            // For last token
            tokens.push_back(token);

        }
        ifs.close();
        

 
        // Pick the unique tokens
        for (unsigned int i = 0; i < tokens.size(); i++) {
            bool unique = true;
            for (unsigned int j = 0; j < uniqueTokens.size(); j++) {
                if (tokens.at(i)==uniqueTokens.at(j)) {
                    unique = false;
                    break;
                }
            }
            if (unique)
                uniqueTokens.push_back(tokens.at(i));
        }
        
        
        // Output
        for (unsigned int i = 0; i < uniqueTokens.size(); i++) {
            cout << uniqueTokens.at(uniqueTokens.size()-1-i) << endl;
        }
        
    }
    
    
    return 0;
}
