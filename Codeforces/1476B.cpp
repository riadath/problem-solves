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
        ll n, per;
        cin >> n >> per;
        ll arr[n + 1];
        fl(i, 0, n) cin >> arr[i];
        ll lo = 0, hi = 1e9 * 500, mn = 5e12;
        while (lo <= hi)
        {
            ll mid = (lo + hi) / 2;
            ll cur = mid;
            bool flag = 1;
            fl(i, 1, n)
            {
                db temp = arr[i] * 1.0;
                temp /= cur;
                temp *= 100.0;
                if (temp - (db)per > 0.000000000001)
                {
                    flag = 0;
                    break;
                }
                cur += arr[i];
            }
            // debug(mid);
            // debug(flag);
            if (flag)
            {
                mn = min(mn, mid);
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }
        cout << max(oll, mn - arr[0]) << nl;
    }
    return 0;
}
