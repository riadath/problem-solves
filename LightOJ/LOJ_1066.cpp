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
int n;
string mat[20];
int dirx[] = {1, -1, 0, 0};
int diry[] = {0, 0, 1, -1};
int bfs(int sx, int sy, int dx, int dy)
{
    int visited[20][20], distance[20][20];
    MEM(visited, false);
    fl(i, 0, n + 1) fl(j, 0, n + 1) distance[i][j] = 1e7;
    visited[sx][sy] = true, distance[sx][sy] = 0;
    queue<pii> node;
    node.push(mp(sx, sy));
    while (!node.empty())
    {
        int tx = node.front().fi;
        int ty = node.front().se;
        node.pop();
        fl(k, 0, 4)
        {
            int x = tx + dirx[k], y = ty + diry[k];
            if (x >= 0 && x < n && y >= 0 && y < n)
            {
                if (!visited[x][y] && (mat[x][y] == '.' || mat[x][y] == mat[dx][dy]))
                {
                    visited[x][y] = true;
                    distance[x][y] = 1 + distance[tx][ty];
                    if (x == dx && y == dy)
                        return distance[x][y];
                    node.push(mp(x, y));
                }
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
        int sx = 0, sy = 0;
        map<char, pii> pos;
        cin >> n;
        string let;
        fl(i, 0, n)
        {
            cin >> mat[i];
            fl(j, 0, n)
            {
                if (mat[i][j] == 65)
                    sx = i, sy = j;
                else if (mat[i][j] >= 66 && mat[i][j] <= 91)
                {
                    let.pb(mat[i][j]);
                    pos[mat[i][j]] = mp(i, j);
                }
            }
        }
        cout << "Case " << kas++ << ": ";
        if (let.size() == 0)
        {
            cout << 0 << nl;
            continue;
        }
        sort(all(let));
        int sum = 0;
        bool flag = true;
        fl(i, 0, let.size())
        {
            int temp = bfs(sx, sy, pos[let[i]].fi, pos[let[i]].se);
            if (temp == -1)
            {
                flag = false;
                break;
            }
            mat[sx][sy] = '.';
            sum += temp;
            sx = pos[let[i]].fi, sy = pos[let[i]].se;
        }
        if (!flag)
        {
            cout << "Impossible" << nl;
        }
        else
        {
            cout << sum << nl;
        }
    }
    return 0;
}
