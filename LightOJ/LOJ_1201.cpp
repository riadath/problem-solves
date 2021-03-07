#include <bits/stdc++.h>
using namespace std;

#ifdef IHAVETOPEE
#include "debug.h"
#else
#define debug(args...)
#endif

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
int n, m;
vector<int> graph[1009];
int dp[1009][2];
bool visited[1009];
void f(int u)
{
    if (visited[u])
        return;
    visited[u] = true;
    dp[u][1] = 1;
    fl(i, 0, graph[u].size())
    {
        int v = graph[u][i];
        // debug(v);
        if (visited[v])
            continue;
        f(v);
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
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
        MEM(dp, 0), MEM(visited, 0);
        scanf("%d %d", &n, &m);
        fl(i, 0, m)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            graph[x].pb(y);
            graph[y].pb(x);
        }
        int sum = 0;
        for (int i = 1; i <= n; i++)
            if (!visited[i])
            {
                f(i);
                sum += max(dp[i][0], dp[i][1]);
            }
        printf("Case %d: ", kas++);
        printf("%d\n", sum);
        fl(i, 1, n + 1) graph[i].clear();
    }
    return 0;
}
