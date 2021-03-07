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
        ll n, w;
        cin >> n >> w;
        ll lwr = w / 2 + (w % 2 != 0);
        vector<pll> arr;
        vector<ll> items;
        fl(i, 0, n)
        {
            ll x;
            cin >> x;
            if (x <= w)
                arr.pb(mp(x, i + 1));
        }
        if (arr.size() == 0)
        {
            cout << -1 << nl;
            continue;
        }
        sort(all(arr), comp);
        if (arr[arr.size() - 1].fi >= lwr)
        {
            cout << 1 << nl;
            cout << arr[arr.size() - 1].se << nl;
            continue;
        }
        int lw = 0, hi = arr.size() - 1;
        ll sum = 0;
        while (lw <= hi)
        {
            if (sum + arr[hi].fi <= w)
            {
                sum += arr[hi].fi;
                items.pb(arr[hi].se);
                hi--;
                if (sum >= lwr)
                    break;
            }
            else if (sum + arr[lw].fi <= w)
            {
                sum += arr[lw].fi;
                items.pb(arr[lw].se);
                lw++;
                if (sum >= lwr)
                    break;
            }
        }
        if (sum >= lwr)
        {
            cout << items.size() << nl;
            sort(all(items));
            fl(i, 0, items.size()) cout << items[i] << sp;
            cout << nl;
        }
        else
            cout << -1 << nl;
    }
    return 0;
}
