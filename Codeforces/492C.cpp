#include <bits/stdc++.h>
using namespace std;
#ifdef IHAVETOPEE
#include "debug.h"
#else
#define debug(args...)
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
#define fl(i, a, b) for (ll i = a; i < b; i++)
#define lf(i, b, a) for (ll i = b; i >= a; i--)
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
    if (a.se == b.se)
        return a.fi < b.fi;
    return a.se < b.se;
}

int main()
{
    FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ll n, r, avg, sum = 0;
    cin >> n >> r >> avg;
    vector<pll> arr;
    avg *= n;
    fl(i, 0, n)
    {
        int x, y;
        cin >> x >> y;
        sum += x;
        arr.pb(mp(x, y));
    }
    sort(all(arr), comp);
    ll left = max(oll, avg - sum);
    ll ans = 0;
    fl(i, 0, n)
    {
        if (arr[i].fi < r)
        {
            if (r - arr[i].fi >= left)
            {
                ans += left * arr[i].se;
                left = 0;
            }
            else
                ans += (arr[i].se * (r - arr[i].fi)), left -= (r - arr[i].fi);
        }
        if (left == 0)
            break;
    }
    cout << ans << nl;
    return 0;
}
