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
int n, src, dest, arr[50009], parent[50009];
vector<int> graph[50009], ans;
void print(int ds)
{
    ans.pb(ds);
    if (ds == src)
        return;
    print(parent[ds]);
}
void bfs(int sr)
{
    bool visited[50009];
    MEM(visited, 0);
    queue<int> node;
    node.push(sr);
    visited[sr] = true;
    while (!node.empty())
    {
        int u = node.front();
        node.pop();
        // cout << u << ">>>\n";
        fl(i, 0, graph[u].size())
        {
            int v = graph[u][i];
            if (parent[v] == v)
                parent[v] = u;
            if (!visited[v])
            {
                visited[v] = 1, node.push(v);
            }
        }
    }
    //clearrrrrrrrrrrrrrrrrrrrrrrrrrr
    // fl(i, 1, 100) if ((int)graph[i].size() != 0) cout << i << sp << parent[i] << nl;
    print(dest);
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
        scanf("%d", &n);
        fl(i, 0, n)
        {
            scanf("%d", &arr[i]);
        }
        fl(i, 0, 50002) parent[i] = i;

        fl(i, 0, n - 1)
        {
            int u = arr[i], v = arr[i + 1];
            graph[u].pb(v), graph[v].pb(u);
        }
        fl(i, 0, n)
        {
            sort(all(graph[arr[i]]));
        }
        //clearrrrrrrrrrrrrrrrrrrrrrrrrrr
        // fl(i, 1, n + 1)
        // {
        //     cout << i << "->";
        //     fl(j, 0, graph[i].size()) cout << graph[i][j] << sp;
        //     cout << nl;
        // }
        src = arr[0], dest = arr[n - 1];
        printf("Case %d:\n", kas++);

        bfs(arr[0]);
        reverse(all(ans));

        fl(i, 0, ans.size())
        {
            printf("%d", ans[i]);
            if (i != (int)(ans.size() - 1))
                printf(" ");
        }
        printf("\n");
        fl(i, 0, n) graph[arr[i]].clear();
        ans.clear();
    }
    return 0;
}
