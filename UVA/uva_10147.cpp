
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
vector<pii> make;
vector<pii> point;
map<pii, db> cost;
int n, m;
bool made[759][759];

void prims()
{
    int vis_cnt = 1;
    bool visited[n + 1];
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

            make.pb(u.se);
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
    // freopen("out.txt", "w", stdout);
    int T;
    cin >> T;
    int kas = 1;
    while (T--)
    {
        if (kas++ != 1)
            cout << nl;
        cin >> n;
        MEM(made, false);
        fl(i, 0, n)
        {
            int x, y;
            cin >> x >> y;
            point.pb(mp(x, y));
        }
        cin >> m;
        fl(i, 0, m)
        {
            int x, y;
            cin >> x >> y;
            made[x][y] = true;
            made[y][x] = true;
        }
        fl(i, 1, n + 1)
        {
            fl(j, i + 1, n + 1)
            {
                graph[i].pb(j);
                graph[j].pb(i);
                if (made[i][j])
                {
                    cost[mp(i, j)] = 0.00;
                    cost[mp(j, i)] = 0.00;
                }
                else
                {
                    cost[mp(i, j)] = dist(point[i - 1], point[j - 1]);
                    cost[mp(j, i)] = dist(point[i - 1], point[j - 1]);
                }
            }
        }

        prims();

        int cnt = 0;
        fl(i, 0, make.size())
        {

            int x = make[i].fi;
            int y = make[i].se;
            if (!made[x][y])
            {
                cnt++;
                cout << x << sp << y << nl;
                made[x][y] = true;
                made[y][x] = true;
            }
        }
        if (cnt == 0)
        {
            cout << "No new highways need" << nl;
        }

        fl(i, 0, n + 1) graph[i].clear();
        make.clear();
        point.clear();
        cost.clear();
    }
    return 0;
}
