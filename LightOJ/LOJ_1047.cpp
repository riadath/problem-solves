#include <bits/stdc++.h>
using namespace std;
int rgb[25][5];
bool flag[1000][1000];
int dp[1000][1000];
int n;
int f(int p,int q)
{
    if(p == n)
        return 0;
    if(flag[p][q])
        return dp[p][q];
    int a = INT_MAX,b = INT_MAX,c = INT_MAX;
    int temp = INT_MAX;
    if(q != 1)
    {
        a = rgb[p][1] + f(p+1,1);
        temp = min(temp,a);
    }

    if(q != 2)
    {
        b = rgb[p][2] + f(p+1,2);
        temp = min(temp,b);
    }
    if(q != 3)
    {
        c = rgb[p][3] + f(p+1,3);
        temp = min(temp,c);
    }
    dp[p][q] = temp;
    flag[p][q] = true;
    return dp[p][q];

}

int main()
{
    int T;
    scanf("%d",&T);
    for(int kase = 1; kase <= T; kase++)
    {
        scanf("%d",&n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d %d %d",&rgb[i][1],&rgb[i][2],&rgb[i][3]);
        }
        int ans = f(0,0);
        printf("Case %d: %d\n",kase,ans);
        for(int i = 0; i < 1000; i++)
        {
            for(int j = 0; j < 1000; j++)
            {
                dp[i][j] = 0;
                flag[i][j] = false;

            }
        }
    }
    return 0;
}
