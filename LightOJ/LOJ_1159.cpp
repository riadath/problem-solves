#include <bits/stdc++.h>
using namespace std;

#ifdef IHAVETOPEE
#include "debug.h"
#else
#define debug(args)
#endif
#define FIO ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);

string str1,str2,str3;  
int n1,n2,n3;

int dp[51][51][51];

int f(int l1,int l2,int l3)
{
    if(l1 >= n1 || l2 >= n2 || l3 >= n3)return 0;
    int &ret = dp[l1][l2][l3];

    if(ret != -1)return ret;
    int ans = 0;
     
    if(str1[l1] == str2[l2] && str2[l2] == str3[l3]){
        ans = 1 + f(l1 + 1,l2 + 1,l3 + 1);  
    }
    else{
        int a = f(l1 + 1,l2,l3);
        int b = f(l1,l2 + 1,l3);
        int c = f(l1,l2,l3 + 1);
        ans = max(a,max(b,c));
    }
   
    debug(ans);
    ret = ans;
    return ret;
}

int main()
{
    FIO;
    #ifdef IHAVETOPEE 
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    int T,kase;
    cin>>T;
    for(kase = 1;kase <= T;kase++){
        memset(dp,-1,sizeof(dp));
        cin>>str1>>str2>>str3;
        n1 = str1.size(),n2 = str2.size(),n3 = str3.size();
        printf("Case %d: ",kase);
        printf("%d\n",f(0,0,0));
    }

    return 0;
}
