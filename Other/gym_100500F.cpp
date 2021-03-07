#include <bits/stdc++.h>
using namespace std;

// #ifdef IHAVETOPEE
// #include "debug.h"
// #else
// #define debug(args...)
// #endif

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

int main()
{
    // FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T, kas = 1;
    cin >> T;
    while (T--)
    {
        ll n, m;
        cin >> n >> m;
        m = (n * (n + 1) / 2) - m + 1;
        // if (n == m)
        // {
        //     cout << "Case " << kas++ << ": ";
        //     cout << n - 1 << sp << 0 << nl;
        //     continue;
        // }

        ll curr = n, up = n - 1, dw = n - 1, base = m / curr;
        // cout << base << nl;
        while (base > 1)
        {
            // cout << base << sp << m << sp << curr << nl;
            ll pp = (curr - base);
            m -= (((curr * (curr + 1)) / 2) - ((pp * (pp + 1) / 2)));
            curr -= base;
            up -= base, dw -= base;
            if (curr < 1)
                break;
            // cout << "_>" << m << sp << curr << nl;
            base = m / curr;
        }
        while (m > 0 && curr > 0)
        {
            // cout << m << sp << sp << curr << sp << up << sp << dw << nl;
            if (m - curr > 0)
            {
                m -= curr;
                up--, curr--, dw--;
            }
            else
                break;
        }
        dw -= (m - 1);
        // cout << up << sp << dw << nl;
        cout << "Case " << kas++ << ": ";
        cout << up << sp << dw << nl;
    }
    return 0;
}