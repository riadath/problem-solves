#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,k;
        cin>>n>>k;
        if(k == 1)
        {
            for(int i = 0;i < n-2;i++)cout<<"a";
            for(int i = 0;i < 2;i++)cout<<"b";
            cout<<endl;
        }
        else
        {
            int i,j;
            int temp = 0;
            int range = 1;
            for(i = 2,j = 1; i<=k; j++)
            {
                range++;
                temp = i+j;
                if(k >= i && k <=temp)
                    break;
                i = temp+1;
            }
            i = k-i;
            int x1 = n-i-1,x2 = n-range-1;
            for(int l = 0;l < n;l++){
                if(l == x1 || l == x2){
                    cout<<"b";
                    continue;
                }else{
                    cout<<"a";
                }
            }
            cout<<endl;
        }
    }
    return 0;
}
























