#include <bits/stdc++.h>
using namespace std;
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
#define pi 2 * acos(0)
#define db double
#define fi first
#define se second
#define pi4 pair<pii, pii>
#define all(a) a.begin(), a.end()

bool comp(const pii &a, const pii &b)
{
    return a.second < b.second;
}
int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    cin >> n;
    int arr[n + 1];
    fl(i, 0, n) cin >> arr[i];
    int mn = 1e8, mx = 0, ans = 0;
    int l = 0, r = 0;
    while (r < n)
    {
        mn = min(arr[r], mn);
        mx = max(arr[r], mx);
        if (mx - mn > 1)
        {
            int t = arr[r];
            while (abs(arr[r - 1] - t) <= 1)
                r--;
            l = r;
            mn = arr[r];
            mx = arr[r];
        }
        else
            ans = max(ans, ++r - l);
    }
    cout << ans << nl;
    return 0;
}
