#include <bits/stdc++.h>
using namespace std;

#ifdef IHAVETOPEE
#include "debug.h"
#else
#define debug(args)
#endif

// #pragma GCC target("avx2")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
        ll k, mx = 0, mn = 1e12, cur_dist = 0,st = 0, mex = n + 1;
        map<ll, bool> arr;
        vector<ll> brr;
        cin >> n >> k;
        fl(i, 0, n)
        {
            ll x;
            cin >> x;
            brr.pb(x);
            mx = max(mx, x);
            mn = min(mn, x);
            if (!arr[x])
                cur_dist++, arr[x] = true;
        }
        sort(all(brr));
        fl(i, 0, n)
        {
            if (brr[i] != st)
            {
                mex = st;
                break;
            }
            else
                st++;
        }
        if (mn == 0 && mx == n-1)
        {
            cout << n + k << nl;
            continue;
        }
        // debug(mex);
        ll newEl = (mex + mx) / 2LL + (mex + mx) % 2LL;
        if (!arr[newEl] && k > 0)
            cout << cur_dist + 1 << nl;
        else
            cout << cur_dist << nl;
    }
    return 0;
}