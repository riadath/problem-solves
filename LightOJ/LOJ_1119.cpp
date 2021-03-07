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
int arr[20][20], n, lim;
int dp[20000];
int f(int bt)
{
    // cout << bt << nl;
    if (bt == lim)
        return 0;
    int &ret = dp[bt];
    if (ret != -1)
        return ret;
    ll costp = 1e8, cost1 = 0;
    for (int ii = 0; ii < n; ii++)
    {
        if (!(bt & (1 << ii)))
        {
            cost1 = 0;
            // cout << "# " << ii << nl;
            for (int jj = 0; jj < n; jj++)
            {
                if (bt & (1 << jj))
                    cost1 += arr[ii][jj];
            }
            costp = min(costp, cost1 + arr[ii][ii] + f((bt | (1 << ii))));
        }
    }
    return ret = costp;
}
int main()
{
    FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T, kas = 1;
    // scanf("%d", &T);
    cin >> T;
    while (T--)
    {
        MEM(dp, -1);
        cin >> n; // scanf("%d", &n);
        lim = pow(2, n) - 1;
        fl(i, 0, n)
        {
            fl(j, 0, n) cin >> arr[i][j]; //scanf("%d", &arr[i][j]);
        }

        cout << "Case " << kas++ << ": ";
        cout << f(0) << nl;
    }
    return 0;
}
