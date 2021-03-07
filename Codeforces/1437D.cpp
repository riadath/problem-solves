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
        int arr[n + 10];
        MEM(arr, 0);
        fl(i, 0, n) cin >> arr[i];
        int l = 1, cnt = 0, cur = 0, new_cnt = 0, flg = 1;
        while (l < n)
        {
            if (arr[l] > arr[l - 1])
            {
                cnt++;
                while (arr[l] > arr[l - 1])
                {
                    if (l < n)
                    {
                        if (arr[l] > arr[l - 1])
                            l++, cur++;
                    }
                    else
                        break;
                }
            }
            else if (arr[l] < arr[l - 1])
            {
                // cout << "->" << cur << sp << new_cnt << nl;
                l++, cur--, new_cnt++;
                if (flg)
                {
                    cnt++, flg = 0;
                }
                if (l < n)
                {
                    while (arr[l] > arr[l - 1])
                    {
                        if (l < n)
                        {
                            if (arr[l] > arr[l - 1])
                                l++, new_cnt++;
                        }
                        else
                            break;
                    }
                }
                if (cur == 0)
                {
                    cur = new_cnt, new_cnt = 0, flg = 1;
                }
            }
        }
        cout << cnt << nl;
    }
    return 0;
}
