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

int main()
{
    FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ll a, b;
    cin >> a >> b;
    string aa, bb;
    while (a != 0)
    {
        aa.pb('0' + a % 2);
        a /= 2;
    }
    while (b != 0)
    {
        bb.pb('0' + b % 2);
        b /= 2;
    }
    reverse(all(aa)), reverse(all(bb));
    // debug(aa);
    // debug(bb);
    // debug(aa.size());
    if (aa == bb)
        cout << 0 << nl;
    else if ((int)aa.size() < (int)bb.size())
    {
        ll ans = 1;
        fl(i, 0, bb.size()) ans *= 2;
        cout << ans - 1 << nl;
    }
    else
    {
        ll st = 0;
        fl(i, 0, aa.size())
        {
            if (aa[st] == bb[st])
            {
                st++;
            }
            else
            {
                break;
            }
        }
        // debug(st);
        ll cnt = (bb.size() - st), ans = 1;
        fl(i, 0, cnt) ans *= 2;
        cout << ans - 1 << nl;
    }
    return 0;
}
