#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin>>T;
    while(T--)
    {
        int n,k;
        cin>>n>>k;
        bool flag = false;;
        if(k > floor(sqrt(n)))flag == false;
        else if(n%2==0 && k%2==0)flag = true;
        else if(n%2==1 && k%2==1)flag = true;
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}

