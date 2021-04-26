//
//  main.cpp
//  program_42_dice_and_the_gaussian_distribution
//
//  Created by depplenny on 4/25/21.
//

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

class Dice {
private:
    int upside;
public:
    Dice() {
        upside = 1;
    }

    void setUpside(int i) {
        upside = i;
    }
    int getUpside() {
        return upside;
    }
    
    void roll() {
        upside = rand() % 6 + 1;
    }
    
};


int main(int argc, const char * argv[]) {
    srand((unsigned int) time(0));
    const int NUM_DICES = 10;
    const int NUM_OUTCOMES = NUM_DICES*6 - NUM_DICES*1 + 1;
    Dice dices[NUM_DICES];
    int total;
    // count[0] is the number of times that total = NUM_DICES*1
    int counts[NUM_OUTCOMES]= {0};
    int N;
    
    
    cout << "Enter the number of times that you want ot roll 10 dices: ";
    cin >> N;
    
    
    for (int n = 0; n < N; n++) {
        // roll 10 dices and record the total of 10 upsides of dices
        total = 0;
        for (int i = 0; i < NUM_DICES; i++) {
            dices[i].roll();
            total += dices[i].getUpside();
        }
        
        
        for (int j = 0; j < 51; j++) {
            if(total == j + 10) {
                counts[j]++;
            }
        }
    }
    
    
    for (int i = 0; i < NUM_OUTCOMES; i++) {
        cout << NUM_DICES*1 + i << ": ";
        cout << setw(counts[i]) << setfill('*') << "" << endl;
    }
    
    

    
    return 0;
}
