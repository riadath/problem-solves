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
        vector<ll> arr(n);
        fl(i, 0, n) cin >> arr[i];
        sort(all(arr)), reverse(all(arr));
        bool flag = true;
        ll bb = 0, aa = 0;
        fl(i, 0, n)
        {
            if (flag)
            {
                if (arr[i] % 2 == 0)
                    aa += arr[i];
            }
            else
            {
                if (arr[i] % 2)
                    bb += arr[i];
            }
            flag = !flag;
        }
        if (bb > aa)
            cout << "Bob" << nl;
        else if (aa > bb)
            cout << "Alice" << nl;
        else
            cout << "Tie" << nl;
    }
    return 0;
}
