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
        ll n;
        cin >> n;
        ll moves = 0;
        while (n != 1)
        {
            if (n % 2 == 0 && n > 2)
            {
                moves++;
                n = 2;
            }
            else
            {
                n--;
                moves++;
            }
        }
        cout << moves << nl;
        // vector<ll> divs;
        // for (ll i = 2; i * i <= n; i++)
        // {
        //     if (n % i == 0)
        //     {
        //         divs.pb(i);
        //         if ((n / i) != i)
        //             divs.pb(n / i);
        //     }
        // }
        // sort(all(divs)), reverse(all(divs));
        // // fl(i, 0, divs.size()) cout << divs[i] << sp;
        // // cout << nl;
        // ll moves = 0;
        // fl(i, 0, divs.size())
        // {
        //     if (n % divs[i] == 0 && divs[i] != n)
        //     {
        //         n /= divs[i];
        //         moves++;
        //     }
        // }
        // cout << moves + (n - 1) << nl;
    }
    return 0;
}
