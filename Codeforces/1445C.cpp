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

// #define SIZE 50000
// bool prime[50100];

// void sieve()
// {
//     prime[0] = 1, prime[1] = 1;
//     for (int i = 4; i <= SIZE; i += 2)
//         prime[i] = 1;
//     for (int i = 3; i * i <= SIZE; i += 2)
//     {
//         for (int j = 2; i * j <= SIZE; j++)
//         {
//             prime[i * j] = 1;
//         }
//     }
// }

int main()
{
    FIO;
    // sieve();

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        ll p, q;
        cin >> p >> q;
        if (p % q)
        {
            cout << p << nl;
            continue;
        }
        if ((p % 2 == 0) && (p / 2) % q)
        {
            cout << p / 2 << nl;
            continue;
        }
        vector<ll> divs;
        for (ll i = 1; i * i <= q; i++)
        {
            if (q % i == 0)
            {
                if (q / i != i)
                {
                    divs.pb(i);
                    divs.pb(q / i);
                }
                else
                {
                    divs.pb(i);
                }
            }
        }
        ll mx = 1;
        srt(divs);
        for (int i = 0; i < (int)divs.size(); i++)
        {
            // cout << divs[i] << nl;
            if (p % divs[i] == 0 && divs[i] != 1)
            {
                ll te = p;
                // cout << divs[i] << sp << te << nl;
                while (te % divs[i] == 0)
                {
                    te /= divs[i];
                    if (te % q)
                        mx = max(mx, te);
                }
            }
        }
        cout << mx << nl;
    }
    return 0;
}
