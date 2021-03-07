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
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        string str[n + 1];
        fl(i, 0, n) cin >> str[i];
        vector<pii> moves;
        if (str[0][1] == '1' && str[1][0] == '1')
        {
            if (str[n - 2][n - 1] == '1')
                moves.pb(mp(n - 1, n));
            if (str[n - 1][n - 2] == '1')
                moves.pb(mp(n, n - 1));
        }
        else if (str[0][1] == '0' && str[1][0] == '0')
        {
            if (str[n - 2][n - 1] == '0')
                moves.pb(mp(n - 1, n));
            if (str[n - 1][n - 2] == '0')
                moves.pb(mp(n, n - 1));
        }
        else if (str[n - 2][n - 1] == '1' && str[n - 1][n - 2] == '1')
        {
            if (str[0][1] == '1')
                moves.pb(mp(1, 2));
            if (str[1][0] == '1')
                moves.pb(mp(2, 1));
        }
        else if (str[n - 2][n - 1] == '0' && str[n - 1][n - 2] == '0')
        {
            if (str[0][1] == '0')
                moves.pb(mp(1, 2));
            if (str[1][0] == '0')
                moves.pb(mp(2, 1));
        }
        else
        {
            if (str[0][1] == '0')
            {
                moves.pb(mp(2, 1));
            }
            else
            {
                moves.pb(mp(1, 2));
            }
            if (str[n - 2][n - 1] == '1')
            {
                moves.pb(mp(n, n - 1));
            }
            else
            {
                moves.pb(mp(n - 1, n));
            }
        }
        cout << moves.size() << nl;
        fl(i, 0, (int)moves.size()) cout << moves[i].fi << sp << moves[i].se << nl;
    }
    return 0;
}