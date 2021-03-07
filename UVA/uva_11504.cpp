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
    return a.se > b.se;
}
int n, e, visited[100009], t_in[100009], t_out[100009], timer = 1;
vector<int> graph[100009];

void dfs(int u)
{
    t_in[u] = timer++;
    visited[u] = 1;
    for (int v : graph[u])
    {
        if (!visited[v])
            dfs(v);
    }
    visited[u] = 2;
    t_out[u] = timer++;
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
        vector<pii> sorted;
        cin >> n >> e;
        fl(i, 0, e)
        {
            int u, v;
            cin >> u >> v;
            graph[u].pb(v);
        }
        fl(i, 1, n + 1)
        {
            if (!visited[i])
                dfs(i);
        }
        fl(i, 1, n + 1) sorted.pb(mp(i, t_out[i]));
        sort(all(sorted), comp);
        int cnt = 0;
        MEM(visited, 0);
        fl(k, 0, sorted.size())
        {
            int i = sorted[k].fi;
            if (!visited[i])
                cnt++, dfs(i);
        }
        cout << cnt << nl;
        //clear
        MEM(visited, 0), timer = 1;
        fl(i, 0, n + 1) graph[i].clear();
    }
    return 0;
}
