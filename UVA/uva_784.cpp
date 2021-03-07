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
int dirx[] = {0, 1, -1, 0};
int diry[] = {1, 0, 0, -1};

int main()
{
    // FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T;
    cin >> T;
    getchar();
    while (T--)
    {
        string maze[100], temp, ender;
        int st = 0, posx = 0, posy = 0, done = 1;
        while (true)
        {
            getline(cin, temp);
            // cout << "===>" << temp << nl;
            if (temp[0] == '_')
            {
                ender = temp;
                break;
            }

            // cout << temp << nl;
            maze[st] = temp;
            if (done)
            {
                fl(i, 0, temp.size())
                {
                    if (temp[i] == '*')
                    {
                        posx = st, posy = i, done = 0;
                        break;
                    }
                }
            }
            st++;
        }
        // cout << posx << sp << posy << nl;
        // cout << "======================================\n";
        queue<pii> node;
        node.push(mp(posx, posy));
        // map<pii, bool> visited;
        maze[posx][posy] = '#';
        while (!node.empty())
        {
            int x = node.front().fi;
            int y = node.front().se;
            node.pop();
            fl(k, 0, 4)
            {
                int xx = x + dirx[k], yy = y + diry[k];
                if (xx < st && xx >= 0)
                    if (yy < maze[xx].size() && yy >= 0)
                        if (maze[xx][yy] == ' ')
                        {
                            maze[xx][yy] = '#';
                            node.push(mp(xx, yy));
                        }
            }
        }
        fl(i, 0, st) if (maze[i][0] != ' ') cout << maze[i] << nl;
        cout << ender << nl;
    }
    return 0;
}
