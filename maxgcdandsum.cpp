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

int maximumGcdAndSum(vector <int> A, vector <int> B, int n) {
    int maxGcd=max(A[n-1], B[n-1]);
    int ans_A, ans_B;
    
    vector<int> freq_A(maxGcd + 1, 0);
    vector<int> freq_B(maxGcd + 1, 0);
    
    for(int i=0; i<n; i++){
        freq_A[A[i]]++;
        freq_B[B[i]]++;
    }
    maxGcd=min(A[n-1], B[n-1]);
    
    for(int i=maxGcd; i>0; i--){
        ans_A=0;
        ans_B=0;
        
        int j=i;
        while(j<=A[n-1]){
            if(freq_A[j]!=0)
                ans_A=j;
            j+=i;
        }
        j=i;
        while(j<=B[n-1]){
            if(freq_B[j]!=0)
                ans_B=j;
            j+=i;
        }
        if(ans_A!=0 && ans_B!=0)
            break;
    }
    return ans_A + ans_B;
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for(int A_i = 0; A_i < n; A_i++){
        cin >> A[A_i];
    }
    sort(A.begin(), A.end());
    vector<int> B(n);
    for(int B_i = 0; B_i < n; B_i++){
        cin >> B[B_i];
    }
    sort(B.begin(), B.end());
    
    int res = maximumGcdAndSum(A, B, n);
    cout << res << endl;
    return 0;
}


