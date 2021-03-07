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

ll binaryTo(string str)
{
    reverse(all(str));
    ll st = 1, tot = 0;
    fl(i, 0, str.size())
    {
        tot += (str[i] - '0') * st;
        st *= 2;
    }
    return tot;
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
        if (n == 1)
        {
            cout << 1 << nl;
            continue;
        }
        else if (n == 0)
        {
            cout << 0 << nl;
            continue;
        }
        string ans = "";
        if (n % 2 == 0)
            ans += "1", n--;
        // cout << "->" << ans << nl;
        while (n > 1)
        {
            if (n > 1)
            {
                if (m > 0)
                {
                    ans += "0";
                    m -= 1;
                }
                ans += "11";
                n -= 2;
            }
            else
                break;
        }
        if (m > 0)
            ans += "0", m--;
        // cout << ans << nl;
        if (n == 1)
        {
            if (ans[ans.size() - 1] == '0')
                ans += "1";
            else
            {
                if (ans[0] == '0')
                    ans = "1" + ans;
                else
                    ans += "1";
            }
        }
        fl(i, 0, m)
        {
            ans = "0" + ans;
        }
        // cout << ans << sp;
        cout << binaryTo(ans) << nl;
    }
    return 0;
}