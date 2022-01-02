#include <bits/stdc++.h>
using namespace std;
#ifdef IHAVETOPEE
#include "debug.h"
#else
#define debug(args)
#endif

long long oll = 0;
#define ll long long
#define ull unsigned long long
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define pb push_back
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define lcm(a, b) a *b / __gcd(a, b)
#define fl(i, a, b) for (ll i = (int)a; i < (int)b; i++)
#define lf(i, b, a) for (ll i = (int)b; i >= (int)a; i--)
#define MEM(x, y) memset(x, y, sizeof(x))
#define mp make_pair
#define bs(x, y) binary_search(x.begin(), x.end(), y)
#define nl "\n"
#define sp " "
#define srt(x) sort(x.begin(), x.end())
#define pi 3.141592653589793238
#define db double
#define fi first
#define se second
#define pi4 pair<pii, pii>
#define all(a) a.begin(), a.end()

bool comp(const pii &a, const pii &b)
{
    return a.fi < b.fi;
}

int main()
{
    FIO;
    #ifdef IHAVETOPEE 
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    int T;
    cin >> T;
    while (T--)
    {
        ll m,n;cin>>m>>n;
        ll arr[m + 1][n + 1];   
        fl(i,0,m)fl(j,0,n){
            cin>>arr[i][j];
        }
        vector<ll>mxs;
        fl(i,0,n){
            ll mn = 0;
            fl(j,0,m){
                // debug(j);debug(i);
                // debug(arr[j][i]);
                mn = max(mn,arr[j][i]);
            }
            mxs.pb(mn);
        }
        debug(mxs);
        ll ans = -1e12;
        fl(i,0,m){
            vector<pll>tmp;
            fl(j,0,n)tmp.pb(mp(arr[i][j],j));
            sort(all(tmp),comp);
            debug(tmp);
            ll tmn = 1e12;
            bool flag[n + 1];
            MEM(flag,0);

            fl(j,0,n-2){
                debug(tmp[j].se);
                debug(mxs[tmp[j].se]);
                tmn = min(tmn,mxs[tmp[j].se]);
                flag[tmp[j].se] = 1;
            }
            fl(j,0,n){
                if(!flag[j])tmn = min(tmn,arr[i][j]);
            }
            debug(tmn);
            ans = max(ans,tmn);
        }
        cout<<ans<<"\n";
    }
    return 0;
}