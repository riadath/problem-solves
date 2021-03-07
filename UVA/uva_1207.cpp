#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int len_a,len_b;
string a,b;

int f(int x,int y)
{
    if(x == len_a)return len_b - y;
    if(y == len_b)return len_a - x;

    if(dp[x][y] != - 1)return dp[x][y];

    int p,q,r;
    if(a[x] == b[y]){
        dp[x][y] = f(x+1,y+1);
    }else{

        p = 1 + f(x,y+1);
        q = 1 + f(x+1,y);
        r = 1 + f(x+1,y+1);
        dp[x][y] = min(p,min(q,r));
    }

    return dp[x][y];

}

int main()
{
    while(cin>>len_a>>a>>len_b>>b){
        memset(dp,-1,sizeof(dp));
        int ans = f(0,0);
        cout << ans << "\n";
    }
    return 0;
}


