//Author: Xiang Zhao
//Assignment Title:  Array Count
//Assignment Description:
//  Count a value in the array/vector for different data type
//Due Date: 3/26/2021
//Date Created: 3/25/2021
//Date Last Modified: 3/25/2021
//Data Abstraction:
//  int double char string array vector
//Input:
//  int double char string array vector
//Process:
//  Count a value in the array/vector for different data type
//Output:
//  frequency
//Assumptions:
//  It is assumed that, having been prompted to do so, the user will
//  correctly input data



#ifndef arrayCount_h
#define arrayCount_h

#include <string>
#include <vector>

using namespace std;



/*
 * Description:
 *   Find the frequency of the value v in the array a.
 *
 * Return:
 *   int
 * Precondition:
 *   int array a, int s, int v
 * Postcondition:
 *   The frequency of the value v in the array a.
 *
 */
int arrayCount(int a[], int s, int v);




/*
 * Description:
 *   Find the frequency of the value v in the array a.
 *
 * Return:
 *   int
 * Precondition:
 *   double array a, int s, double v
 * Postcondition:
 *   The frequency of the value v in the array a.
 *
 */
int arrayCount(double a[], int s, double v);


/*
 * Description:
 *   Find the frequency of the value v in the array a.
 *
 * Return:
 *   int
 * Precondition:
 *   string array a, int s, string v
 * Postcondition:
 *   The frequency of the value v in the array a.
 *
 */
int arrayCount(string a[], int s, string v);



/*
 * Description:
 *   Find the frequency of the value v in the array a.
 *
 * Return:
 *   int
 * Precondition:
 *   char array a, char v
 * Postcondition:
 *   The frequency of the value v in the array a.
 *
 */
int arrayCount(char a[], char v);





/*
 * Description:
 *   Find the frequency of the value v in the array a.
 *
 * Return:
 *   int
 * Precondition:
 *   char array a, char v
 * Postcondition:
 *   The frequency of the value v in the array a.
 *
 */
int arrayCount(char a[], char v);


/*
 * Description:
 *   Find the frequency of the value v in the array a.
 *
 * Return:
 *   int
 * Precondition:
 *   int vector a, int v
 * Postcondition:
 *   The frequency of the value v in the array a.
 *
 */
int arrayCount(vector<int> a, int v);


/*
 * Description:
 *   Find the frequency of the value v in the array a.
 *
 * Return:
 *   int
 * Precondition:
 *   string vector a, int v
 * Postcondition:
 *   The frequency of the value v in the array a.
 *
 */
int arrayCount(vector<string> a, string v);

/*
 * Description:
 *   Find the frequency of the value v in the array a.
 *
 * Return:
 *   int
 * Precondition:
 *   double vector a, int v
 * Postcondition:
 *   The frequency of the value v in the array a.
 *
 */
int arrayCount(vector<double> a, double v);

/*
 * Description:
 *   Find the frequency of the value v in the array a.
 *
 * Return:
 *   int
 * Precondition:
 *   char vector a, int v
 * Postcondition:
 *   The frequency of the value v in the array a.
 *
 */
int arrayCount(vector<char> a, char v);


#endif /* arrayCount_h */



