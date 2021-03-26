//Author: Xiang Zhao
//Assignment Title:  C string
//Assignment Description:
//  functions with c string
//Due Date: 3/26/2021
//Date Created: 3/25/2021
//Date Last Modified: 3/25/2021


#ifndef Cstring_h
#define Cstring_h








/*
 * Description:
 *   Find the length of a c string.
 * Return:
 *   int
 * Precondition:
 *   c string
 * Postcondition:
 *   the length of a c string.
 *
 */
int Strlen(const char s1[]);




/*
 * Description:
 *   Copy c string s2 to c string s1
 *   make sure char array s1's size >= s2
 * Return:
 *   void
 * Precondition:
 *   c string
 * Postcondition:
 *   copied c string
 *
 */
void Strcpy(char s1[], const char s2[]);


/*
 * Description:
 *   compare s1 and s2
 *   if the first character that does not match
 *   has a greater value in s1 than in s2;
 * Return:
 *   int, 0: equal, 1: s1 > s2, -1: s1 < s2
 * Precondition:
 *   c string
 * Postcondition:
 *   c string, int result
 *
 */
int Strcmp(const char s1[ ], const char s2[ ]);

/*
 * Description:
 *   concatenate s2 to s1
 * Return:
 *   total string
 * Precondition:
 *   two c string
 * Postcondition:
 *   1 c string concatenated with the otehr, 1 cstring intact
 *
 */
void Strcat(char s1[ ], const char s2[ ]);


#endif /* Cstring_h */
