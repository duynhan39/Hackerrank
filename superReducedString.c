#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char* reduce(char* s){
    int i, check=0;
    int n=strlen(s);
    for(i=0; i< n-1; i++){
        check=0;
        if (s[i+1]==s[i]){
            check=1;
            break;
        }
    }
    if (check){
        for(int j=i; j<n-1; j++)
            s[j]=s[j+2];
        return(reduce(s));
    } else if (strlen(s)==0){
        return "Empty String";
    } else
        return s;
}

int main() {
    char s[100];
    scanf("%s", s);
    printf("%s\n", reduce(s));
    return 0;
}


