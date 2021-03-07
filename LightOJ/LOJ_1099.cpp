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
    return a.second > b.second;
}

int n, m;
vector<pii> graph[5009];
int dist1[5009], dist2[5009];

int dijakstra()
{
    dist1[1] = 0;
    priority_queue<pii> node;
    node.push(mp(0, 1));
    while (!node.empty())
    {
        int u = node.top().se;
        node.pop();
        fl(i, 0, graph[u].size())
        {
            int v = graph[u][i].fi;
            int w = graph[u][i].se;
            if (dist1[v] > dist1[u] + w)
            {
                dist2[v] = min(dist2[v], min(dist1[v], min(dist2[u] + w, dist1[u] + 3 * w)));
                dist1[v] = dist1[u] + w;
                node.push(mp(-1 * (dist1[v]), v));
            }
            else if (dist1[u] + w > dist1[v] && dist1[u] + w < dist2[v])
            {
                dist2[v] = dist1[u] + w;
            }
        }
    }
    int mn = 1e7;
    fl(i, 0, graph[1].size()) mn = min(graph[1][i].se, mn);
    return min(dist2[n], dist1[n] + 2 * mn);
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
        int mn1 = 1e8, mn2 = 1e8, mn3 = 1e8, i;
        cin >> n >> m;

        fl(i, 0, n + 1)
        {
            graph[i].clear();
            dist1[i] = 1e7, dist2[i] = 1e7;
        }

        fl(i, 0, m)
        {
            int x, y, w;
            cin >> x >> y >> w;
            graph[x].pb(mp(y, w));
            graph[y].pb(mp(x, w));
        }

        cout << "Case " << kas++ << ": " << dijakstra() << nl;
    }
    return 0;
}
