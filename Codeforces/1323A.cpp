#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int arr[n];
        bool flag = false;
        for(int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        for(int i = 0; i < n; i++)
        {
            if(arr[i]%2==0)
            {
                cout<<1<<endl;
                cout<<i+1<<endl;
                flag = true;
                break;
            }
        }
        int num_odds = 0,odds[5];

        if(!flag)
        {
            for(int i = 0; i < n; i++)
            {
                if(arr[i]%2==1)
                {
                    odds[num_odds++] = i+1;
                }
                if(num_odds == 2)
                {
                    cout<<2<<endl;
                    cout<<odds[0]<<" "<<odds[1]<<endl;
                    flag = true;
                    break;
                }
            }
        }
        if(!flag)
        {
            cout<<-1<<endl;
        }
    }
    return 0;
}






