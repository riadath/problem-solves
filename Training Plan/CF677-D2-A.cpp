#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    int wid = 0;
    for(int i = 0;i < a;i++){
        int temp;
        cin>>temp;
        if(temp <= b)wid++;
        else wid += 2;
    }
    cout<<wid<<endl;
    return 0;
}
