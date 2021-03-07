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
ll arr[100109], degree[100109];
bool comp(const ll &a, const ll &b)
{
    return a > b;
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
        MEM(degree, 0);
        ll n, sum = 0;
        cin >> n;
        fl(i, 0, n) cin >> arr[i + 1], sum += arr[i + 1];
        vector<pii> edges(n + 1);
        vector<ll> detum, ans;
        fl(i, 0, n - 1)
        {
            cin >> edges[i].fi >> edges[i].se;
            degree[edges[i].fi]++, degree[edges[i].se]++;
        }
        fl(i, 1, n + 1) fl(j, 1, degree[i]) detum.pb(arr[i]);
        sort(all(detum), comp);
        // debug(detum);
        ans.pb(sum);
        fl(i, 0, n - 2)
        {
            sum += detum[i];
            ans.pb(sum);
        }
        sort(all(ans));
        // debug(ans);
        fl(i, 0, ans.size()) cout << ans[i] << sp;
        cout << nl;
    }
    return 0;
}
