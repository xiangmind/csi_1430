//Author: Xiang Zhao
//Assignment Title:  C string
//Assignment Description:
//  functions with c string
//Due Date: 3/26/2021
//Date Created: 3/25/2021
//Date Last Modified: 3/25/2021





int Strlen(const char s1[]) {
    int n = 0;
    while (s1[n]) n++;
    return n;
}


void Strcpy(char s1[], const char s2[]) {
    int n = Strlen(s2);
    for (int i = 0; i<n; i++) {
        s1[i] = s2[i];
    }
    s1[n] = '\0';
}


int Strcmp(const char s1[ ], const char s2[ ]) {
    int n = Strlen(s1);
    int m = Strlen(s2);
    int len = (n < m) ? n : m;

    int ret = 0;
    for (int i = 0; i < len; i++) {
        if (s1[i] != s2[i]) {
            if (s1[i] > s2[i])
                ret = 1;
            else
                ret = -1;
        }
    }
    
    return ret;
}



void Strcat(char s1[ ], const char s2[ ]) {
    int n = Strlen(s1);
    int m = Strlen(s2);
    
    for (int i = 0; i < m; i++) {
        s1[n+i] = s2[i];
    }
    s1[n+m] = '\0';
    
}
