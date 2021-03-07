#include <bits/stdc++.h>
using namespace std;
#ifdef IHAVETOPEE
#include "debug.h"
#else
#define debug(args...)
#endif

// #pragma GCC target("avx2")
// #pragma GCC optimization("O3")
// #pragma GCC optimization("unroll-loops")

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
    if (a.fi == b.fi)
        return a.se > b.se;
    return a.fi < b.fi;
}
ll n, d;
vector<pll> ms;
int binary(int st)
{
    int low = st, high = n - 1, idx = st;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (abs(ms[mid].fi - ms[st].fi) >= d)
        {
            high = mid - 1;
        }
        else
        {
            idx = mid;
            low = mid + 1;
        }
    }
    return idx;
}
int main()
{
    FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    cin >> n >> d;
    fl(i, 0, n)
    {
        ll u, v;
        cin >> u >> v;
        ms.pb(mp(u, v));
    }
    sort(all(ms), comp);

    ll prefix[n + 10];
    MEM(prefix, 0);
    prefix[0] = 0, prefix[1] = ms[0].se;
    fl(i, 2, n + 1)
    {
        prefix[i] = ms[i - 1].se + prefix[i - 1];
    }

    ll mx = 0;
    // fl(i, 0, n) cout << "=>" << ms[i].fi << sp << ms[i].se << "\n";
    // fl(i, 1, n + 1) cout << prefix[i] << " \n"[i == n];
    for (int i = 0; i < n; i++)
    {
        int st = i, en = binary(i);
        // cout << st << sp << en << nl;
        ll sum = prefix[en + 1] - prefix[st];
        // cout << sum << nl;
        mx = max(mx, sum);
    }
    cout << mx << nl;
    return 0;
}
