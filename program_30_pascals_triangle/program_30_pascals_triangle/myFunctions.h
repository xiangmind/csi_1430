//Author: Xiang Zhao
//Assignment Title:  My Functions
//Assignment Description:
//  Learn how to define functions in seperate files in cpp
//Due Date: 3/26/2021
//Date Created: 3/25/2021
//Date Last Modified: 3/25/2021
//Data Abstraction:
//  int double array
//Input:
//  int double array
//Process:
//  find the min max absoluteValue
//  factorial combination permutation
//Output:
//  the min max absoluteValue
//  factorial combination permutation
//Assumptions:
//  It is assumed that, having been prompted to do so, the user will
//  correctly input data

#ifndef myFunctions_h
#define myFunctions_h


/*
 * description: Function returns the value of the larger of two.
 * return: int
 * precondition: two int values exist
 * postcondition: The value of the larger int is returned.
 *   The original doubles are unchanged
 *   If the doubles have the same value
 *   then the value of either double is returned.
 *
 */
int max (int m, int n);

/*
 * description: Function returns the value of the larger of two.
 * return: double
 * precondition: two double values exist
 * postcondition: The value of the larger double is returned.
 *   The original doubles are unchanged
 *   If the doubles have the same value
 *   then the value of either double is returned.
 *
 */
double max (double m, double n);

/*
 * description: Function returns the value of the largest
 * return: int
 * precondition: an array of integer values exist
 * postcondition:
 *   The largest value in the array is returned.
 *   The original array is unchanged
 *
 */
int max (const int m[], int n);



/*
 * description: Function returns the value of the largest
 * return: double
 * precondition: an array of double values exist
 * postcondition:
 *   The largest value in the array is returned.
 *   The original array is unchanged
 *
 */
double max (const double m[], int n);





/*
 * description: Function returns the value of the smallest
 * return: double
 * precondition: an array of double values exist
 * postcondition:
 *   The largest value in the array is returned.
 *   The original array is unchanged
 *
 */
int min (int m, int n);

/*
 * description: Function returns the value of the smallest
 * return: double
 * precondition: an array of double values exist
 * postcondition:
 *   The largest value in the array is returned.
 *   The original array is unchanged
 *
 */
double min (double m, double n);

/*
 * description: Function returns the value of the smallest
 * return: double
 * precondition: an array of double values exist
 * postcondition:
 *   The largest value in the array is returned.
 *   The original array is unchanged
 *
 */
int min (const int m[], int n);

/*
 * description: Function returns the value of the smallest
 * return: double
 * precondition: an array of double values exist
 * postcondition:
 *   The largest value in the array is returned.
 *   The original array is unchanged
 *
 */
double min (const double m[], int n);




/*
 * description:
 *   This function returns the absolute value of an integer
 * return: double
 * precondition: an array of double values exist
 * postcondition:
 *   The largest value in the array is returned.
 *   The original array is unchanged
 *
 */
int absoluteValue (int m);

/*
 * description:
 *   This function returns the absolute value of an double
 * return: double
 * precondition: an array of double values exist
 * postcondition:
 *   The largest value in the array is returned.
 *   The original array is unchanged
 *
 */
double absoluteValue (double m);

/*
 * precondition:
 *   Some integer value N exists
 * postcondition:
 *   The value of the N unchanged
 * return:
 *   double
 * description:
 *   The function calculates factorial.
 */
double factorial(int m);



/*
 * description:
 *   The function calculates the number of
 *   combinations of M items taken N at a time.
 * return:
 *   double
 * precondition:
 *   an array of double values exist
 * postcondition:
 *   The largest value in the array is returned.
 *   The original array is unchanged
 *
 */
double combination( int M, int N);




/*
 * description:
 *   The function calculates the number of
 *   permutations of M items taken N at a time.
 * return:
 *   double
 * precondition:
 *   an array of double values exist
 * postcondition:
 *   The largest value in the array is returned.
 *   The original array is unchanged
 *
 */
double permutation( int M, int N);






#endif /* myFunctions_h */
