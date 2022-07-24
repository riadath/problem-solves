#include <bits/stdc++.h>
using namespace std;

#ifdef IHAVETOPEE
#include "debug.h"
#else
#define debug(args)
#endif

#define ll long long
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define lcm(a, b) a *b / __gcd(a, b)
#define MEM(x, y) memset(x, y, sizeof(x))
#define PI acos(0)*2
#define fi first
#define se second
#define all(a) a.begin(), a.end()


int main()
{
    FIO;
    #ifdef IHAVETOPEE 
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    int T;cin>>T;
    while(T--){
        int n,m;cin>>n>>m;
        vector<pll>arr;
        vector<ll>cnt(n + 1,0);
        vector<ll>fren[n + 1];
        vector<ll>weight(n + 1,0);
        for (int i = 0; i < n; i++)
        {
            int t;cin>>t;
            weight[i + 1] = t;
            arr.pb({t,i + 1});
        }
        sort(all(arr));
        for (int i = 0; i < m; i++)
        {
            int x,y;
            cin>>x>>y;
            cnt[x]++,cnt[y]++;
            fren[x].pb(y),fren[y].pb(x);
        }
        if(!(m%2)){
            cout<<0<<"\n";
            continue;
        }
        ll cur_mn = 1e12;
        for (int i = 0; i < (int)arr.size(); i++)
        {
            // cout<<arr[i].se<<"   weight : "<<arr[i].fi<<"  count : "<<cnt[arr[i].se]<<"\n";
            if(cnt[arr[i].se]%2){
                cur_mn = min(cur_mn,arr[i].fi);
            }
        }
        
        ll sum = 0,mn_w = 0;

        for (int i = 0; i < n; i++)
        {
            mn_w = 0;
            mn_w += arr[i].fi;
            for(int j = 0;j < fren[arr[i].se].size();j++){
                if((cnt[fren[arr[i].se][j]])%2 == 0){
                    cur_mn = min(cur_mn,mn_w + weight[fren[arr[i].se][j]]);
                }
            }
        }
        
        cout<<cur_mn<<"\n";     
        
    }

    return 0;
}

/*
sum += cnt[arr[i].se];
mn_w += arr[i].fi;
if(sum >= n)break;



sum += cnt[arr[i].se];
mn_w += arr[i].fi;
if(sum >= n || sum%2 == 1){
    break;
}
for(int j = 0;j < fren[arr[i].se].size();j++)cnt[fren[arr[i].se][j]]--;
*/