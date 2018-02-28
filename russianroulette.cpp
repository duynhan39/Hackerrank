#include <iostream>
using namespace std;

int main() {
    int n, count = 0, op = 0, total=0;
    cin>>n;
    for(int i = 0; i < n; i++) {
        int in;
        cin>>in;
        if(in == 0) {
            op += (count+1)/2;
            count = 0;
        } else {
            count++;
            total++;
        }
    }
    op += (count+1)/2;
    cout<<op<<" "<<total<<endl;
    return 0;
}
