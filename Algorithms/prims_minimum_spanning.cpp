/*
 MINIMUM SPANNING TREE
 UVA 908
 USES PAIRS
*/

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
#define pi 3.141592653589793238
#define db double
#define fi first
#define se second
#define pi4 pair<pii, pii>
#define all(a) a.begin(), a.end()

bool comp(const pii &a, const pii &b)
{
    return a.second < b.second;
}

db dist(pii x, pii y)
{
    return sqrt((x.fi - y.fi) * (x.fi - y.fi) + (x.se - y.se) * (x.se - y.se));
}

vector<int> graph[759];
map<pii, int> cost;
int n;
void prims()
{
    int vis_cnt = 1;
    bool visited[800];
    MEM(visited, false);
    visited[1] = true;
    priority_queue<pair<db, pii>> node;
    for (int i = 0; i < graph[1].size(); i++)
    {
        int v = graph[1][i];

        db x = cost[mp(1, v)];
        node.push(mp(-1 * x, mp(1, v)));
    }
    while (vis_cnt < n)
    {
        pair<db, pii> u = node.top();
        node.pop();
        int x = u.se.se;
        if (!visited[x])
        {
            visited[x] = true;
            vis_cnt++;
            for (int i = 0; i < graph[x].size(); i++)
            {
                int v = graph[x][i];
                if (!visited[v])
                {
                    db c = cost[mp(x, v)];
                    node.push(mp(-1 * c, mp(x, v)));
                }
            }
        }
    }
}

int main()
{
    FIO;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //make graph
    // do the thing
    return 0;
}
