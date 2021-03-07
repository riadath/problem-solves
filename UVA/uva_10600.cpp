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

bool comp(const pair<pii, int> &a, const pair<pii, int> &b)
{
    return a.se < b.se;
}

vector<pair<pii, int>> edges;
map<pii, bool> mn_ed;
int parent[200];
int n, m, mins;
int find(int u)
{
    if (parent[u] == u)
        return u;
    else
        return find(parent[u]);
}
int kruskal(int frs)
{
    vector<pii> taken;
    fl(i, 0, n + 1) parent[i] = i;
    int cnt = 0, ret = 0;
    // cout << "----------------------------\n";
    fl(i, 0, edges.size())
    {
        int u = edges[i].fi.fi;
        int v = edges[i].fi.se;
        int pru = u, prv = v;
        u = find(u);
        v = find(v);
        if (u != v)
        {
            taken.pb(mp(pru, prv));
            if (frs)
            {
                mn_ed[mp(pru, prv)] = true;
            }
            // cout << pru << sp << prv << sp << edges[i].se << nl;
            ret += edges[i].se;
            parent[u] = v;
            cnt++;
            if (cnt == n - 1)
                break;
        }
    }
    bool flag = true;
    if (frs == 0)
    {
        fl(i, 0, taken.size()) if (!mn_ed[taken[i]])
        {
            flag = false;
            break;
        }
    }
    if (frs == 0 && flag)
        ret = 1e8;
    // cout << "----------------------------\n";
    return ret;
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
        cin >> n >> m;
        fl(i, 0, m)
        {
            int u, v, w;
            cin >> u >> v >> w;
            edges.pb(mp(mp(u, v), w));
        }
        sort(all(edges), comp);
        //finding first minimum
        mins = kruskal(1);
        // cout << "CUR::" << mins << nl;

        int second_min = 1e8;
        vector<pair<pii, int>> temp = edges;
        fl(i, 0, edges.size())
        {
            edges[i].se = 1e8;
            sort(all(edges), comp);
            int temp_min = kruskal(0);
            // cout << "CUR::" << temp_min << nl;
            if (temp_min < 1e6)
                second_min = min(temp_min, second_min);
            edges = temp;
        }
        cout << mins << sp << second_min << nl;

        //clear
        edges.clear();
        mn_ed.clear();
    }
    return 0;
}
