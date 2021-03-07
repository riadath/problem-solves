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
int n, k;
bool comp(const pii &a, const pii &b)
{
    int tm = (a.se - a.fi);
    int tp = (b.se - b.fi);
    return tm < tp;
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
        string str;
        cin >> n >> k >> str;
        vector<pii> lr;
        pii end, start;
        fl(i, 0, n)
        {
            if (str[i] == 'L')
            {
                int st = i;
                while (str[i] == 'L')
                    i++;
                i--;
                if (st == 0)
                {
                    start = mp(st, i);
                }
                if (i == n - 1)
                {
                    end = mp(st, i);
                }
                else if (st != 0 && i != n - 1)
                    lr.pb(mp(st, i));
            }
        }
        sort(all(lr), comp);

        fl(i, 0, lr.size())
        {
            // cout << lr[i].fi << sp << lr[i].se << nl;
            fl(j, lr[i].fi, lr[i].se + 1)
            {
                if (k > 0)
                {
                    str[j] = 'W';
                    k--;
                }
                else
                    break;
            }
            if (k <= 0)
                break;
        }
        if (k > 0)
        {
            if (str[n - 1] == 'L')
            {
                fl(j, end.fi, end.se + 1)
                {
                    if (k > 0)
                    {
                        str[j] = 'W';
                        k--;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            if (k > 0 && str[0] == 'L')
            {
                lf(j, start.se, start.fi)
                {
                    if (k > 0)
                    {
                        str[j] = 'W';
                        k--;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        int sum = 0;
        int pt = 1;
        // cout << str << nl;
        fl(i, 0, n)
        {
            if (str[i] == 'W')
            {
                sum += pt;
                pt = 2;
            }
            if (str[i] == 'L')
            {
                pt = 1;
            }
        }
        cout << sum << nl;
        // fl(i, 0, lr.size()) cout << lr[i].fi << sp << lr[i].se << nl;
    }
    return 0;
}
