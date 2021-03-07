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
int dirx[] = {1, -1, 0, 0};
int diry[] = {0, 0, 1, -1};
vector<int> graph[2509];
int n, m;
bool cycle()
{
    int n_nodes = n * m;
    bool visited[n_nodes + 1];
    MEM(visited, false);
    for (int sr = 1; sr <= n_nodes; sr++)
    {
        if (!visited[sr])
        {
            int parent[n_nodes + 1];
            MEM(parent, -1);

            queue<int> nodes;
            nodes.push(sr);
            visited[sr] = true;
            while (!nodes.empty())
            {
                int u = nodes.front();
                nodes.pop();
                fl(i, 0, graph[u].size())
                {
                    int v = graph[u][i];
                    if (!visited[v])
                    {
                        visited[v] = true;
                        nodes.push(v);
                        parent[v] = u;
                    }
                    else if (parent[u] != v)
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main()
{
    FIO;
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    map<pii, int> nd;
    cin >> n >> m;
    string s[n];
    int st = 1;
    fl(i, 0, n)
    {
        cin >> s[i];
        fl(j, 0, m)
        {
            nd[mp(i, j)] = st++;
        }
    }
    fl(i, 0, n)
    {
        fl(j, 0, m)
        {
            int u = nd[mp(i, j)];
            fl(k, 0, 4)
            {
                int x = i + dirx[k];
                int y = j + diry[k];
                if (x < n && x >= 0 && y < m && y >= 0)
                {
                    int v = nd[mp(x, y)];
                    if (s[x][y] == s[i][j])
                    {
                        graph[u].pb(v);
                    }
                }
            }
        }
    }

    // fl(i, 1, n * m + 1)
    // {
    //     cout << i << sp << "---> ";
    //     fl(j, 0, graph[i].size()) cout << graph[i][j] << sp;
    //     cout << nl;
    // }

    if (cycle())
        cout << "Yes" << nl;
    else
        cout << "No" << nl;
    return 0;
}
