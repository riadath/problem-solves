#include <bits/stdc++.h>
using namespace std;

#ifdef IHAVETOPEE
#include "debug.h"
#else
#define debug(args)
#endif
#define FIO ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);

#define ll long long

bool comp(const pair<ll,ll> &a,const pair<ll,ll> &b){
    return a.first < b.first;
}

int main()
{
    FIO;
    #ifdef IHAVETOPEE 
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    int T;cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        vector<pair<ll,ll>>arr,brr;
        for(int i = 0;i < n*m;i++){
            ll x;cin>>x;
            arr.push_back(make_pair(x,i+1));
        }
        brr = arr;
        sort(arr.begin(),arr.end());
        debug(arr);
        for(int i = 0;i < n*m - 1;i++){
            if(arr[i].first == arr[i+1].first){
                int en = i,st = i;
                while(true){
                    if(arr[en].first == arr[en+1].first)en++;
                    else break;
                }
                debug(st);
                debug(en);
                for(int j = st,k = en;j <= (en+st)/2;j++,k--){
                    // debug(j);
                    // debug(k);
                    swap(arr[j],arr[k]);
                }
                i = en;
            }
        }
        map<pair<ll,ll>,int>idx;
        for(int i = 0;i < n*m;i++)idx[arr[i]] = i;
        debug(arr);
        debug(brr);
        debug(idx);
        
        int ans = 0,occu[n*m + 9];
        memset(occu,0,sizeof(occu));

        for(int i = 0;i < n*m;i++){
            int sit = idx[brr[i]],cnt = 0;
            for(int j = 0;j < sit;j++)cnt += occu[j];
            occu[sit] = 1;
            ans += cnt;
        }
        cout<<ans<<"\n";

    }
    return 0;
}
