#include <bits/stdc++.h>
using namespace std;
#ifdef IHAVETOPEE
#include "debug.h"
#else
#define debug(args...)
#endif

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

int main()
{
    FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        ll n, g, b, gd, bd, ans = 0;
        cin >> n >> g >> b;
        if (g >= n)
        {
            cout << n << nl;
            continue;
        }
        gd = n / 2 + (n % 2 != 0);
        bd = n / 2;
        if (g >= gd)
        {
            ans += g;
            if (b >= n - g)
                ans += n - g;
            else
            {
                ans += b;
                ans += max(oll, n - g - b);
            }
            cout << ans << nl;
            continue;
        }
        if (g < b)
        {
            ll gcy = gd / g; // bcy = bd / b;
            ans += gcy * (g + b) + max(oll, n - gcy * (g + b));
            ans += max(oll, (gd - max(oll, n - gcy * (g + b))) - gcy * g);
            if (g * gcy >= gd)
            {
                ans -= b;
                ans += max(oll, (bd - (gcy - 1) * b));
            }
            cout << ans << nl;
        }
        else
        {
            cout << n << nl;
        }
    }
    return 0;
}
