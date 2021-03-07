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
int n, k;
bool comp(const pii &a, const pii &b)
{
    int tm = (a.se - a.fi);
    int tp = (b.se - b.fi);
    return tm < tp;
}

int main()
{
    FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ll n, k;
    cin >> n >> k;
    vector<ll> divs;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            divs.pb(i);
            if (i != n / i)
            {
                divs.pb(n / i);
            }
        }
    }
    if (k > divs.size())
    {
        cout << -1 << nl;
        return 0;
    }
    sort(all(divs));
    cout << divs[k - 1] << nl;
    return 0;
}
