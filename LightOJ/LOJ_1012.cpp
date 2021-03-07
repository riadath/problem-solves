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
#define pi 2 * acos(0)
#define db double
#define fi first
#define se second
#define pi4 pair<pii, pii>
#define all(a) a.begin(), a.end()

bool comp(const int &a, const int &b)
{
    return a > b;
}
string mat[30];
int r, c, n;
int dirx[] = {1, -1, 0, 0};
int diry[] = {0, 0, 1, -1};

int bfs(pii sr)
{
    map<pii, bool> visited;
    visited[sr] = true;
    queue<pii> node;
    node.push(sr);
    int cnt = 1;
    while (!node.empty())
    {
        pii u = node.front();
        node.pop();
        fl(k, 0, 4)
        {
            int x = u.fi + dirx[k];
            int y = u.se + diry[k];
            if (x >= 0 && x < r && y >= 0 && y < c)
            {
                if (mat[x][y] == '.' && !visited[mp(x, y)])
                {
                    visited[mp(x, y)] = true;
                    cnt++;
                    node.push(mp(x, y));
                }
            }
        }
    }
    return cnt;
}

int main()
{
    // FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T;
    cin >> T;
    int kas = 1;
    while (T--)
    {
        cin >> c >> r;
        n = r * c;
        pii sr;
        fl(i, 0, r)
        {
            cin >> mat[i];
            fl(j, 0, c) if (mat[i][j] == '@')
            {
                sr = mp(i, j);
            }
        }
        int ans = bfs(sr);
        cout << "Case " << kas++ << ": ";
        cout << ans << nl;
    }
    return 0;
}
