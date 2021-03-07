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
#define SIZE 100009
int n, flag[100109];
double dp[100109];
vector<int> divi[100109];
double f(int i)
{
    if (i == 1)
        return 0.00;
    if (flag[i])
        return dp[i];
    flag[i] = 1;
    double ret = 0.0;
    for (int k = 0; k < (int)divi[i].size(); k++)
    {
        // cout << ":::: " << divi[i][k] << nl;
        ret += (1.0 + 1.0 * f(i / divi[i][k]));
    }
    // cout << "===>" << ret << nl;
    return dp[i] = (ret * 1.0 + 1.0) / ((double)divi[i].size() * 1.0);
}
int main()
{
    // FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    for (int i = 2; i < SIZE; i++)
    {
        for (int j = i; j < SIZE; j += i)
            divi[j].pb(i);
    }
    MEM(flag, 0);
    int T, kas = 1;
    cin >> T;
    while (T--)
    {
        cin >> n;
        cout << "Case " << kas++ << ": ";
        cout << setprecision(10) << f(n) << nl;
    }
    return 0;
}
