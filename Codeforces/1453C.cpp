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
        string str[2009];
        int n;
        cin >> n;
        pll xn[20], yn[20];
        fl(i, 0, 10) xn[i].fi = yn[i].fi = 1e10, xn[i].se = yn[i].se = -1e10;
        fl(i, 0, n)
        {
            cin >> str[i];
            fl(j, 0, n)
            {
                int id = str[i][j] - '0';
                xn[id].fi = min(xn[id].fi, i);
                xn[id].se = max(xn[id].se, i);
                yn[id].fi = min(yn[id].fi, j);
                yn[id].se = max(yn[id].se, j);
            }
        }
        int area[20];
        MEM(area, 0);
        fl(i, 0, n) fl(j, 0, n)
        {
            int id = str[i][j] - '0';
            int t1 = max(abs(xn[id].fi - i), abs(xn[id].se - i)) * max(j, n - j - 1);
            int t2 = max(abs(yn[id].fi - j), abs(yn[id].se - j)) * max(i, n - i - 1);
            area[id] = max(area[id], max(t1, t2));
        }

        fl(i, 0, 10) cout << area[i] << sp;
        cout << nl;
    }
    return 0;
}
