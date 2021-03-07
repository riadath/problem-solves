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
    int n;
    cin >> n;
    vector<int> arr;
    fl(i, 0, n)
    {
        int x;
        cin >> x, arr.pb(x);
    }
    srt(arr), reverse(all(arr));
    bool flag = true;
    int st, en = n / 2 + (n % 2 != 0), mxx = 0;
    while (arr[mxx] == arr[0])
        mxx++;
    en = max(en, mxx);
    st = en - 1;
    int leg = n - 1;
    // int len = en;
    vector<int> ans;
    while (st >= 0 && leg >= en)
    {
        if (flag)
        {
            // cout << arr[st] << nl;
            ans.pb(arr[st--]);
            flag = !flag;
        }
        else if (!flag)
        {
            // cout << arr[en] << nl;
            ans.pb(arr[leg--]);
            flag = !flag;
        }
    }
    while (st >= 0)
        ans.pb(arr[st--]);
    while (leg >= en)
        ans.pb(arr[en++]);
    int cnt = 0;
    fl(i, 1, n - 1) if (ans[i] < ans[i - 1] && ans[i] < ans[i + 1]) cnt++;
    cout << cnt << nl;
    fl(i, 0, n) cout << ans[i] << " \n"[i == n - 1];
    return 0;
}
