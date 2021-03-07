#include <bits/stdc++.h>
using namespace std;

// #ifdef IHAVETOPEE
// #include "debug.h"
// #else
// #define debug(args...)
// #endif

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
int dp[200][200];
string str;
int f(int i, int j)
{
    if (i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (str[i] == str[j])
    {
        return dp[i][j] = f(i + 1, j - 1);
    }
    else
    {
        int mn1, mn2;
        mn1 = 1 + f(i + 1, j);
        mn2 = 1 + f(i, j - 1);
        return dp[i][j] = min(mn1, mn2);
    }
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
        MEM(dp, -1);
        cin >> str;
        printf("Case %d: ", kas++);
        cout << f(0, str.size() - 1) << nl;
    }
    return 0;
}
