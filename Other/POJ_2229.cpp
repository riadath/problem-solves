#include <stdio.h>
int mod = 1000000000;
long long dp[1000010];
int main()
{
    int n;
    scanf("%d",&n);
    int coin[25];
    int i,j;
    for(i = 1,j = 0;i <= n;i = i*2,j++){
        coin[j] = i;
    }
    int num_coins = j;
    dp[0] = 1;
    for(i = 0;i < num_coins;i++){
        for(j = coin[i];j <= n;j++){
            dp[j] += dp[j-coin[i]];
            if(dp[j]>=mod)dp[j] %= mod;
        }
    }
    printf("%lld",dp[n]);
    return 0;
}
