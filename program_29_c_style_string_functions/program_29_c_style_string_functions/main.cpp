//
//  main.cpp
//  program_29_c_style_string_functions
//
//  Created by depplenny on 3/25/21.
//

#include <iostream>
#include "Cstring.h"

using namespace std;

int main(int argc, const char * argv[]) {
    char s1[100] = "xiang";
    char s2[100] = "zhao";
    
    cout << "s1[0]:\n";
    cout << s1[0] << endl;
    
    cout << "Strlrn():\n";
    cout << Strlen(s1) << endl;
    
    Strcpy(s1, "xiang sadfasd ");
    cout << "Strcpy():\n";
    cout << s1 << endl;
    
    cout << "Strcmp():\n";
    cout << Strcmp("123a", "123bhhh") << endl;
    
    
    Strcat(s1,s2);
    cout << "Strcat():\n";
    cout << s1 << endl;
    
    
    return 0;
}
