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
int dp[100109][2];
int x, y, n, p, k;
string arr;
int f(int i, int pos)
{
    if (i >= n - 1)
    {
        if (i == n - 1)
        {
            if (arr[i] == '0')
                return x;
            else
                return 0;
        }
        return 0;
    }
    if (dp[i][pos] != -1)
        return dp[i][pos];
    int l = INT_MAX, m = l, s = l;
    if (arr[i] == '0')
    {
        if (pos == 1)
        {
            l = y + f(i + 1, 1);
        }
        m = x + f(i + k, 2);
    }
    else
    {
        if (pos == 1)
        {
            m = y + f(i + 1, 1);
        }
        l = f(i + k, 2);
    }
    return dp[i][pos] = min(l, min(m, s));
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
        cin >> n >> p >> k >> arr >> x >> y;
        MEM(dp, -1);
        cout << f(p - 1, 1) << nl;
    }
    return 0;
}
