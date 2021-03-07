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
bool valid[500009];
bool visited[500009];
vector<int> graph[201009];
map<int, vector<int>> digg;
int bfs(int sr)
{
    int cnt = 1;
    vector<int> vyrevy;
    vyrevy.pb(sr);
    visited[sr] = true;
    queue<int> node;
    node.push(sr);
    while (!node.empty())
    {
        int u = node.front();
        node.pop();
        fl(i, 0, graph[u].size())
        {
            int v = graph[u][i];
            if (!visited[v])
            {
                visited[v] = true;
                vyrevy.pb(v);
                cnt++;
                node.push(v);
            }
        }
    }
    if (digg[cnt].size() == 0)
    {
        digg[cnt] = vyrevy;
    }
    return cnt;
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
        ll n, m, mx_div = -1e12;
        vector<pii> edlist;
        vector<int> taken;

        cin >> n >> m;
        ll a[n + 10], b[n + 10];

        //clear
        MEM(valid, 0), MEM(visited, 0);
        fl(i, 0, n + 100) graph[i].clear();
        digg.clear();
        //clear

        fl(i, 1, n + 1) cin >> a[i];
        fl(i, 1, n + 1)
        {
            cin >> b[i];
            double ni = a[i] * 1.0;
            ni /= b[i];
            ni *= 1e5;
            ll temp = (ll)floor(ni);
            mx_div = max(mx_div, temp);
        }
        fl(i, 0, m)
        {
            int u, v;
            cin >> u >> v;
            edlist.pb(mp(u, v));
        }
        fl(i, 1, n + 1)
        {
            double ni = a[i] * 1.0;
            ni /= b[i];
            ni *= 1e5;
            ll temp = (ll)floor(ni);
            if (temp == mx_div)
            {
                taken.pb(i);
                valid[i] = true;
            }
        }

        map<int, int> mping, rev_map;
        fl(i, 0, taken.size())
        {
            mping[taken[i]] = i + 1;
            rev_map[i + 1] = taken[i];
        }
        fl(i, 0, edlist.size())
        {
            int u = edlist[i].fi, v = edlist[i].se;
            if (valid[u] && valid[v])
            {
                u = mping[u], v = mping[v];
                graph[u].pb(v);
                graph[v].pb(u);
            }
        }
        int mx = 0;
        fl(k, 0, taken.size())
        {
            int i = mping[taken[k]];
            if (!visited[i])
            {
                // cout << taken[k] << "->>" << mping[taken[k]] << nl;
                mx = max(bfs(i), mx);
            }
        }
        cout << mx << nl;
        sort(all(digg[mx]));
        fl(i, 0, digg[mx].size()) cout << rev_map[digg[mx][i]] << sp;
        cout << nl;
    }
    return 0;
}
