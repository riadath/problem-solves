#include <bits/stdc++.h>
using namespace std;

#ifdef IHAVETOPEE
#include "debug.h"
#else
#define debug(args...)
#endif

#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
ll arr[21];
int main()
{
    FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T, kas = 1;
    cin >> T;
    ll fact = 1;
    arr[0] = 1;
    fl(i, 1, 20)
    {
        fact *= i;
        arr[i] = fact;
    }
    while (T--)
    {
        ll n;
        cin >> n;
        cout << "Case " << kas++ << ": ";
        vector<int> ans;
        lf(i, 19, 0)
        {
            if (arr[i] <= n)
                n -= arr[i], ans.pb(i);
        }
        reverse(all(ans));
        if (n == 0)
        {
            fl(i, 0, ans.size())
            {
                cout << ans[i] << "!";
                if (i != (int)(ans.size() - 1))
                    cout << "+";
            }
            cout << nl;
        }
        else
            cout << "impossible" << nl;
    }
    return 0;
}
