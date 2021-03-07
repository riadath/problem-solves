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

    string str, ans;
    int one = 0;
    cin >> str;
    fl(i, 0, str.size())
    {
        if (str[i] == '1')
            one++;
    }
    int cnt = 0, term = 0;
    fl(i, 0, (int)str.size())
    {
        if (str[i] == '0')
            cnt++;
        if (str[i] == '2')
        {
            fl(k, 0, cnt) ans.pb('0');
            if (!term)
            {
                term++;
                fl(k, 0, one) ans.pb('1');
            }
            ans.pb('2');
            cnt = 0;
        }
    }
    fl(i, 0, cnt) ans.pb('0');
    if (!term)
        fl(i, 0, one) ans.pb('1');
    cout << ans << nl;

    return 0;
}
