#include <iostream>

using namespace std;


int main() {
    int q;
    cin>>q;
    for(int each = 0; each < q; each++) {
        string s = "";
        cin>>s;
        string head, tail;
        head.assign(s, 0, 5);
        tail.assign(s.end()-2, s.end());
        int type = 0;
        if(tail == "ic") {
            type = 1;
            if(head == "hydro") {
                type = 2;
            }
        }
        switch (type) {
            case 0:
                cout<<"not an acid"<<endl;
                break;
            case 1:
                cout<<"polyatomic acid"<<endl;
                break;
            case 2:
                cout<<"non-metal acid"<<endl;
                break;
            default:
                break;
        }
    }
    return 0;
}

