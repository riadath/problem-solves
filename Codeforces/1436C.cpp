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
    return a.fi < b.fi;
}
ll mod = 1e9 + 7;
ll fact(ll n)
{
    ll ret = 1;
    fl(i, 1, n + 1)
    {
        ret = (ret * i) % mod;
    }
    return ret;
}
int main()
{
    FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int n, x, pos;
    cin >> n >> x >> pos;
    vector<int> perm;
    int lo = 0, hi = n;
    int chk = pos, sm_c = 0, big_c = 0;
    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        if (mid > chk)
        {
            hi = mid;
            perm.pb(+1);
            big_c++;
        }
        else if (mid <= chk)
        {
            lo = mid + 1;
            if (lo - 1 == pos)
                continue;
            perm.pb(-1);
            sm_c++;
        }
    }
    ll ans = 1;
    int smol = (x - 1), big = n - x;
    if (smol < sm_c || big < big_c)
    {
        cout << 0 << nl;
        return 0;
    }
    fl(i, 0, perm.size())
    {
        // cout << perm[i] << nl;
        if (perm[i] == 1)
            ans = (ans * big--) % mod;

        else
            ans = (ans * smol--) % mod;
    }
    // cout << ans << nl;
    ans = (ans * fact(max(0, smol + big))) % mod;
    cout << ans << nl;
    return 0;
}
