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
    ll arr[n + 1];
    fl(i, 0, n) cin >> arr[i];
    sort(arr, arr + n);
    ll f1 = 0;
    fl(i, 0, n)
    {
        f1 += abs(arr[i] - 1);
    }
    ll ans = f1;
    fl(i, 2, 100009)
    {
        ll pw = 1, cost = 0;
        fl(j, 0, n)
        {
            //cout << pw << nl;
            cost += abs(arr[j] - pw);
            if (pw * i <= 1e18 && pw * i >= 0)
                pw *= i;
            else
                pw = 1e18;
        }
        pw /= i;
        // cout << pw << nl;
        if (pw > f1 + arr[n - 1] || pw == 1e18)
            break;
        ans = min(ans, cost);
    }
    cout << ans << nl;
    return 0;
}
