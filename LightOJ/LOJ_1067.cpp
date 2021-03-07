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
ll mod = 1000003;

int GCD(int a, int b, int &x, int &y)
{
    if (a == 0)
    {
        x = 0, y = 1;
        return a;
    }
    int x1, y1;
    int gcd = GCD(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}

ll iverse(int a)
{
    int x, y;
    int gcd = GCD(a, mod, x, y);
    return (ll)(x % mod + mod) % mod;
}
ll miverse[1000109];
ll facto[1000109];

int main()
{
    // FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    facto[0] = 1;
    fl(i, 1, mod + 10)
    {
        miverse[i] = iverse(i);
        facto[i] = (facto[i - 1] * i) % mod;
    }

    int T, kas = 1;
    scanf("%d", &T);
    while (T--)
    {
        ll n, k, fact = 1;
        scanf("%lld %lld", &n, &k);
        fact = ((fact * facto[n]) % mod * (miverse[(facto[k] * facto[n - k]) % mod])) % mod;
        printf("Case %d: ", kas++);
        printf("%lld\n", fact);
    }
    return 0;
}
