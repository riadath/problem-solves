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
int n, d;
vector<int> xcords[300009];
int dist(int i, int j)
{
    int sum = 0;
    fl(k, 0, d)
    {
        sum += abs(xcords[i][k] - xcords[j][k]);
    }
    return sum;
}
int prims()
{
    int vis_cnt = 1, total_cost = 0;
    bool visited[n + 100];
    MEM(visited, false);
    visited[1] = true;
    priority_queue<pii> node;
    fl(i, 2, n + 1)
    {
        node.push(mp(dist(1, i), i));
    }
    while (vis_cnt < n)
    {
        int x = node.top().fi;
        int u = node.top().se;
        node.pop();
        if (!visited[u])
        {
            total_cost += x;
            visited[u] = true;
            vis_cnt++;
            fl(v, 1, n + 1)
            {
                if (v == u)
                    continue;
                if (!visited[v])
                {
                    int c = dist(u, v);
                    node.push(mp(c, v));
                }
            }
        }
    }
    return total_cost;
}
int main()
{
    FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    cin >> n >> d;
    fl(i, 1, n + 1)
    {
        fl(j, 0, d)
        {
            int temp;
            cin >> temp;
            xcords[i].pb(temp);
        }
        // debug(xcords[i]);
    }
    cout << prims() << nl;
    return 0;
}
