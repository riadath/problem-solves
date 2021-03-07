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
        ll n, l, r, a = 1, b = 0;
        vector<pll> wb;
        cin >> n >> l >> r;
        fl(i, 0, n)
        {
            ll p, q;
            cin >> p >> q;
            if (p % 2 == 0)
                a = 2;
            wb.pb(mp(p, q));
        }
        b = wb[n - 1].se;
        ll cur = 1;
        lf(i, n - 2, 0)
        {
            if (wb[i + 1].fi % 2 == 0)
                cur = 2;
            if ((cur * wb[i].se) % 2 != b % 2)
                b = 1;
            else
                b = 2;
        }

        ll fr, sed = a;
        if ((a * l) % 2 != b % 2)
            fr = 1;
        else
            fr = 2;
        // cout << fr << sp << sed << nl;
        if (fr % 2 == 0 && sed % 2 == 0)
            cout << r - l + 1 << sp << 0 << nl;
        else if (fr % 2 == 1 && sed % 2 == 0)
            cout << 0 << sp << r - l + 1 << nl;
        else if (fr % 2 == 0 && sed % 2 == 1)
        {
            ll pr1 = (r - l) / 2, pr2 = (r - l) / 2 + ((r - l) % 2 != 0);
            cout << pr1 + 1 << sp << pr2 << nl;
        }
        else
        {
            cout << (r - l + 1) / 2 << sp << (r - l + 1) / 2 + ((r - l + 1) % 2 != 0) << nl;
        }
    }
    return 0;
}