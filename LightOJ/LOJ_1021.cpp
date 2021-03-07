#include <bits/stdc++.h>
using namespace std;

#ifdef IHAVETOPEE
#include "debug.h"
#else
#define debug(args...)
#endif

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
int base, k, lim;
string str;
ll charToNum(char ch)
{
    if (ch >= '0' && ch <= '9')
        return ch - '0';
    else
        return ch - 55;
}
void bitSET(int num)
{
    int svv = num;
    string str;
    while (num != 0)
    {
        if (num % 2 == 0)
            str += "0";
        else
            str += "1";
        num /= 2;
    }
    while ((int)str.size() < 20)
    {
        str = str + '0';
    }
    reverse(all(str));
    cout << svv << "-----> " << str << nl;
}

ll dp[21][65540];
ll f(int rem, int bt)
{
    // debug(rem);
    // bitSET(bt);
    if (bt == lim)
    {
        return (rem % k) == 0;
    }
    ll &ret = dp[rem][bt];
    if (ret != -1)
        return ret;
    ll cnt = 0;
    // cout << "___>\n";
    fl(i, 0, (int)str.size())
    {
        // bitSET(bt);
        // cout << "=====> " << (1 << i) << sp << (bt & (1 << i)) << nl;
        if ((bt & (1 << i)) == 0)
        {
            cnt += f((rem * base + charToNum(str[i])) % k, bt | (1 << i));
        }
    }
    return ret = cnt;
}

int main()
{
    FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T, kas = 1;
    cin >> T;
    while (T--)
    {
        MEM(dp, -1);
        cin >> base >> k;
        cin >> str;
        lim = pow(2, (int)str.size()) - 1;
        // cout << lim << nl;
        cout << "Case " << kas++ << ": ";
        cout << f(0, 0) << nl;
    }
    return 0;
}
