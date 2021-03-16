//Author: Xiang Zhao
//Assignment Title:  Encryption square
//Assignment Description:
//  Encode a message by disordering it
//Due Date: 3/12/2021
//Date Created: 3/12/2021
//Date Last Modified: 3/12/2021
//Data Abstraction:
//  string  int enum
//Input:
//  a message to be encoded
//Process:
//  put the message into a 2d array
//  then extract the infomation in
//  a clockwise expanding square spiral from
//  the center of the matrix.
//Output:
//  The encodes message
//Assumptions:
//  It is assumed that, having been prompted to do so, the user will
//  correctly input data



#include <iostream>
#include <string>
#include <cmath>



using namespace std;



int main () {
   
    
    string s;
    string code;
    int N;
    int ci, cj;
    int numEncodedChars=0;
    int numSteps=0;
    int stepSize=1;
    enum  direction {Right, Down, Left, Up};
    direction dir = Right;
    
    getline(cin, s);
    int strLen = static_cast<int>(s.size());
    
    N = sqrt(strLen);

    
    
    if (N*N < strLen)
        N+=1;
    
    if (N % 2 == 0)
        N+=1;

    char message[N][N];
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            
            if (i*N+j < strLen)
                message[i][j] = s[i*N+j];
            else
                message[i][j] = '*';
            
        }
    }
    
    /*
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << message[i][j]  << " ";
        }
        cout << endl;
    }
    cout << endl;
    */
    
    
    ci = N/2;
    cj = N/2;


    // Start point
    code+=message[ci][cj];
    numEncodedChars++;

    while (numEncodedChars < N*N) {
        if (stepSize==numSteps) {
            dir = static_cast<direction>((dir+1) % 4);
            numSteps=0;
        }
        if (ci==cj && ci!=N/2)
            stepSize++;
        
        if (dir == Right)
            cj++;
        if (dir == Down)
            ci++;
        if (dir == Left)
            cj--;
        if (dir == Up)
            ci--;
        
        code+=message[ci][cj];
        numEncodedChars++;
        numSteps++;
    }
    
    
    cout << code << endl;
    
    
}
