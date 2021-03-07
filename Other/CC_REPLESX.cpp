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
        ll n = 0, x = 0, k = 0, p = 0, cur_pos = -1;
        bool flag = 1;
        cin >> n >> x >> p >> k;
        ll arr[n + 1];
        fl(i, 1, n + 1)
        {
            cin >> arr[i];
            if (arr[i] == x)
            {
                flag = 0;
            }
        }
        sort(arr + 1, arr + n + 1);

        if (flag)
        {
            arr[k] = x;
            sort(arr + 1, arr + n + 1);
            fl(i, 1, n + 1)
            {
                if (arr[i] == x)
                {
                    cur_pos = i;
                    break;
                }
            }
        }
        if (arr[p] == x)
        {
            cout << flag << nl;
            continue;
        }
        if (!flag)
            fl(i, 1, n + 1)
            {
                if (arr[i] == x && cur_pos == -1)
                {
                    cur_pos = i;
                }
                if (arr[i] == x && cur_pos != -1)
                {
                    if (p > k)
                    {
                        if (i > p && cur_pos < p)
                            cur_pos = i;
                    }
                    else
                    {
                        if (i < p)
                        {
                            cur_pos = i;
                        }
                    }
                }
            }

        if ((cur_pos < p && p > k) || (cur_pos > p && p < k))
        {
            cout << -1 << nl;
            continue;
        }
        cout << abs(cur_pos - p) + flag << nl;
    }
    return 0;
}
