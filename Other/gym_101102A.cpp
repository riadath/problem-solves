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
ll MOD = 1e9 + 7;
ll n, m, w, k, coin1[200], coin2[200], possible[20000], dp[159][15009], dp2[159][15009];
ll f(int i, int amt)
{
    if (amt == 0)
        return 1;
    if (i >= n)
    {
        // cout << "--->" << amt << nl;
        // possible[amt] = 1;
        return (amt == 0);
    }
    if (dp[i][amt] != -1)
        return dp[i][amt];
    ll a = 0, b = 0;
    a = f(i + 1, amt) % MOD;
    if (amt - coin1[i] >= 0)
        b = f(i + 1, amt - coin1[i]) % MOD;
    return dp[i][amt] = (a + b) % MOD;
}

ll f2(int j, int amt)
{
    // cout << "HERE" << nl;
    // cout << amt << nl;
    if (amt == 0)
        return 1;
    if (j >= m)
    {
        return (amt == 0);
    }
    if (dp2[j][amt] != -1)
        return dp2[j][amt];
    ll a = 0, b = 0;
    a = f2(j + 1, amt) % MOD;
    // cout << amt << sp << coin2[j] << sp << w << nl;
    if (amt - coin2[j] >= 0)
        b = f2(j + 1, amt - coin2[j]) % MOD;
    return dp2[j][amt] = (a + b) % MOD;
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
        MEM(dp, -1), MEM(dp2, -1), MEM(possible, 0);
        cin >> n >> m >> k >> w;
        fl(i, 0, n) cin >> coin1[i];
        fl(i, 0, m) cin >> coin2[i];
        ll ans = 0;
        fl(i, 0, w + 1)
        {
            int s1 = i, s2 = w - i;
            if (abs(s1 - s2) <= k)
            {
                ll cnt1 = f(0, s1);
                ll cnt2 = f2(0, s2);
                ans += (cnt1 * cnt2) % MOD;
            }
        }
        cout << ans % MOD << nl;
    }
    return 0;
}
