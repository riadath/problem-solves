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
vector<int> graph[10009];
pii inOut[10009];
vector<pii> srnode;
bool visited[10009];

void bfs(int sr)
{
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
                node.push(v);
            }
        }
    }
}

int main()
{
    //FIO;
    freopen("in.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
    int T, kas = 1;
    scanf("%d", &T);
    while (T--)
    {
        cin >> n >> m;
        fl(i, 0, m)
        {
            int a, b;
            cin >> a >> b;
            graph[a].pb(b);
            inOut[a].se += 1;
            inOut[b].fi += 1;
        }
        fl(i, 1, n + 1)
        {
            srnode.pb(mp(i, inOut[i].se));
        }
        sort(all(srnode), comp);
        int mv = 0;
        fl(i, 1, n + 1)
        {
            if (inOut[i].fi == 0 && !visited[i])
            {
                mv++;
                bfs(i);
            }
        }

        fl(i, 0, srnode.size())
        {
            int temp = srnode[i].fi;
            if (!visited[temp])
            {
                mv++;
                bfs(temp);
            }
        }

        printf("Case %d: %d\n", kas++, mv);

        //clear
        MEM(inOut, 0);
        fl(i, 1, n + 1) graph[i].clear();
        MEM(visited, 0);
        srnode.clear();
    }
    return 0;
}
