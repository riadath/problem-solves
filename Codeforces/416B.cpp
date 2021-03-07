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
bool comp2(const tuple<int, int, int> &a, const tuple<int, int, int> &b)
{
    if (get<1>(a) == get<1>(b))
    {
        return get<0>(a) < get<0>(b);
    }
    return get<1>(a) > get<1>(b);
}

int main()
{
    FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int n, k, gcnt = 0, mcnt = 0;
    cin >> n;
    vector<tuple<int, int, int>> guest;
    vector<pii> table;
    fl(i, 0, n)
    {
        int x, y;
        cin >> x >> y;
        guest.pb(make_tuple(x, y, i + 1));
    }
    cin >> k;
    fl(i, 0, k)
    {
        int x;
        cin >> x;
        table.pb(mp(x, i + 1));
    }
    sort(all(guest), comp2);
    sort(all(table), comp);
    // fl(i, 0, n) cout << "=>" << get<0>(guest[i]) << sp << get<1>(guest[i]) << sp << get<2>(guest[i]) << nl;
    // fl(i, 0, k) cout << "->" << table[i].fi << sp << table[i].se << nl;
    vector<pii> ans;
    fl(i, 0, n)
    {
        fl(j, 0, k)
        {
            if (table[j].fi != -1)
                if (table[j].fi >= get<0>(guest[i]))
                {
                    gcnt += 1, mcnt += get<1>(guest[i]);
                    ans.pb(mp(get<2>(guest[i]), table[j].se));
                    table[j].fi = -1;
                    break;
                }
        }
    }
    cout << gcnt << sp << mcnt << nl;
    fl(i, 0, ans.size())
    {
        cout << ans[i].fi << sp << ans[i].se << nl;
    }
    return 0;
}
