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
#define srt(x) sort(x.begin(), x.end())
#define pi 3.141592653589793238
#define fi first
#define se second
#define all(a) a.begin(), a.end()



ll n, m;
vector<int> graph[1009];
ll vv[1009],ven[1009];
bool flag_rm[1009];

bool comp(const pll &a, const pll &b)
{
    if(a.se == b.se){
        return ven[a.fi] < ven[b.fi];
    }
    return a.se > b.se;
}
int main()
{
    FIO;
#ifdef IHAVETOPEE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    vector<pll>arr;
    cin >> n >> m;
    fl(i, 1, n + 1) {
        cin >> vv[i];
        arr.push_back(mp(i,vv[i]));
    }

    fl(i, 0, m)
    {
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    fl(i,1,n+1){
        ll tsum = 0;
        fl(j,0,graph[i].size()){
            tsum += vv[graph[i][j]];
        }
        ven[i] = tsum;
    }

    sort(all(arr),comp);
    ll min_en = 0;
    fl(i,0,arr.size()){
        int ii = arr[i].fi;
        min_en += ven[ii];
        fl(k,0,graph[ii].size()){
            int v = graph[ii][k];
            ven[v] -= vv[ii];
        }
    }
    debug(arr);

    cout<<min_en<<"\n";
    return 0;
}
