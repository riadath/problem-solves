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
#define pii pair<ll, ll>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define lcm(a, b) a *b / __gcd(a, b)
#define fl(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)
#define lf(i, b, a) for (ll i = (ll)b; i >= (ll)a; i--)
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

bool comp(const pll &a, const pll &b)
{
    return a.se > b.se;
}

int main()
{
    FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        ll n;
        cin>>n;
        vector<vector<ll>>arr(n + 1);
        vector<vector<ll>>csum(n + 1);
        vector<pll>order;
        vector<ll>unis(n);
        fl(i,0,n){
            cin>>unis[i];
        }
        fl(i,0,n){
            ll temp;
            cin>>temp;
            arr[unis[i]].pb(temp);
        }
        
        fl(i,1,n + 1){
            if(arr[i].size() != 0){
                order.pb(mp(i,arr[i].size()));
                sort(all(arr[i]));
                reverse(all(arr[i]));
            }
        }
        sort(all(order),comp);
        fl(i,1,n + 1){
            if(arr[i].size() != 0){
                csum[i].pb(0);
                csum[i][0] = arr[i][0];
                fl(j,1,arr[i].size()){
                    csum[i].pb(0);
                    csum[i][j] = arr[i][j] + csum[i][j-1];
                }
            }
        }
        // fl(i,1,n + 1){
        //     debug(arr[i]);
        // }

        vector<ll>ans(n + 1,0);
        fl(k,1,n + 1){
            ll tot = 0;
            fl(i,0,order.size()){
                ll pp = order[i].se/k;
                if(!pp)break;
                pp *= k;
                tot += csum[order[i].fi][pp - 1];
            }
            ans[k] = tot;
        }
        fl(i,1,n + 1)cout<<ans[i]<<" \n"[i == n];
    }
    return 0;
}
