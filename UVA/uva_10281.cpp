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

double stringto(string inp)
{
    return 1.0 * (inp[1] - '0') + 10.0 * (inp[0] - '0') + 1.0 * ((inp[4] - '0') + 10.0 * (inp[3] - '0')) / 60.00 + 1.0 * ((inp[7] - '0') + 10.0 * (inp[6] - '0')) / (3600.00);
}
double sto(string inp)
{
    double st = 1, ret = 0;
    lf(i, inp.size() - 1, 0)
    {
        ret += 1.0 * (st * (inp[i] - '0'));
        st *= 10.0;
    }
    return ret;
}
int main()
{
    // FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    vector<string> inp;
    string temp;
    while (cin >> temp)
    {
        inp.pb(temp);
    }
    double elapsed = 0, dist = 0, cur_sp = 0;

    fl(i, 0, inp.size())
    {

        if (inp[i].size() == 8)
        {
            double tot = stringto(inp[i]);
            db tme = tot - elapsed;
            // cout << tot << sp << tme << nl;
            if ((i + 1 < inp.size() && inp[i + 1].size() == 8) || i == inp.size() - 1)
            {
                cout << inp[i] << sp;
                printf("%0.2lf km\n", tme * cur_sp + dist);
                dist += tme * cur_sp;
            }
            else if (i + 1 < inp.size() && inp[i + 1].size() != 8)
            {
                dist += tme * cur_sp;
                cur_sp = sto(inp[i + 1]);
                // cout << dist << sp << cur_sp << nl;
                i++;
            }
            elapsed = tot;
        }
    }

    return 0;
}