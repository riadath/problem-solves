#include <bits/stdc++.h>
using namespace std;

// #ifdef IHAVETOPEE
// #include "debug.h"
// #else
// #define debug(args...)
// #endif

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
ll n, tp, c;
bool comp(const pll &a, const pll &b)
{
    if (a.se == b.se)
        return ((a.fi * a.fi) % c) > ((b.fi * b.fi) % c);
    return a.se > b.se;
}

int main()
{
    // FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T, kas = 1;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lld %lld %lld", &n, &tp, &c);
        ll tpc[tp + 10];
        MEM(tpc, 0);
        for (int i = 0; i < n; i++)
        {
            ll x;
            scanf("%lld", &x);
            tpc[x]++;
        }
        vector<pll> arr;
        for (ll i = 1; i <= tp; i++)
        {
            if (tpc[i] != 0)
                arr.pb(mp(i, tpc[i]));
        }
        sort(all(arr), comp);
        ll cur_min = arr[0].se, amuse = (arr[0].fi * arr[0].fi) % c, mx = amuse * cur_min;
        fl(i, 1, (int)arr.size())
        {
            if (arr[i].se == 0)
                continue;
            cur_min = min(cur_min, arr[i].se);
            amuse += ((arr[i].fi * arr[i].fi) % c);
            mx = max(mx, cur_min * amuse);
        }
        printf("Case %d: %lld\n", kas++, mx);
        // cout << amuse * cur_min << nl;
    }
    return 0;
}