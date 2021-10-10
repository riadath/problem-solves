#include <bits/stdc++.h>
using namespace std;

#ifdef IHAVETOPEE
#include "debug.h"
#else
#define debug(args)
#endif
#define FIO ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);

int n;
string s1,s2;
int dp[100009][5];

int f(int i,int prev){
    if(i >= n){
        return 0;
    }

    int &ret = dp[i][prev];

    if(ret != -1)return ret;

    int a = 0,b = 0,c = 0;

    if(s1[i] != s2[i]){
        a = 2 + f(i + 1,3);
    }
    else{
        if(s1[i] == '0'){
            if(prev == 0 || prev == 1 || prev == 3)a = 1 + f(i+1,3),b = f(i + 1,1);
            if(prev == 2)a = 2 + f(i + 1,3);
        }
        if(s1[i] == '1'){
            if(prev == 0 || prev == 2 || prev == 3)a = f(i + 1,2);
            if(prev == 1)a = 2 + f(i + 1,3);
        }
    }
    ret = max(a,b);
    return ret;

}


int main()
{
    FIO;
    #ifdef IHAVETOPEE 
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    int T;
    cin>>T;
    while(T--){
        memset(dp,-1,sizeof(dp));
        cin>>n>>s1>>s2;
        int ans = f(0,0);
        cout<<ans<<"\n";
    }

    return 0;
}
