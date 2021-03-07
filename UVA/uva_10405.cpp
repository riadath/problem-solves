#include <bits/stdc++.h>
using namespace std;
string a,b;
int dp[1001][1001];
int f(int i ,int j)
{
    if(i == a.size() || j == b.size())return 0;
    if(dp[i][j] != -1)return dp[i][j];
    int p = 0,q = 0;
    if(a[i] == b[j]){
        dp[i][j] = 1 + f(i+1,j+1);
    }else{
        p = f(i,j+1);
        q = f(i+1,j);
        dp[i][j] = max(p,q);
    }
    return dp[i][j];

}
int main()
{
    //freopen("input_file.txt","r",stdin);
    //freopen("output_file.txt","w",stdout);
    //int i = 1;
    while(getline(cin,a)){
        getline(cin,b);
        memset(dp,-1,sizeof(dp));
        int ans = f(0,0);
        //cout<<"Case "<<i<<": ";
        cout<<ans<<endl;
        //i++;
    }

}

