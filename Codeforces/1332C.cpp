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
        char a[n];
        scanf("%s",a);
        int moves = 0;
        int lc[k][26];
        memset(lc,0,sizeof(lc));
        for(int i = 0; i < n; i++)
        {
            lc[i%k][a[i]-'a']++;
        }
        if(k%2==1)
        {
            for(int i = 0; i < k/2; i++)
            {
                int t = k-i-1;
                int mx = 0,s = 0;
                for(int j = 0; j < 26; j++)
                {
                    mx = max(mx,lc[i][j]+lc[t][j]);
                }
                moves += ((2*(n/k))-mx);
            }
            moves += (n/k - *max_element(lc[k/2],lc[k/2]+26));
        }
        else
        {
            for(int i = 0; i < k/2; i++)
            {
                int t = k-i-1;
                int mx = 0,s = 0;
                for(int j = 0; j < 26; j++)
                {
                    mx = max(mx,lc[i][j]+lc[t][j]);
                }
                moves += ((2*(n/k))-mx);

            }
        }
        cout<<moves<<endl;
    }
    return 0;
}











