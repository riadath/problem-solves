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
        set<int> uniq;
        map<int, vector<int>> pos;
        fl(i, 0, n)
        {
            int x;
            cin >> x;
            uniq.insert(x);
            pos[x].pb(i + 1);
        }
        int mv = 1e8;
        // if (uniq.size() == 1)
        // {
        //     mv = 0;
        //     cout << mv << nl;
        //     continue;
        // }
        // if ((int)uniq.size() == n)
        // {
        //     mv = 1;
        //     cout << mv << nl;
        //     continue;
        // }
        for (int i : uniq)
        {
            int temp = 0;
            fl(j, 0, pos[i].size() - 1)
            {
                if ((pos[i][j + 1] - pos[i][j] - 1) > 0)
                    temp++;
            }
            // cout << i << sp << temp << nl;
            if (pos[i][pos[i].size() - 1] != n)
                temp += 1;
            if (pos[i][0] != 1)
                temp += 1;
            mv = min(mv, temp);
        }
        cout << mv << nl;
    }
    return 0;
}
