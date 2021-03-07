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
int n;
bool visited[100][101][101];
int dist[101][101][101];
int dirx[] = {1, -1, 0, 0};
int diry[] = {0, 0, 1, -1};
vector<pii> d, s;
string mat[20];
bool avail(pii cor, int k)
{
    int x = cor.fi + dirx[k];
    int y = cor.se + diry[k];
    if (x >= 0 && x < n && y >= 0 && y < n)
    {
        if (mat[x][y] == '.' || mat[x][y] == 'X')
            return true;
    }
    return false;
}
bool avail2(pii cor, int k)
{
    int x = cor.fi + dirx[k];
    int y = cor.se + diry[k];
    return (x >= 0 && x < n && y >= 0 && y < n);
}
int bfs()
{
    MEM(visited, 0);
    MEM(dist, -1);
    dist[s[0].fi * n + s[0].se][s[1].fi * n + s[1].se][s[2].fi * n + s[2].se] = 0;
    visited[s[0].fi * n + s[0].se][s[1].fi * n + s[1].se][s[2].fi * n + s[2].se] = 1;
    queue<tuple<pii, pii, pii>> node;
    node.push(make_tuple(s[0], s[1], s[2]));
    while (!node.empty())
    {
        tuple<pii, pii, pii> top = node.front();
        node.pop();
        fl(k, 0, 4)
        {
            tuple<pii, pii, pii> v;
            pii aa = get<0>(top), bb = get<1>(top), cc = get<2>(top);

            // string str = "---------------";
            // debug(str);
            // debug(aa);
            // debug(bb);
            // debug(cc);

            bool done[4];
            MEM(done, 0);
            fl(pp, 0, 3)
            {
                if (avail2(aa, k) && !done[0])
                {
                    int x = aa.fi + dirx[k], y = aa.se + diry[k];
                    if ((mp(x, y) != bb && mp(x, y) != cc) && mat[x][y] != '#')
                    {
                        done[0] = 1;
                        aa = mp(x, y);
                    }
                }
                if (avail2(bb, k) && !done[1])
                {
                    int x = bb.fi + dirx[k], y = bb.se + diry[k];
                    if ((mp(x, y) != aa && mp(x, y) != cc) && mat[x][y] != '#')
                    {
                        done[1] = 1;
                        bb = mp(x, y);
                    }
                }
                if (avail2(cc, k) && !done[2])
                {
                    int x = cc.fi + dirx[k], y = cc.se + diry[k];
                    if ((mp(x, y) != bb && mp(x, y) != aa) && mat[x][y] != '#')
                    {
                        done[2] = 1;
                        cc = mp(x, y);
                    }
                }
            }
            v = make_tuple(aa, bb, cc);
            // debug(aa);
            // debug(bb);
            // debug(cc);
            int p = get<0>(top).fi * n + get<0>(top).se;
            int q = get<1>(top).fi * n + get<1>(top).se;
            int r = get<2>(top).fi * n + get<2>(top).se;
            int pp = aa.fi * n + aa.se;
            int qq = bb.fi * n + bb.se;
            int rr = cc.fi * n + cc.se;
            if (mat[aa.fi][aa.se] == 'X' && mat[bb.fi][bb.se] == 'X' && mat[cc.fi][cc.se] == 'X')
            {
                return 1 + dist[p][q][r];
            }
            if (!visited[pp][qq][rr])
            {
                visited[pp][qq][rr] = true;
                dist[pp][qq][rr] = 1 + dist[p][q][r];
                node.push(v);
            }
        }
    }
    return -1;
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
        cin >> n;
        fl(i, 0, n)
        {
            cin >> mat[i];
            fl(j, 0, n)
            {
                if (mat[i][j] == 'X')
                    d.pb(mp(i, j));
                if (mat[i][j] >= 'A' && mat[i][j] <= 'C')
                    s.pb(mp(i, j));
            }
        }
        int ans = bfs();
        cout << "Case " << kas++ << ": ";
        if (ans == -1)
            cout << "trapped" << nl;
        else
            cout << ans << nl;
        //clear
        d.clear(), s.clear();
    }
    return 0;
}
