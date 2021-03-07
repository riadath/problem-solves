#include <bits/stdc++.h>
using namespace std;

// #ifdef IHAVETOPEE
// #include "debug.h"
// #else
// #define debug(args...)
// #endif

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
int n, m, timer = 0, root_child = 0, cnt = 0;
int time_in[100109], low_nd[100109];
int visited[100109], parent[100109];
int if_articulate[100109];
vector<int> graph[100109];

void dfs_articulate(int u)
{
    visited[u] = true;
    time_in[u] = low_nd[u] = ++timer;
    // cout << "NODE: " << u << nl;
    for (int v : graph[u])
    {
        // cout << v << "\\" << nl;
        if (v == parent[u])
            continue;
        if (visited[v])
        {
            low_nd[u] = min(low_nd[u], time_in[v]);
            continue;
        }
        parent[v] = u;
        dfs_articulate(v);
        low_nd[u] = min(low_nd[u], low_nd[v]);
        if (u != 1 && time_in[u] <= low_nd[v])
        {
            // cout << "======>" << u << sp << v << sp << low_nd[u] << sp << low_nd[v] << nl;
            if_articulate[u] = 1;
        }
        if (u == 1)
            root_child += 1;
    }
    if (root_child > 1 && u == 1)
        if_articulate[u] = 1;
}

int main()
{
    //  FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T, kas = 1;
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        fl(i, 0, m)
        {
            int x, y;
            cin >> x >> y;
            graph[x].pb(y), graph[y].pb(x);
        }
        dfs_articulate(1);
        fl(i, 1, n + 1) if (if_articulate[i]) cnt++;

        // cout << "ROOT CHILD : " << root_child << nl;
        // fl(i, 1, n + 1) cout << i << sp << time_in[i] << sp << low_nd[i] << sp << if_articulate[i] << nl;

        cout << "Case " << kas++ << ": " << cnt << nl;
        //clearing
        MEM(visited, 0), MEM(parent, 0), MEM(time_in, 0);
        MEM(if_articulate, 0), MEM(low_nd, 0);
        timer = 0, root_child = 0, cnt = 0;
        fl(i, 0, n + 10) graph[i].clear();
    }
    return 0;
}
