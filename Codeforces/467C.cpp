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
    return a.fi < b.fi;
}
ll dp[5001][5001];
ll n, m, k, arr[5001];
ll seg_sum[5001];
ll f(int i, int cnt)
{
    if (i > n - m)
    {
        return (cnt == k) ? 0 : -1e15;
    }
    ll &ret = dp[i][cnt];
    if (ret != -1)
        return ret;
    ll a = -1e18, b = -1e18;
    a = (seg_sum[i + m] - seg_sum[i]) + f(i + m, cnt + 1);
    b = f(i + 1, cnt);
    // debug(a);
    // debug(b);
    return ret = max(a, b);
}
int main()
{
    FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    MEM(dp, -1);
    cin >> n >> m >> k;
    fl(i, 0, n) cin >> arr[i];
    seg_sum[0] = 0;
    fl(i, 1, n + 1)
    {
        seg_sum[i] = seg_sum[i - 1] + arr[i - 1];
    }
    // fl(i, 1, n + 1)
    // {
    //     debug(seg_sum[i]);
    // }
    cout << f(0, 0) << nl;
    return 0;
}
