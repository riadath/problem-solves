#include <bits/stdc++.h>
using namespace std;

#ifdef IHAVETOPEE
#include "debug.h"
#else
#define debug(args)
#endif
#define FIO ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);

#define ll long long
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
        ll n,l,r,k;
        cin>>n>>l>>r>>k;
        ll arr[n + 1];
        for(int i = 0;i < n;i++){
            cin>>arr[i];
        }
        vector<ll>valid;
        for(int i = 0;i < n;i++){
            if(arr[i] >= l && arr[i] <= r)
                valid.push_back(arr[i]);
        }
        sort(valid.begin(),valid.end());
        ll cnt = 0;
        for(int i = 0;i < valid.size();i++){
            if(valid[i] > k)break;
            cnt += 1;
            k -= valid[i];
        }
        debug(valid);
        cout<<cnt<<"\n";
    }
    return 0;
}
