#include <bits/stdc++.h>
using namespace std;
int coin[] = {1,5,10,25,50};
long long dp[6][10000];
int n;

long long f(int i,int amount)
{
    if(i>=5)
    {
        if(amount == 0){
            //cout<<i<<"   "<<amount<<endl;
            return 1;
        }
        else return 0;
    }
    if(dp[i][amount] != -1)
        return dp[i][amount];

    long long a = 0,b = 0;
    if(amount-coin[i]>=0)
        a = f(i,amount-coin[i]);
    b = f(i+1,amount);

    dp[i][amount] = a+b;
    return dp[i][amount];

}

int main()
{

    memset(dp,-1,sizeof(dp));
    while(scanf("%d",&n)==1)
    {
        long long ans = f(0,n);
        printf("%lld\n",ans);
    }
    return 0;
}
























