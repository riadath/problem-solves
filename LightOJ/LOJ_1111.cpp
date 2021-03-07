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
int n, m, k, srces[109];
vector<int> graph[1009];
void bfs(int visited[], int src)
{
    visited[src] = true;
    queue<int> node;
    node.push(src);
    while (!node.empty())
    {
        int u = node.front();
        node.pop();
        fl(i, 0, graph[u].size())
        {
            int v = graph[u][i];
            if (!visited[v])
            {
                visited[v] = 1;
                node.push(v);
            }
        }
    }
}
int main()
{
    // FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T, kas = 1;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d %d", &k, &n, &m);
        fl(i, 0, k) scanf("%d", &srces[i]);
        fl(i, 0, m)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            graph[x].pb(y);
        }
        int visit[1009];
        fl(i, 0, n + 1) visit[i] = 1;
        fl(i, 0, k)
        {
            int src = srces[i];
            int visited[1009];
            MEM(visited, 0);
            bfs(visited, src);
            fl(i, 1, n + 1)
            {
                visit[i] = (visit[i] & visited[i]);
            }
        }
        int cnt = 0;
        fl(i, 1, n + 1) if (visit[i]) cnt++;
        printf("Case %d: ", kas++);
        printf("%d\n", cnt);
        //clear
        fl(i, 1, n + 1) graph[i].clear();
    }
    return 0;
}
