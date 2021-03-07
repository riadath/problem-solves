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
        ll n;
        cin >> n;
        if (n == 1)
        {
            cout << 1 << nl;
            continue;
        }
        vector<ll> tw;
        ll st = 2;
        while (st <= n)
        {
            tw.pb(st);
            st *= 2;
        }
        if (tw[tw.size() - 1] == n)
        {
            cout << -1 << nl;
            continue;
        }
        // debug(tw);
        st = 1;
        int idx = 0;
        vector<ll> ans;
        while (st <= n)
        {
            if (tw[idx] == st)
            {
                if (st + 1 > n)
                    break;
                ans.pb(st + 1);
                st += 1;
                if (idx < (int)tw.size() - 1)
                {
                    ans.pb(tw[idx]);
                    idx++;
                }
            }
            else
            {
                ans.pb(st);
            }
            st++;
        }
        ans.pb(tw[tw.size() - 1]);
        swap(ans[0], ans[2]);
        fl(i, 0, ans.size()) cout << ans[i] << sp;
        cout << nl;
        // fl(i, 0, ans.size() - 1)
        // {
        //     int z = ans[i] & ans[i + 1];
        //     if (z > 0)
        //         z = 1;
        //     else
        //         z = 0;
        //     if (z == 0)
        //         cout << z << sp;
        // }
        // cout << nl;
    }
    return 0;
}
