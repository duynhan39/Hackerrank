#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main ()
{
    int  h, w;
    cin>>h>>w;
    vector<vector<int>> toy(h);
    int total=2*h*w;
    //vector<int> line(w);
    for(int i=0; i<h; i++)
    {
        int num;
        cin>>num;
        toy[i].push_back(num);
        total+=toy[i][0];
        for(int j=1; j<w; j++)
        {
            cin>>num;
            toy[i].push_back(num);
            total+=abs(toy[i][j]-toy[i][j-1]);
        }
        total+=toy[i][w-1];
    }
    for(int i=0; i<w; i++)
    {
        total+=toy[0][i];
        for(int j=1; j<h; j++)
        {
            total+=abs(toy[j][i]-toy[j-1][i]);
        }
        total+=toy[h-1][i];
    }
    cout<<total<<endl;
    return 0;
}
