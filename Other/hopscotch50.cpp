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

bool comp(const pii &a, const pii &b)
{
    return a.fi < b.fi;
}


ll arr[59][59];
ll dp[2509][59][59], n, k;

vector<pii> cords[2509];

ll f(int i, int x, int y)
{
    if (i > k)
    {
        return 0;
    }
    ll &ret = dp[i][x][y];
    ll aa = 1e12;

    if (ret != -1)
        return ret;

   
    for (int j = 0; j < cords[i].size(); j++)
    {
        ll dist;

        if(x == -1 || y == -1)dist = 0;
        else dist = abs(cords[i][j].fi - x) + abs(cords[i][j].se - y);

        aa = min(aa, (ll)(dist + f(i + 1, cords[i][j].fi, cords[i][j].se)));
    }
    return ret = aa;
}

int main()
{
    FIO;

#ifdef IHAVETOPEE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    memset(dp, -1, sizeof(dp));

    cin >> n >> k;

    bool flag[k + 1];
    memset(flag, 0, sizeof(flag));
    fl(i, 0, n) fl(j, 0, n)
    {
        cin >> arr[i][j];
        flag[arr[i][j]] = 1;
    }

    bool chk = 1;
    fl(i, 1, k + 1) if (!flag[i])
    {
        chk = 0;
        break;
    }

    if (!chk)
    {
        cout << -1 << "\n";
        return 0;
    }
    fl(i, 0, n) fl(j, 0, n)
    {
        cords[arr[i][j]].pb(mp(i, j));
    }

    fl(i,1,k+1){

        debug(cords[i]);
    }

    ll ans = f(1, -1,-1);
    cout << ans << "\n";
    return 0;
}
