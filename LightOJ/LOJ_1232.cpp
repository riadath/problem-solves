#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input_file.txt","r",stdin);
    //freopen("output_file.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int kase = 1; kase <=T; kase++)
    {
        int n,k;
        int mod = 100000007;
        long long dp[10010];
        long long coin[105];
        scanf("%d %d",&k,&n);
        int i,j;
        for(i = 0; i < k; i++)
            scanf("%lld",&coin[i]);
        for(int i = 0; i <= n; i++)
            dp[i] = 0;
        dp[0] = 1;
        for(i = 0; i < k; i++)
        {
            for(j = coin[i]; j <= n; j++)
            {
                dp[j] += dp[j-coin[i]];
                dp[j] %= mod;
            }
        }
        printf("Case %d: %lld\n",kase,dp[n]);
    }
    return 0;
}




























































