//
//  main.cpp
//  34 week
//
//  Created by Cao Trong Duy Nhan on 7/18/17.
//  Copyright © 2017 Duy Nhan Cao. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>


using namespace std;

void subarray(vector<int> arr, int x, int y, int n){
    vector<int> freq_sum(2*n+1, 0);
    
    bool check=false;
    int subArrNum=0;
    int sum_i=0;
    freq_sum[n]++;
    
    for(int i=0; i<n; i++){
        if(arr[i]==x || arr[i]==y)
            check=true;
        if (arr[i]==x)
            sum_i++;
        if (arr[i]==y)
            sum_i--;
        freq_sum[sum_i+n]++;
    }
    
    if(check==false)
        cout << n*(n+1)/2 << endl;
    else {
        for(int i=0; i<=2*n; i++){
            subArrNum += freq_sum[i]*(freq_sum[i]-1)/2;
        }
        
        cout << subArrNum << endl;
    }
    
    
}

int main() {
    int n;
    int q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
        cin >> arr[arr_i];
    }
    for(int a0 = 0; a0 < q; a0++){
        int x;
        int y;
        cin >> x >> y;
        if(x-y==0)
            cout << n*(n+1)/2 << endl;
        else
            subarray(arr, x, y, n);
    }
    return 0;
}


