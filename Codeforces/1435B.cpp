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
        int n, m;
        cin >> n >> m;
        vector<int> rows[n + 10];
        map<int, int> rcnt;
        fl(i, 0, n)
        {
            fl(j, 0, m)
            {
                int x;
                cin >> x;
                rows[i].pb(x);
                rcnt[x] = i;
            }
        }
        vector<int> oneCol;
        fl(i, 0, n)
        {
            int x;
            cin >> x, oneCol.pb(x);
        }
        fl(i, 0, m - 1)
        {
            fl(j, 0, n)
            {
                int x;
                cin >> x;
            }
        }
        // cout << "=>\n";
        fl(i, 0, n)
        {
            int rc = rcnt[oneCol[i]];
            fl(j, 0, m) cout << rows[rc][j] << sp;
            cout << nl;
        }
    }
    return 0;
}
