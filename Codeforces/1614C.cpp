#include <bits/stdc++.h>
using namespace std;

#ifdef IHAVETOPEE
#include "debug.h"
#else
#define debug(args)
#endif
#define FIO ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);

#define ll long long



ll mod = 1000000007;

int main()
{
    FIO;
    #ifdef IHAVETOPEE 
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    
    int T;cin>>T;
    while(T--){
        vector<ll>arr;
        ll m,n,cur_mx = -1;
        cin>>n>>m;

        for(int i = 0;i < m;i++){
            ll l,r,x;
            cin>>l>>r>>x;
            arr.push_back(x);
        }
        ll sum = 0;
        for(int i = 0;i < arr.size();i++){
            debug(arr[i]);
            sum = (sum | arr[i]);
        }
        debug(sum);
        ll mult = 1;
        for(int i = 0;i < n-1;i++)mult = (mult * 2LL)%mod;
        sum = (sum * mult)%mod;

        cout<<sum<<"\n";
    }
    return 0;
}
