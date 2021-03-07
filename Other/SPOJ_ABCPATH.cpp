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
int n, m;
string str[100];
map<pii, bool> mat;
int dirx[] = {1, 0, 1, -1, 0, -1, 1, -1};
int diry[] = {0, 1, 1, 0, -1, -1, -1, 1};
int dp[51][51];
int dfs(int cx, int cy)
{
    if (dp[cx][cy] != -1)
        return dp[cx][cy];
    pii cor = mp(cx, cy);
    mat[cor] = true;
    int ret = 0; //, flag = 0;
    fl(k, 0, 8)
    {
        int x = dirx[k] + cor.fi, y = diry[k] + cor.se;
        if (x >= 0 && x < n && y >= 0 && y < m)
        {
            if (str[cor.fi][cor.se] + 1 == str[x][y] && !mat[mp(x, y)])
            {
                // flag = 1;
                mat[mp(x, y)] = true;
                int temp = 1 + dfs(x, y);
                ret = max(temp, ret);
            }
        }
    }
    return dp[cx][cy] = ret;
}
int main()
{
    FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int kas = 1;
    // cin >> T;
    while (cin >> n >> m && (m || n))
    {
        mat.clear();
        MEM(dp, -1);
        fl(i, 0, n) cin >> str[i];
        int mx = 0, exi = 0;
        fl(i, 0, n) fl(j, 0, m) if (str[i][j] == 'A') mx = max(mx, dfs(i, j)), exi = 1;
        cout << "Case " << kas++ << ": ";
        if (!exi)
            cout << 0 << nl;
        else
            cout << mx + 1 << nl;
    }
    return 0;
}
