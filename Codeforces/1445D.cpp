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
ll mod = 998244353;
ll GCD(ll a, ll b, ll &x, ll &y)
{
    if (a == 0)
    {
        x = 0, y = 1;
        return a;
    }
    ll x1, y1;
    ll gcd = GCD(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}

ll iverse(ll a, ll mod)
{
    ll x, y;
    ll gcd = GCD(a, mod, x, y);
    return (ll)(x % mod + mod) % mod;
}
int main()
{
    FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    /**
     * The Iverse function finds the modular multiplicative
     * inverse of a mod m.
     */
    ll sum = 0, n, fact = 1, nicher = 1;
    cin >> n;
    int arr[2 * n + 100];
    fl(i, 0, 2 * n) cin >> arr[i];
    sort(arr, arr + 2 * n);
    fl(i, n, 2 * n) sum += arr[i];
    fl(i, 0, n) sum -= arr[i];
    sum = sum % mod;
    fl(i, 1, 2 * n + 1) fact = (fact * i) % mod;
    fl(i, 1, n + 1) nicher = (nicher * i) % mod;
    fl(i, 1, n + 1) nicher = (nicher * i) % mod;
    // cout << sum << nl;
    nicher = iverse(nicher, mod);
    ll ans = (fact * nicher) % mod;
    // cout << "---->" << ans << nl;
    ll final = (ans * sum) % mod;
    cout << final % mod << nl;
    return 0;
}
