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
        int n;
        ll x;
        cin >> n >> x;
        vector<pll> arr;
        fl(i, 0, n)
        {
            ll x;
            cin >> x;
            arr.pb(mp(x, 1));
        }
        fl(i, 0, arr.size())
        {

            if (arr[i].fi % x == 0)
            {
                ll pp = arr[i].fi;
                arr.pb(mp(pp / x, arr[i].se * x));
                pp /= x;
            }
            else
                break;
        }
        ll sum = 0;
        // fl(i, 0, arr.size())
        // {
        //     fl(j, 0, arr[i].se) cout << arr[i].fi << sp;
        // }
        // cout << nl;
        fl(i, 0, arr.size())
        {
            // debug(arr[i]);
            sum += (arr[i].fi * arr[i].se);
        }
        cout << sum << nl;
    }
    return 0;
}
