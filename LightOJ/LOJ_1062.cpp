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
        db x, y, c;
        cin >> x >> y >> c;
        db lo = 0.00000001, hi = min(x, y);
        db ans = 0;
        while (abs(hi - lo) > 0.00000001)
        {
            db mid = (lo + hi) / (2.00);
            db c_temp = sqrt((y * y - mid * mid) * (x * x - mid * mid)) / (sqrt((y * y - mid * mid)) + sqrt((x * x - mid * mid)));
            if (abs(c_temp - c) < 0.00000001)
            {
                ans = mid;
                break;
            }
            if (c_temp > c)
            {
                lo = mid;
            }
            else
            {
                hi = mid;
            }
        }
        cout << "Case " << kas++ << ": ";
        printf("%0.10lf\n", ans);
    }
    return 0;
}
