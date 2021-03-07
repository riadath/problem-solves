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

int main()
{
    FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        ll n, tot = 0;
        cin >> n;
        ll arr[n + 1];
        ll sum = 0, mn = n - 1, mx = 0;
        fl(i, 0, n) cin >> arr[i], sum += arr[i], mx = max(mx, arr[i]);
        arr[n] = 1e18;
        if (n == 1)
        {
            cout << 0 << nl;
            continue;
        }
        fl(i, 0, n)
        {
            tot += arr[i];
            if (sum % tot == 0 && (sum / tot) <= n && tot >= mx)
            {
                ll szz = sum / tot, flag = 1;
                for (int k = i + 1; k < n;)
                {
                    if (arr[k] == tot)
                        k++;
                    else
                    {
                        int sum = 0;
                        while (sum < tot)
                        {
                            sum += arr[k++];
                        }
                        if (sum != tot)
                        {
                            flag = 0;
                            break;
                        }
                    }
                }
                if (flag)
                    mn = min(mn, n - szz);
            }
        }
        cout << mn << nl;
    }
    return 0;
}
