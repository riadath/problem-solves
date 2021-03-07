//uva 11517
//every coin can be used exactly once
//iterative solution

#include <bits/stdc++.h>
using namespace std;
int dp[1001][15000];
int coin[1001];
int make,n,prev= INT_MAX;
int f(int i,int amount)
{
    if(amount>=make)
    {
        return amount;
    }
    if(i>=n)
    {
        return INT_MAX;
    }

    if(dp[i][amount] != -1)
        return dp[i][amount];

    int temp = INT_MAX;

    temp = min(f(i+1,amount+coin[i]),f(i+1,amount));

    dp[i][amount] = temp;
    return dp[i][amount];
}


int f1(int amount)
{
    int dp2[amount];
    for(int i = 0;i <= amount;i++)dp2[i] = INT_MAX;
    dp2[0] = 0;
    for(int i = 0;i < n;i++){
        for(int j = amount-coin[i];j>=0;j--){
            if(dp2[j] != INT_MAX){
                dp2[j+coin[i]] = min(dp2[j+coin[i]],dp2[j]+1);
            }
        }
    }
    return dp2[amount];
}

int main()
{
   // freopen("input_file.txt","r",stdin);
    //freopen("output_file.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for (int y = 1;y<=T;y++)
    {
        scanf("%d %d",&make,&n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&coin[i]);
        }
        memset(dp,-1,sizeof(dp));
        int ans = f(0,0);
        int num_coin = f1(ans);
        printf("%d %d\n",ans,num_coin);
    }
    return 0;
}














































