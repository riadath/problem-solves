#include <bits/stdc++.h>
using namespace std;

// #ifdef IHAVETOPEE
// #include "debug.h"
// #else
// #define debug(args...)
// #endif

#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
int n, arr[200009], LIS[200009], INF[200009];
int LONGEST()
{
    int mx = 0;
    fl(i, 0, n)
    {
        int pos = lower_bound(INF, INF + n + 1, arr[i]) - INF;
        INF[pos] = arr[i], LIS[i] = pos;
        mx = max(mx, pos);
    }
    return mx;
}
int main()
{
    FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    cin >> n;
    fl(i, 0, n) cin >> arr[i];
    INF[0] = -INT_MAX;
    fl(i, 1, n + 1) INF[i] = INT_MAX;
    cout << LONGEST() << nl;
    fl(i, 0, n) cout << LIS[i] << " \n"[i == n - 1];
    return 0;
}