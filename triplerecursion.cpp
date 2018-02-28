#include <iostream>
using namespace std;

int main() {
    int n, m, k;
    cin>>n>>m>>k;
    for(int i=0; i<n; i++)
    {
        int start=m-i;
        cout<<start;
        for(int j=1; j<=i; j++)
        {
            start+=k+1;
            cout<<" "<<start;
        }
        for(int j=i+1; j<n; j++)
        {
            start--;
            cout<<" "<<start;
            
        }
        cout<<endl;
    }
    return 0;
}
