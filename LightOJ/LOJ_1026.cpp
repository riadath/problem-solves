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
    if (a.fi == b.fi)
        return a.se < b.se;
    return a.fi < b.fi;
}
int n;
vector<int> graph[10015];

int str_to(char str[100])
{
    int len = strlen(str);
    int sum = 0;
    for (int i = 1; i < len - 1; i++)
    {
        sum *= 10;
        sum += str[i] - '0';
    }
    return sum;
}

int timer = 0, visited[10009], time_in[10009], low_nd[10009], parent[10009];

void dfs_articulate(int u)
{
    // cout << "TIMER : " << timer << nl;
    timer++;
    time_in[u] = timer;
    low_nd[u] = time_in[u];
    visited[u] = true;
    // cout << "NODE : " << u << nl;
    for (int v : graph[u])
    {
        // cout << "/ " << v << nl;
        if (v == parent[u])
            continue;
        if (visited[v])
        {
            low_nd[u] = min(low_nd[u], time_in[v]);
        }
        else
        {
            parent[v] = u;
            dfs_articulate(v);
            low_nd[u] = min(low_nd[u], low_nd[v]);
        }
    }
    timer++;
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
        for (int i = 0; i < n; i++)
        {
            int u;
            char str[10];
            scanf("%d %s", &u, str);
            int len = str_to(str);
            for (int j = 0; j < len; j++)
            {
                int v;
                scanf("%d", &v);
                graph[u].pb(v);
            }
        }
        timer = 0;
        fl(i, 0, n) if (!visited[i])
        {

            dfs_articulate(i);
        }
        vector<pii> ans;
        map<pii, bool> chek;
        for (int u = 0; u < n; u++)
        {
            for (int v : graph[u])
            {
                // cout << u << sp << time_in[u] << "----" << v << sp << low_nd[v] << nl;

                if (time_in[u] < low_nd[v])
                {
                    if (u < v)
                        ans.pb(mp(u, v));
                    else
                        ans.pb(mp(v, u));
                }
            }
        }
        printf("Case %d:\n", kas++);
        sort(all(ans), comp);
        printf("%d critical links\n", (int)ans.size());
        for (pii i : ans)
        {
            printf("%d - %d\n", min(i.fi, i.se), max(i.fi, i.se));
        }

        //clearing
        fl(i, 0, n + 1) graph[i].clear();
        MEM(visited, 0), MEM(time_in, 0), MEM(low_nd, 0), MEM(parent, 0);
    }
    return 0;
}
