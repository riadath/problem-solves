#include <bits/stdc++.h>
using namespace std;
int main()
{

    int T;
    cin>>T;
    while(T--)
    {
        string s;
        cin>>s;
        int n = s.size();
        int arr[n];
        int i,j;
        bool is = false;
        arr[0] = 0;
        for(i = 0,j = 1; i < n; i++)
        {
            if(s[i] == 'R')
            {
                is = true;
                arr[j] = i+1;
                j++;
            }
        }
        arr[j] = n+1;
        int diff = 0;
            for(i = 0; i < j; i++)
            {
                if(arr[i+1] - arr[i] > diff)
                {
                    diff = arr[i+1]-arr[i];
                }
            }
        cout<<diff<<endl;
    }
    return 0;
}











