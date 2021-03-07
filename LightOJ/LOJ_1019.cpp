#include <bits/stdc++.h>
using namespace std;
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
#define pi 2 * acos(0)
#define db double
#define fi first
#define se second
#define pi4 pair<pii, pii>
#define all(a) a.begin(), a.end()

bool comp(const pii &a, const pii &b)
{
    return a.second < b.second;
}
int cost[109][109], n, m;
vector<int> graph[109];
ll dijastra()
{
    ll distance[109];
    fl(i, 0, 109) distance[i] = INT_MAX;
    distance[1] = 0;

    priority_queue<pair<ll, int>> node;
    node.push(mp(0, 1));

    while (!node.empty())
    {
        pair<ll, int> tp = node.top();
        node.pop();
        int u = tp.se;
        fl(i, 0, graph[u].size())
        {
            int v = graph[u][i];
            if (distance[v] > distance[u] + cost[u][v])
            {
                distance[v] = distance[u] + cost[u][v];
                node.push(mp(-1 * distance[v], v));
            }
        }
    }
    // cout << "\nCost 1 ot n : " << cost[1][n] << nl;
    // fl(i, 1, n + 1)
    // {
    //     cout << "\nDistance " << i << ": " << distance[i];
    //     if (i == n)
    //         cout << nl;
    // }
    return distance[n];
}
int main()
{
    // FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T, kas = 1;
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        fl(i, 1, n + 1) fl(j, 1, n + 1) cost[i][j] = INT_MAX;
        fl(i, 0, m)
        {
            int u, v, c;
            cin >> u >> v >> c;
            if (cost[u][v] == INT_MAX)
            {
                graph[u].pb(v);
                graph[v].pb(u);
                cost[u][v] = c;
                cost[v][u] = c;
            }
            else
            {
                if (c < cost[u][v])
                {
                    cost[u][v] = c;
                    cost[v][u] = c;
                }
            }
        }
        cout << "Case " << kas++ << ": ";
        ll mn = dijastra();
        if (mn == INT_MAX)
            cout << "Impossible" << nl;
        else
            cout << mn << nl;
        fl(i, 0, 109) graph[i].clear();
    }
    return 0;
}
