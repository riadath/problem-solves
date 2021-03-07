#include <bits/stdc++.h>
using namespace std;
int coin[60];
int take[60];
long long dp[100][1012];
int n,k;
int m = 100000007;
long long f(int i,int amount)
{

    if(i>=n)
    {
        if(amount == 0)return 1;
        else return 0;
    }

    if(dp[i][amount] != -1)
        return dp[i][amount];

    long long a = 0;
    for(int l = 0; l <= 5; l++)
    {
        if(amount-l*coin[i] >= 0)
            a = a + f(i+1,amount-l*coin[i])%m;
    }
    dp[i][amount] = a;
    return dp[i][amount]  ;
}


int main()
{
    int T;
    scanf("%d",&T);

    for(int kase = 1; kase <= T; kase++)
    {
        memset(dp,-1,sizeof(dp));

        scanf("%d %d",&n,&k);
        for(int i = 0; i < n; i++)
            scanf("%d",&coin[i]);
        for(int i = 0; i < n; i++)
            scanf("%d",&take[i]);
        long long ans = f(0,k)%m;
        printf("Case %d: %lld\n",kase,ans);
    }
    return 0;
}

























