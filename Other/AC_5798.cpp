
#include <bits/stdc++.h>
using namespace std;
char arr[101][101];
int h,w;
int dp[101][101][2];
int f(int i,int j,int p)
{
    if(i >= h || j >= w)
        return INT_MAX;

    int cost;
    if(arr[i][j] == '#' && p == 1)
        cost = 1;
    else cost = 0;

    if(i == h-1 && j == w-1)
    {
        return cost;
    }

    if(dp[i][j][p] != -1)
        return dp[i][j][p];


    int a,b;
    if(arr[i][j] == '.')
    {
        a = f(i+1,j,1);
        b = f(i,j+1,1);
        dp[i][j][p] = min(a,b);

    }
    else
    {
        a = f(i+1,j,0);
        b = f(i,j+1,0);
        dp[i][j][p] = cost+min(a,b);
    }
    return dp[i][j][p];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp,-1,sizeof(dp));
    cin>>h>>w;
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            cin>>arr[i][j];
        }
    }
    int ans = f(0,0,1);
    cout<<ans<<"\n";
    return 0;
}



















