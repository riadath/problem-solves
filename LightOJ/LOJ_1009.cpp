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
vector<int> graph[20009];
int n, m;
bool visited[200009];
int col[200009];
int bfs(int sr)
{
    visited[sr] = true;
    col[sr] = 1;
    queue<int> node;
    node.push(sr);
    int col_ar[3];
    MEM(col_ar, 0);
    col_ar[col[sr]]++;
    while (!node.empty())
    {
        int u = node.front();
        node.pop();
        int to_col;
        if (col[u] == 1)
        {
            to_col = 2;
        }
        else
        {
            to_col = 1;
        }
        fl(i, 0, graph[u].size())
        {
            int v = graph[u][i];
            if (!visited[v])
            {
                visited[v] = true;
                node.push(v);
                col[v] = to_col;
                col_ar[col[v]]++;
            }
        }
    }
    return max(col_ar[1], col_ar[2]);
}

int main()
{
    //FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T, kas = 1;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &m);
        map<int, bool> flag;
        map<int, int> mapped;
        int st = 0;
        fl(i, 0, m)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            if (!flag[x])
            {
                flag[x] = true;
                mapped[x] = ++st;
            }
            if (!flag[y])
            {
                flag[y] = true;
                mapped[y] = ++st;
            }
            int u = mapped[x], v = mapped[y];
            graph[u].pb(v);
            graph[v].pb(u);
        }
        n = st;
        MEM(visited, false);
        MEM(col, -1);
        int cnt = 0;
        fl(i, 1, n + 1)
        {
            if (col[i] == -1)
            {
                cnt += bfs(i);
            }
        }
        printf("Case %d: %d\n", kas++, cnt);
        fl(i, 0, n + 1) graph[i].clear();
    }
    return 0;
}
