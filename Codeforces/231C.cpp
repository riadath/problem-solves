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
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    fl(i, 0, n) cin >> arr[i];
    sort(all(arr)), reverse(all(arr));
    ll i = 0, mn = 0, mnum = -1;
    vector<ll> sum(n + 1, oll);

    fl(i, 1, n + 1)
    {
        sum[i] = arr[i - 1] + sum[i - 1];
    }
    debug(arr);
    debug(sum);
    fl(j, 0, n)
    {
        ll tk = k, cnt = 1;
        if (i > j)
        {
            tk -= ((i - j) * arr[j] - (sum[i + 1] - sum[j + 1]));
            debug(sum[i + 1] - sum[j + 1]);
            cnt += (i - j);
        }
        debug(arr[j]);
        debug(tk);
        debug(cnt);
        int st = max(i + 1, j + 1);
        for (; tk >= 0 && st < n; st++)
        {
            if (tk - (arr[j] - arr[st]) >= 0 && st < n)
            {
                tk -= arr[j] - arr[st];
                cnt++;
                i = st;
            }
            else
            {
                break;
            }
        }
        debug(cnt);
        if (cnt >= mn)
        {
            mn = cnt;
            mnum = arr[j];
        }
    }
    cout << mn << sp << mnum << nl;
    return 0;
}
