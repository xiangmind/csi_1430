

#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;


void print(ostream& os, const vector<vector<int>>& grid) {
    for (size_t i = 0; i < grid.size(); i++) {
        for (size_t j = 0; j < grid[i].size(); j++) {
            os << grid[i][j] << " ";
            if (j==2 || j==5)
                os << " ";
        }
        os << endl;
        if (i==2 || i==5)
            os << endl;
    }   
    cout << endl;
}


// check if key exits in v
bool linearSearch(vector<int>& v, int key) {
    bool ret = false;
    for (size_t i = 0; i < v.size(); i++) {
        if (v[i] == key)
            ret = true;
    }
    return ret;

}


vector<int> slice(const vector<vector<int>>& grid, int iMin, int iMax, int jMin, int jMax) {
    vector<int> box;
    for (int i = iMin; i <= iMax; i++) {
        for (int j = jMin; j <= jMax; j++) {
            box.push_back(grid[i][j]);
        }
    }
    return box;
}


vector<int> getBox(const vector<vector<int>>& grid, int ci, int cj) {
    vector<int> box;

    if ( 0 <= ci && ci <= 2 && 0 <= cj && cj<= 2)
        box = slice(grid, 0, 2, 0, 2);

    if ( 0 <= ci && ci <= 2 && 3 <= cj && cj<= 5)
        box = slice(grid, 0, 2, 3, 5);

    if ( 0 <= ci && ci <= 2 && 6 <= cj && cj<= 8)
        box = slice(grid, 0, 2, 6, 8);

    if ( 3 <= ci && ci <= 5 && 0 <= cj && cj<= 2)
        box = slice(grid, 3, 5, 0, 2);

    if ( 3 <= ci && ci <= 5 && 3 <= cj && cj<= 5)
        box = slice(grid, 3, 5, 3, 5);

    if ( 3 <= ci && ci <= 5 && 6 <= cj && cj<= 8)
        box = slice(grid, 3, 5, 6, 8);

    if ( 6 <= ci && ci <= 8 && 0 <= cj && cj<= 2)
        box = slice(grid, 6, 8, 0, 2);

    if ( 6 <= ci && ci <= 8 && 3 <= cj && cj<= 5)
        box = slice(grid, 6, 8, 3, 5);

    if ( 6 <= ci && ci <= 8 && 6 <= cj && cj<= 8)
        box = slice(grid, 6, 8, 6, 8);

    return box;
}


//Each cell may contain a number from one to nine, 
//and each number can only occur once in each row, column, and box
bool isValidGuess(const vector<vector<int>>& solution, int ci, int cj, int guess) {
    bool ret;
    vector<int> row, col, box;
    
    row = solution[ci];
    
    for (size_t i = 0; i < solution.size(); i++) {
        col.push_back(solution[i][cj]);
    }

    box = getBox(solution, ci, cj);

    ret = !linearSearch(row, guess);
    ret = ret && !linearSearch(col, guess);
    ret = ret && !linearSearch(box, guess);

    return ret;
}


// Check if it is a initial zero of the puzzle
bool isEmpty(const vector<vector<int>>& puzzle, int i, int j) {
    bool ret = false;
    if (puzzle[i][j] == 0)
        ret = true;
    return ret;
}


// Find the next initial zero cell
void forward(const vector<vector<int>>& puzzle, int i, int j, int& ni, int& nj) {
    //cout << "* forward" << endl;
    if (j == 8) {
        ni = i + 1;
        nj = 0;
    }
    else {
        ni = i;
        nj = j + 1;
    }

    while (!isEmpty(puzzle, ni, nj)) {
        if (nj == 8) {
            ni = ni + 1;
            nj = 0;
        }
        else {
            nj = nj + 1;
        }
    }
}


// Find the previous initial zero cell
void backward(const vector<vector<int>>& puzzle, int i, int j, int& pi, int& pj) {
    //cout << "* backward" << endl;
    if (j == 0) {
        pi = i - 1;
        pj = 8;
    }
    else {
        pi = i;
        pj = j - 1;
    }

    while (!isEmpty(puzzle, pi, pj)) {
        if (pj == 0) {
            pi = pi - 1;
            pj = 8;
        }
        else {
            pj = pj - 1;
        }
    }
}



// Return wheather i j is the last 0 of the puzzle
bool isLastStep(const vector<vector<int>>& puzzle, int i, int j) {
    bool ret = false;
    int lastI = 8, lastJ = 8;
    int lastINew = 8, lastJNew = 8;

    if (!isEmpty(puzzle, lastI, lastJ)) {
        backward(puzzle, lastI, lastJ, lastINew, lastJNew);
    }

    if(i==lastINew && j==lastJNew)
        ret = true;

    return ret;
}


// return the minimal valid guess at position i j, 
// if none return -1
int makeGuess(const vector<vector<int>>& solution, int i, int j) {
    int guess;
    guess = solution[i][j] + 1;
    
    while(guess<=9) {
        if(isValidGuess(solution, i, j, guess) ) {
            break;
        }
        guess++;
    }

    if (guess == 10)
        guess = -1;

    return guess;
}


// Backtracking solving algorithm
// Given a puzzle and the first 0's position, this func returns the solved puzzle i.e. solution
vector<vector<int>> backtracking(const vector<vector<int>>& puzzle, int i, int j) {
    cout << "* Backtracking starts.\n";
    
    vector<vector<int>> solution = puzzle;
    int guess;
    int iCur , jCur, iNew, jNew;

    iCur = i;
    jCur = j;
    while(true) {
        guess = makeGuess(solution, iCur, jCur);

        if (!isLastStep(puzzle, iCur, jCur)) {

            if (guess==-1) {
                solution[iCur][jCur] = 0;
                backward(puzzle, iCur, jCur, iNew, jNew);

            } 
            else {
                solution[iCur][jCur] = guess;
                forward(puzzle, iCur, jCur, iNew, jNew);
            }

        }
        else {
            if (guess==-1) {
                solution[iCur][jCur] = 0;
                backward(puzzle, iCur, jCur, iNew, jNew);
            }
            else {
                cout << "* Backtracking ends.\n";
                solution[iCur][jCur] = guess;
                break;
            }
        }

        iCur = iNew;
        jCur = jNew;
    }

    return solution; 

}


// Make a random seed puzzle as a starting point for backtracking
vector<vector<int>> makeSeed() {
    int a = rand()%9 + 1;
    int b = rand()%9 + 1;
    int c = rand()%9 + 1;
    int d = rand()%9 + 1;

    vector<vector<int>> seedPuzzle
    {
        { a, 0, 0,  0, 0, 0,  0, 0, 0 }, 
        { 0, 0, 0,  0, 0, 0,  0, c, 0 }, 
        { 0, 0, 0,  0, b, 0,  0, 0, 0 },

        { 0, 0, 0,  0, 0, 0,  0, 0, 0 }, 
        { 0, d, 0,  0, 0, 0,  0, 0, 0 }, 
        { 0, 0, 0,  0, 0, 0,  0, 0, 0 },

        { 0, 0, 0,  0, 0, 0,  0, 0, 0 }, 
        { 0, 0, 0,  0, 0, 0,  0, 0, 0 }, 
        { 0, 0, 0,  0, 0, 0,  0, 0, 0 }
    };

    return seedPuzzle;
}


// lvl is approximately the number of 0's of the generated puzzle
vector<vector<int>> makePuzzle (int lvl) {
    cout << "* Making a sudoku puzzle for you.\n";
    
    srand(time(0));
    int i, j;
    const vector<vector<int>> seedPuzzle = makeSeed();
    vector<vector<int>> solution = backtracking(seedPuzzle, 0, 1);

    // randomly erase some cells of solution
    for (int k = 0;  k < lvl; k++) {
        i = rand()%9;
        j = rand()%9;
        solution[i][j] = 0;
    }

    cout << "* Your puzzle is ready.\n";
    cout << "* Your goal is to change each 0 to any number from 1 to 9.\n";
    cout << "* Each number can only occur once in each row, column, and box.\n";
    cout << endl;

    return solution;
}


// Given a puzzle, let human try to solve it by entering <row> <col> <guess> repeatedly
void play(const vector<vector<int>>& puzzle) {
    vector<vector<int>> solution = puzzle;

    stringstream ss;
    string line;
    int ci, cj, guess;

    print(cout, solution);
    cout << "Please enter <row> <col> <guess> or q to quit: ";
    getline(cin, line);
    while(line!="q") {
        ss.clear();
        ss.str(line);
        ss >> ci >> cj >> guess;
        if (!ss.fail()) {
            ci -= 1;
            cj -= 1;
            if (isValidGuess(solution, ci, cj, guess)) {
                cout << ci+1 << " " << cj+1 << " " << guess << " is a valid guess.\n";
                solution[ci][cj] = guess;

                if (isLastStep(puzzle, ci, cj)) {
                    // Divider
                    cout << setw(60) << setfill('=') << "" << endl;
                    print(cout, solution);
                    cout << "Congrats! You win!" << endl;
                    break;
                }
            }
            else {
                cout << ci+1 << " " << cj+1 << " " << guess << " is not a valid guess. Try again.\n";
            }
        }
        else{
            cout << "Error: Undefined input." << endl;
        }

        // Divider
        cout << setw(60) << setfill('=') << "" << endl;

        print(cout, solution);
        cout << "Please enter <row> <col> <guess> or q to quit: ";
        getline(cin, line);
    }
}


// It's not necessary to use this func
int mySum(const vector<int>& vec) {
    int sum = 0;
    for (size_t i = 0; i < vec.size(); i++) {
        sum += vec[i];
    }
    return sum;
}


// It's not necessary to use this func
bool isSolved(const vector<vector<int>>& solution) {
    vector<int> row, col, box;

    for (size_t i = 0; i < solution.size(); i++) {
        row = solution[i];

        if(mySum(row)!=45)
            return false;
    }
    
    for (size_t j = 0; j < solution[0].size(); j++) {
        col.clear();
        for (size_t i = 0; i < solution.size(); i++) {
            col.push_back(solution[i][j]);
        }

        if(mySum(col)!=45)
            return false;
    }

    int i = 0;
    int j = 0;
    while (i<=6 && j<=6) {
        box = getBox(solution, i, j);

        if(mySum(box)!=45)
            return false;

        if (j==6) {
            i += 3;
            j = 0;
        }
        else {
            j += 3;
        }
    }
    
    return true;
}


int main() {
    /*
    vector<vector<int>> puzzle
    {
        { 5, 0, 4,  6, 7, 8,  9, 1, 2 }, 
        { 6, 7, 2,  1, 9, 5,  3, 4, 8 }, 
        { 1, 9, 8,  3, 4, 2,  5, 6, 7 },

        { 8, 5, 9,  7, 6, 1,  4, 2, 3 }, 
        { 4, 2, 6,  8, 5, 3,  7, 9, 1 }, 
        { 7, 1, 3,  9, 2, 4,  8, 5, 6 },

        { 9, 6, 1,  5, 3, 7,  2, 8, 4 }, 
        { 2, 8, 7,  4, 1, 9,  6, 3, 5 }, 
        { 3, 4, 5,  2, 8, 6,  1, 7, 0 }
    };
    */
    srand(time(0));
    vector<vector<int>> puzzle;
    char lvl;

    cout << "* Welcome to play sudoku developed by Xiang Zhao.\n";
    cout << "* Please choose the diffculty level first.\n";
    cout << "* Enter e for easy, m for medium, h for hard: ";
    cin >>  lvl;
    cin.ignore(); // ignore'\n'

    if (lvl == 'e')
        puzzle = makePuzzle(5);
    else if (lvl == 'm')
        puzzle = makePuzzle(30); 
    else if (lvl == 'h')
        puzzle = makePuzzle(50);

    play(puzzle);

    return 0;
}



