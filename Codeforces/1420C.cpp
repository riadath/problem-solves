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
#define pi 3.141592653589793238
#define db double
#define fi first
#define se second
#define pi4 pair<pii, pii>
#define all(a) a.begin(), a.end()

bool comp(const pii &a, const pii &b)
{
    return a.second > b.second;
}

ll dp[300009][3];
ll n, arr[300009];
ll f(int i, int op)
{
    if (i >= n)
        return 0;
    if (dp[i][op] != -1)
        return dp[i][op];
    ll a = 0, b = 0;
    a = f(i + 1, op);
    ll add;
    if (op == 0)
        add = arr[i];
    if (op == 1)
        add = -arr[i];
    b = add + f(i + 1, !op);
    return dp[i][op] = max(a, b);
}

int main()
{
    FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int T, kas = 1;
    cin >> T;
    while (T--)
    {
        MEM(dp, -1);
        int q;
        cin >> n >> q;
        fl(i, 0, n) cin >> arr[i];
        ll mx = f(0, 0);
        cout << mx << nl;
    }
    return 0;
}
