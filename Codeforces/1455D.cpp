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

bool chek_sorted(vector<int> brr)
{
    vector<int> cpy = brr;
    sort(all(cpy));
    fl(i, 0, brr.size())
    {
        if (brr[i] != cpy[i])
            return false;
    }
    return true;
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
        int n, x, mx = 0;
        cin >> n >> x;
        vector<int> arr;
        fl(i, 0, n)
        {
            int pp;
            cin >> pp, arr.pb(pp);
            mx = max(pp, mx);
        }
        bool flag = chek_sorted(arr);
        if (flag)
        {
            cout << 0 << nl;
            continue;
        }
        if (x >= mx)
        {
            cout << -1 << nl;
            continue;
        }
        int cnt = 0;
        while (true)
        {
            bool flag = true;
            if (x < arr[0])
            {
                swap(x, arr[0]);
                flag = false;
            }
            else
            {
                fl(i, 1, n - 1)
                {
                    if (arr[i] > x && x >= arr[i - 1] && x <= arr[i + 1])
                    {
                        flag = false;
                        swap(arr[i], x);
                        break;
                    }
                }
            }
            cnt++;
            // fl(i, 0, n) cout << arr[i] << " \n"[i == n - 1];
            if (chek_sorted(arr))
                break;
            if (flag)
            {
                cnt = -1;
                break;
            }
        }
        cout << cnt << nl;
    }
    return 0;
}
