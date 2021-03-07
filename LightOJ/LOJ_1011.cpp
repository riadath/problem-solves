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
int arr[17][17], dp[17][65537], n;
int f(int i, int bt)
{
    if (i >= n)
        return 0;
    if (dp[i][bt] != -1)
        return dp[i][bt];
    int mx = 0;
    // debug(bt);
    fl(k, 0, n)
    {
        if (!(bt & (1 << (n - k))))
        {
            mx = max(mx, arr[i][k] + f(i + 1, (bt | (1 << (n - k)))));
        }
    }
    return dp[i][bt] = mx;
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
        scanf("%d", &n);
        fl(i, 0, n) fl(j, 0, n) scanf("%d", &arr[i][j]);
        MEM(dp, -1);
        printf("Case %d: ", kas++);
        printf("%d\n", f(0, 0));
    }
    return 0;
}
