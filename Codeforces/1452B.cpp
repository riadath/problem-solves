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
        int n;
        cin >> n;
        ll mx = 0;
        ll arr[n + 10];
        fl(i, 0, n)
        {
            cin >> arr[i];
            mx = max(mx, arr[i]);
        }
        sort(arr, arr + n);
        ll need = 0;
        fl(i, 1, n)
        {
            if (arr[i] == mx)
                break;
            need += mx - arr[i];
        }
        if (need < arr[0])
        {
            ll rem = arr[0] - need;
            if (rem <= n - 1)
                rem = n - 1 - rem;
            else
            {
                ll k = rem / (n - 1) + (rem % (n - 1) != 0);
                rem = k * (n - 1) - rem;
            }
            cout << rem << nl;
        }
        else
            cout << need - arr[0] << nl;
    }
    return 0;
}
