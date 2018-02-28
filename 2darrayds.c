#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int arr[6][6];
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            scanf("%d",&arr[i][j]);
        }
    }
    int sum[16];
    int k=0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            sum[k]= arr[i][j] + arr[i][j+1] + arr[i][j+2]
            + arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2]
            + arr[i+1][j+1];
            k++;
        }
    }
    
    int max=sum[0];
    for(int i=0; i<16; i++){
        if(sum[i]>max)
            max=sum[i];
    }
    
    printf("%d\n", max);
    

    return 0;
}


