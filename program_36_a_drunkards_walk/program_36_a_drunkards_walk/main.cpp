//Author: Xiang Zhao
//Assignment Title:  Drunkards Walk
//Assignment Description:
// Model a brownian motion
//Due Date: 4/16/2021
//Date Created: 4/16/2021
//Date Last Modified: 4/16/2021
//Data Abstraction:
// class Random Walker int
//Input:
//  the number of steps that Drunkards walks
//Process:
//  randomly select a direction to walk till N steps
//Output:
//  the current position, distance walekd
//Assumptions:
//  It is assumed that, having been prompted to do so, the user will
//  correctly input data

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

void walk(int& x, int& y) {
    int dir = rand()%4;
    if(dir == 0)
        y += 1;
    else if (dir == 1)
        x += 1;
    else if (dir == 2)
        y -= 1;
    else if (dir == 3)
        x -= 1;
}

int dist(int x, int y) {
    return x * x + y * y;
}


int main(int argc, const char * argv[]) {
    
    int distSum = 0;
    int N, T;
    int x, y;
    srand(329);
    
    cin >> N >> T;
    cout << "RandomWalkers " << N  << " " << T << endl;
    
    for (int t = 0; t < T; t++) {
        x=0;
        y=0;

        for (int i = 0; i < N; i++ ) {
            walk(x, y);
        }

        distSum += dist(x, y);
    }
    cout << fixed << setprecision(3);
    cout << "mean squared distance = " << double(distSum) / T << endl;

    return 0;
}
