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
string str;
int dp[200009][5][2];
int f(int i, int rem, int flag)
{
    // cout << rem << nl;
    if (i >= (int)str.size())
        return (rem == 0 && flag);
    if (dp[i][rem][flag] != -1)
        return dp[i][rem][flag];
    int a = 0, b = 0;
    // if (i != (int)str.size() - 1)
    a = f(i + 1, (rem + str[i] - '0') % 3, 1);
    b = (rem == 0 && flag) + f(i + 1, (str[i] - '0') % 3, 1);
    return dp[i][rem][flag] = max(a, b);
}
int main()
{
    FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    cin >> str;
    MEM(dp, -1);
    cout << f(0, 0, 0) << nl;
    return 0;
}
