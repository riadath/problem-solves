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
int n;
pii range[200009];
int arr[200009];
ll dp[400009];
map<int, int> mapping;
set<int> points;
vector<pii> previous[400009];
int main()
{
    FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    cin >> n;
    fl(i, 0, n)
    {
        int a, b;
        cin >> a >> b >> arr[i];
        b++;
        range[i] = (mp(a, b));
        points.insert(a), points.insert(b);
    }
    int st = 1;
    for (int i : points)
    {
        mapping[i] = st++;
    }
    fl(i, 0, n)
    {
        previous[mapping[range[i].se]].pb(mp(mapping[range[i].fi], arr[i]));
    }
    fl(i, 1, st + 1)
    {
        dp[i] = dp[i - 1];
        fl(j, 0, previous[i].size())
        {
            dp[i] = max(dp[i], dp[previous[i][j].fi] + previous[i][j].se);
        }
    }
    cout << dp[st] << nl;
    return 0;
}