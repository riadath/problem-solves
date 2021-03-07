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
int n, m;
int col[100009];
set<int> cols;
vector<int> graph[100009];
map<int, vector<int>> colel;
int main()
{
    FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    fl(i, 1, n + 1)
    {
        cin >> col[i];
        cols.insert(col[i]);
        colel[col[i]].pb(i);
    }
    fl(i, 0, m)
    {
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    int mx = -1e8, idx = 1e8;
    for (auto i : cols)
    {
        map<int, bool> flag;
        int cnt = 0;
        for (int j = 0; j < (int)colel[i].size(); j++)
        {
            int u = colel[i][j];
            for (int k = 0; k < (int)graph[u].size(); k++)
            {
                int v = graph[u][k];
                if (!flag[col[v]] && col[v] != i)
                    cnt++, flag[col[v]] = true;
            }
        }
        // cout << cnt << nl    ;
        if (cnt > mx || (cnt == mx && i < idx))

            mx = cnt, idx = i;
    }
    cout << idx << nl;
    return 0;
}
