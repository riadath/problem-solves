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
int n;
ll arr[109];
bool flag[109];
db dp1[109]; // dp2[109];
db f1(int i)
{
    if (i == n - 1)
    {
        // cout << arr[n - 1] << nl;
        return arr[n - 1];
    }
    if (flag[i])
        return dp1[i];
    db a = 0.00;
    db cnt = 0;
    for (int l = 1; l <= 6; l++)
    {
        if (i + l >= n)
            continue;
        // cout << arr[i] << nl;
        a += arr[i] + f1(i + l);
        cnt++;
    }
    flag[i] = 1;
    return dp1[i] = a / cnt;
}

// ll f2(int i)
// {
//     if (i >= n - 1)
//         return (i == n - 1);
//     if (dp2[i] != -1)
//         return dp2[i];
//     ll a = 0;
//     for (int l = 1; l <= 6; l++)
//     {
//         a += f2(i + l);
//     }
//     return dp2[i] = a;
// }
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
        fl(i, 0, n) scanf("%lld", &arr[i]);
        MEM(flag, 0);
        fl(i, 0, 109) dp1[i] = 0.00;
        printf("Case %d: ", kas++);
        printf("%0.9lf\n", f1(0));
    }
    return 0;
}
