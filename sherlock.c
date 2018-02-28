#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

char* isValid(char* s){
    char* result=(char *)malloc(4 * sizeof(char));
    int n=strlen(s);
    int repeat[50001];
    int k=-1, i, j;
    
    int* same=(int *)malloc(n * sizeof(int));
    for(int i=0; i<n; i++){
        same[i]=1;
    }
    
    for(i=0; i<n; i++){
        if(same[i]){
            k++;
            repeat[k]=1;
            for(j=i+1; j<n; j++){
                if(s[j]==s[i]){
                    same[j]=0;
                    repeat[k]++;
                }
            }
        } else
            continue;
    }
    
    int repeat2[k];
    
    for(i=0; i<=k; i++)
        same[i]=1;
    
    int c=-1;
    for(i=0; i<=k; i++){
        if(same[i]){
            c++;
            repeat2[c]=1;
            for(j=i+1; j<=k; j++){
                if(repeat[j]==repeat[i]){
                    same[j]=0;
                    repeat2[c]++;
                }
            }
        } else
            continue;
    }

    strcpy(result, "NO");
    
    if (c==0)
        strcpy(result, "YES");
    if (c==1 && repeat2[1]==1){
        for (i=1; i<=k; i++)
            if (repeat[i]!=repeat[0])
                break;
        if ((repeat[i]-repeat[0]==1) || repeat[i]==1)
            strcpy(result, "YES");
    }
    if (c==1 && repeat2[0]==1){
        if ((repeat[i]-repeat[0]==1) || repeat[i]==1)
            strcpy(result, "YES");
    }
    
    return result;
}

int main() {
    char* s = (char *)malloc(100001 * sizeof(char));
    scanf("%s", s);
    char* result = isValid(s);
    printf("%s\n", result);
    return 0;
}
