#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    string s;
    cin>>s;
    int a = 0,d = 0;
    for(int i = 0;i< s.size();i++){
        if(s[i] == 'A')a++;
        else if(s[i] == 'D')d++;
    }
  //  cout<<a<<"  "<<d<<endl;
    if(a > d)cout<<"Anton";
    else if(d > a)cout<<"Danik";
    else cout<<"Friendship";
    return 0;
}

















