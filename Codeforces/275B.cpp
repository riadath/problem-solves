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

int main()
{
    FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    string str[100];
    int n, m;
    cin >> n >> m;
    vector<pii> bCells;
    fl(i, 0, n)
    {
        cin >> str[i];
        fl(j, 0, m)
        {
            if (str[i][j] == 'B')
                bCells.pb(mp(i, j));
        }
    }
    bool flag = true;
    fl(i, 0, bCells.size())
    {
        int sx = bCells[i].fi, sy = bCells[i].se;
        fl(j, i + 1, bCells.size())
        {
            int dx = bCells[j].fi, dy = bCells[j].se;
            if (sx == dx)
                fl(k, sy, dy + 1)
                {
                    if (str[sx][k] == 'W')
                    {
                        flag = 0;
                        break;
                    }
                }
            else if (sy == dy)
                fl(k, sx, dx + 1)
                {
                    if (str[k][sy] == 'W')
                    {
                        flag = 0;
                        break;
                    }
                }
            else
            {
                bool succes = 1;
                fl(k, sx, dx + 1)
                {
                    if (str[k][sy] == 'W')
                    {
                        succes = 0;
                        break;
                    }
                }

                int up, dw;
                if (sy > dy)

                    up = dy, dw = sy;
                else
                    up = sy, dw = dy;
                fl(k, up, dw + 1)
                {
                    if (str[dx][k] == 'W')
                    {
                        succes = 0;
                        break;
                    }
                }
                if (!succes)
                {
                    succes = 1;
                    fl(k, up, dw + 1)
                    {
                        if (str[sx][k] == 'W')
                        {
                            succes = 0;
                            break;
                        }
                    }
                    fl(k, sx, dx + 1)
                    {
                        if (str[k][dy] == 'W')
                        {
                            succes = 0;
                            break;
                        }
                    }
                }
                flag = succes;
            }
            if (!flag)
            {
                // cout << "-------\n";
                // cout << sx << sp << sy << nl;
                // cout << dx << sp << dy << nl;
                break;
            }
        }
        if (!flag)
        {
            break;
        }
    }
    if (flag)
        cout << "YES" << nl;
    else
        cout << "NO" << nl;
    return 0;
}
