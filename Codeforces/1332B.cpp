
#include <bits/stdc++.h>
using namespace std;
int factor(int x)
{
    for(int i = 2;; i++)
    {
        for(int j = 2; i*j<=x; j++)
        {
            if(i*j==x)
            {
                if(i<j)
                    return i;
                else
                    return j;
            }
        }
    }
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        bool is_col[n];
        memset(is_col,false,sizeof(is_col));
        int what_col[n];
        memset(what_col,0,sizeof(what_col));
        int cur_col = 0;
        for(int i = 0; i < n; i++)
        {
            if(!is_col[i])
            {
                cur_col++;
                is_col[i] = true;
                what_col[i] = cur_col;
                int temp = factor(arr[i]);
                for(int j = i+1; j < n; j++)
                {
                    if(!is_col[j] && (arr[j]%temp==0))
                    {
                        what_col[j] = cur_col;
                        is_col[j] = true;
                    }
                }
            }
        }
        cout<<cur_col<<endl;
        for(int i = 0; i < n; i++)
        {
            cout<<what_col[i]<<" ";
        }
        cout<<endl;

    }
    return 0;
}
