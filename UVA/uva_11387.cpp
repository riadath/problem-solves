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
    return a.se < b.se;
}

int main()
{
    FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int n;
    while (cin >> n && n != 0)
    {
        vector<int> graph[n + 10];
        vector<pii> res;
        fl(i, 1, n + 1)
        {
            vector<pii> nodes;
            fl(i, 1, n + 1) nodes.pb(mp(i, graph[i].size()));
            sort(all(nodes), comp);
            for (int l = 1, k = 0; l <= n && (int)graph[i].size() < 3; l++)
            {
                int j = nodes[l - 1].fi;
                if (i == j)
                    continue;
                if (graph[j].size() < 3)
                {
                    graph[i].pb(j);
                    graph[j].pb(i);
                    res.pb(mp(i, j));
                }
            }
        }
        bool flag = true;
        fl(i, 1, n + 1) if (graph[i].size() != 3)
        {
            flag = false;
        }
        if (!flag)
            cout << "Impossible" << nl;
        else
        {
            cout << res.size() << nl;
            fl(i, 0, res.size()) cout << res[i].fi << sp << res[i].se << nl;
        }
    }
    return 0;
}