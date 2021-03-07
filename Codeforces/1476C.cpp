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
        ll arr[n + 1], brr[n + 1], crr[n + 1];

        fl(i, 0, n) cin >> crr[i];
        fl(i, 0, n) cin >> arr[i];
        fl(i, 0, n) cin >> brr[i];
        ll ans = 0, save = 0;
        for (int i = 1; i < n; i++)
        {
            ll temp = crr[i] - 1 + 2 + abs(arr[i] - brr[i]);
            if (abs(arr[i] - brr[i]))
            {
                temp = max(temp, save + crr[i] - 1 + 2 - abs(arr[i] - brr[i]));
            }
            ans = max(ans, temp);
            save = temp;
        }
        cout << ans << nl;
    }
    return 0;
}