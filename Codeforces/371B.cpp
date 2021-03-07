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
ll acnt[10], bcnt[10];
int main()
{
    FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ll a, b;
    cin >> a >> b;
    ll ta = a, tb = b;
    ll arr[] = {2, 3, 5};
    fl(i, 0, 3)
    {
        if (ta % arr[i] == 0)
        {
            while (ta % arr[i] == 0)
                acnt[arr[i]]++, ta /= arr[i];
        }
        if (tb % arr[i] == 0)
        {
            while (tb % arr[i] == 0)
                bcnt[arr[i]]++, tb /= arr[i];
        }
    }
    if (ta != tb)
    {
        cout << -1 << nl;
    }
    else
    {
        int ans = abs(acnt[2] - bcnt[2]) + abs(acnt[3] - bcnt[3]) + abs(acnt[5] - bcnt[5]);
        cout << ans << nl;
    }
    return 0;
}
