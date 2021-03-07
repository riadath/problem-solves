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

int dirx[4][3] = {{0, -1, -1}, {0, 1, 1}, {0, -1, -1}, {0, 1, 1}};
int diry[4][3] = {{-1, -1, 0}, {-1, -1, 0}, {1, 1, 0}, {1, 1, 0}};

int main()
{
    FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        string arr[n + 10];
        fl(i, 0, n) cin >> arr[i];
        vector<tuple<pii, pii, pii>> ans;
        fl(i, 0, n) fl(j, 0, m)
        {
            if (arr[i][j] == '1')
            {
                fl(kk, 0, 4)
                {
                    vector<pii> temp;
                    bool flag = true;
                    fl(k, 0, 3)
                    {
                        int x = dirx[kk][k] + i, y = diry[kk][k] + j;
                        if (x >= 0 && x < n && y >= 0 && y < m)
                        {
                            if (arr[x][y] == '1')
                                temp.pb(mp(x, y));
                        }
                        else
                        {
                            flag = false;
                            break;
                        }
                        if (temp.size() == 2)
                            break;
                    }
                    if (flag && temp.size() == 2)
                    {
                        arr[i][j] = '0';
                        arr[temp[0].fi][temp[0].se] = '0', arr[temp[1].fi][temp[1].se] = '0';
                        ans.pb(make_tuple(mp(i, j), temp[0], temp[1]));
                        break;
                    }
                }
            }
        }
        fl(i, 0, n) fl(j, 0, m)
        {
            if (arr[i][j] == '1')
            {
                fl(kk, 0, 4)
                {
                    vector<pii> temp;
                    bool flag = true;
                    fl(k, 0, 3)
                    {
                        int x = dirx[kk][k] + i, y = diry[kk][k] + j;
                        if (x >= 0 && x < n && y >= 0 && y < m)
                        {
                            if (arr[x][y] == '1')
                                temp.pb(mp(x, y));
                        }
                        else
                        {
                            flag = false;
                            break;
                        }
                        if (temp.size() == 2)
                            break;
                    }
                    if (flag)
                    {
                        if (temp.size() == 0)
                        {
                            arr[i][j] = '0';
                            ans.pb(make_tuple(mp(i, j), mp(i + dirx[kk][0], diry[kk][0] + j), mp(i + dirx[kk][1], diry[kk][1] + j)));
                            ans.pb(make_tuple(mp(i, j), mp(i + dirx[kk][2], diry[kk][2] + j), mp(i + dirx[kk][1], diry[kk][1] + j)));
                            ans.pb(make_tuple(mp(i, j), mp(i + dirx[kk][2], diry[kk][2] + j), mp(i + dirx[kk][0], diry[kk][0] + j)));
                        }
                        if (temp.size() == 1)
                        {
                            arr[i][j] = '0';
                            arr[temp[0].fi][temp[0].se] = '0';
                            vector<pii> toad;
                            fl(k, 0, 3)
                            {
                                int x = dirx[kk][k] + i, y = diry[kk][k] + j;
                                if ((x == temp[0].fi && y == temp[0].se))
                                {
                                    continue;
                                }
                                else
                                {
                                    toad.pb(mp(x, y));
                                }
                            }
                            ans.pb(make_tuple(mp(i, j), toad[0], toad[1]));
                            ans.pb(make_tuple(temp[0], toad[0], toad[1]));
                        }
                        break;
                    }
                }
            }
        }
        cout << ans.size() << nl;
        fl(i, 0, ans.size())
        {
            pii x1 = get<0>(ans[i]), x2 = get<1>(ans[i]), x3 = get<2>(ans[i]);
            cout << x1.fi + 1 << sp << x1.se + 1 << sp << x2.fi + 1 << sp << x2.se + 1 << sp << x3.fi + 1 << sp << x3.se + 1 << nl;
        }
    }
    return 0;
}
