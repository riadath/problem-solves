
#include <bits/stdc++.h>
using namespace std;
int n;
int flag[50][5];
long long dp[50][5];

long long f(long long i,int pc)
{

    if(i == n)
        return 1;

    if(flag[i][pc] == 1)
        return dp[i][pc];

    long long a = 0,b = 0,c = 0;
    if(pc!=1)
        a = f(i+1,1);
    if(pc!=2 && i < n-1)
    {
        if(pc == 1)
            b = f(i+2,3);
        if(pc == 3)
            b = f(i+2,1);
    }
    if(pc!=3)
        c = f(i+1,3);

    dp[i][pc] = a+b+c;
    flag[i][pc] = 1;
    return dp[i][pc];
}

int main()
{
    while(scanf("%d",&n) == 1)
    {
        long long flags = f(0,0);
        printf("%lld\n",flags);
        for(int i = 0; i < 50; i++)
        {
            for(int j = 0; j < 5; j++)
                flag[i][j] = 0;
        }
    }

    return 0;
}























