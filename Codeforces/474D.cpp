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
ll mod = 1e9 + 7;
ll dp[100009];
int main()
{
    FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int t, k;
    cin >> t >> k;
    fl(i, 0, k) dp[i] = 1;
    for (ll i = k; i <= 1e5; i++)
        dp[i] = (dp[i - 1] + dp[i - k]) % mod;
    for (ll i = 1; i <= 1e5; i++)
        dp[i] = (dp[i] + dp[i - 1]) % mod;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;

        ll ans = (dp[b] - dp[a - 1]);
        if (ans < 0)
            ans += mod;
        cout << ans << nl;
    }
    return 0;
}
