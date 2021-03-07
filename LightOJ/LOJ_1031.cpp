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
int n, arr[200], sum;
int dp[109][109][2];

int f(int i, int j, int turn)
{
    if (i > j)
        return 0;
    int &ret = dp[i][j][turn];
    if (ret != -1)
        return ret;

    int pp = -1e8, ssm = 0, sign, tret;
    if (turn == 2)
        pp = 1e8;
    if (turn == 1)
        sign = 1, tret = 2;
    else
        sign = -1, tret = 1;
    int pl = 1;
    for (int p = i; p <= j; p++)
    {
        ssm += sign * arr[p];
        if (turn == 1)
            pp = max(pp, ssm + f(i + pl, j, tret));
        else
            pp = min(pp, ssm + f(i + pl, j, tret));
        pl += 1;
    }
    ssm = 0, pl = 1;
    for (int p = j; p >= i; p--)
    {
        ssm += sign * arr[p];
        if (turn == 1)
            pp = max(pp, ssm + f(i, j - pl, tret));
        else
            pp = min(pp, ssm + f(i, j - pl, tret));
        pl += 1;
    }
    return ret = pp;
}
int main()
{
    FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T, kas = 1;
    cin >> T;
    while (T--)
    {
        MEM(dp, -1);
        sum = 0;
        cin >> n;
        fl(i, 0, n) cin >> arr[i], sum += arr[i];
        int mxa = f(0, n - 1, 1);
        cout << "Case " << kas++ << ": ";
        cout << mxa << nl;
    }
    return 0;
}
