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
ll n = 30000, d, dp[30009][500], arr[30009];
ll f(int i, int pr)
{
    // if (arr[i])
    //     cout << i << "---\n";
    if (i > n)
        return 0;
    ll &ret = dp[i][pr + 300];
    if (ret != -1)
        return ret;
    ll a = 0, b = 0, c = 0;
    if (d + pr - 1 > 0)
        b += arr[i] + f(i + d + pr - 1, pr - 1);
    c += arr[i] + f(i + d + pr + 1, pr + 1);
    a += arr[i] + f(i + d + pr, pr);

    // if ((a + b + c))
    //     cout << a << sp << b << sp << c << nl;

    return ret = max(a, max(b, c));
}
int main()
{
    FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    MEM(dp, -1);
    int pp;
    cin >> pp >> d;
    fl(i, 0, pp)
    {
        int x;
        cin >> x;
        arr[x] += 1;
    }
    ll ans = f(d, 0);
    cout << ans << nl;
    return 0;
}
