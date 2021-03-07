#include <bits/stdc++.h>
using namespace std;
string s;
int len;
int dp[1001][1001];
int f(int i,int j)
{
    //cout<<i<<"-----"<<j<<endl;
    //cout<<s[i]<<" _____ "<<s[j]<<endl;
    if(i == j) return 0;
    if(i >= len)return 0;
    if(j < 0)return 0;

    if(dp[i][j] != -1)return dp[i][j];
    //cout<<a[i]<<" "<<b[j]<<endl;
    if(s[i] == s[j]){
        dp[i][j] = f(i+1,j-1);
    }else{
        int p,q,r;
        p = 1 + f(i,j-1);
        q = 1 + f(i+1,j-1);
        r = 1 + f(i+1,j);
        dp[i][j] = min(p,min(q,r));
    }
    return dp[i][j];
}

int main()
{
    //freopen("input_file.txt","r",stdin);
    //freopen("output_file.txt","w",stdout);
    int T;
    cin>>T;
    for(int kase = 1;kase<=T;kase++)
    {
        cin>>s;
        len = s.size();
        //cout<<len<<endl;
        memset(dp,-1,sizeof(dp));
        int ans = f(0,len-1);
        printf("Case %d: %d\n",kase,ans);
        s.clear();
    }
    return 0;
}
