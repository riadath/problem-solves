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

bool if_avail(vector<pair<char, char>> play, char c)
{
    fl(i, 0, play.size())
    {
        if (play[i].fi == c)
            return true;
    }
    return false;
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
        int m, n;
        vector<pair<char, char>> pl1, pl2;
        cin >> n;
        fl(i, 0, n)
        {
            char temp[20000];
            scanf(" %[^\n]", temp);
            pl1.pb(mp(temp[0], temp[strlen(temp) - 1]));
        }
        cin >> m;
        fl(i, 0, m)
        {
            char temp[20000];
            scanf(" %[^\n]", temp);
            pl2.pb(mp(temp[0], temp[strlen(temp) - 1]));
        }

        // fl(i, 0, n) cout << pl1[i].fi << sp << pl1[i].se << nl;
        // fl(i, 0, m) cout << pl2[i].fi << sp << pl2[i].se << nl;
        int winner = -1;
        fl(i, 0, n)
        {
            if (!if_avail(pl2, pl1[i].se))
            {
                winner = 1;
                break;
            }
        }
        if (winner == -1)
        {
            winner = 2;
            fl(i, 0, pl1.size())
            {
                bool whos = true;
                char chur = pl1[i].se;
                bool chek1[20], chek2[20];
                MEM(chek1, 0), MEM(chek2, 0);
                chek1[i] = true;
                int cur_win = 1;
                // cout << "GAME : START\n";
                // cout << pl1[i].fi << sp << pl1[i].se << nl;
                while (cur_win)
                {
                    cur_win = 0;
                    if (whos)
                    {
                        whos = !whos;
                        fl(k, 0, pl2.size())
                        {
                            if (!chek2[k] && pl2[k].fi == chur)
                            {
                                cur_win = 1;
                                chek2[k] = true;
                                chur = pl2[k].se;
                                // cout << pl2[k].fi << sp << pl2[k].se << nl;
                                break;
                            }
                        }
                        if (cur_win == 0)
                        {
                            winner = 1;
                            break;
                        }
                    }
                    else
                    {
                        whos = !whos;
                        fl(k, 0, pl1.size())
                        {
                            if (!chek1[k] && pl1[k].fi == chur)
                            {
                                cur_win = 1;
                                chek1[k] = true;
                                chur = pl1[k].se;
                                // cout << pl1[k].fi << sp << pl1[k].se << nl;
                                break;
                            }
                        }
                    }
                }
                if (winner == 1)
                    break;
            }
        }
        printf("Game %d: player%d\n", kas++, winner);
    }
    return 0;
}