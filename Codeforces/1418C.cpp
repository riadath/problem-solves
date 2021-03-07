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

bool comp(const int &a, const int &b)
{
    return a > b;
}
int dp[200009][2], arr[200009], n;
int f(int i, int j)
{
    if (i >= n)
    {
        return 0;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    int a = 1e7, b = 1e7;
    if (j == 0)
    {
        a = (arr[i] == 1) + f(i + 1, 1);
        if (i + 1 < n)
            b = (arr[i] == 1) + (arr[i + 1] == 1) + f(i + 2, 1);
    }
    else if (j == 1)
    {
        a = f(i + 1, 0);
        b = f(i + 2, 0);
    }
    dp[i][j] = min(a, b);
    return dp[i][j];
}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        fl(i, 0, n) cin >> arr[i];
        fl(i, 0, n + 5) fl(j, 0, 2) dp[i][j] = -1;
        arr[n] = -1, arr[n + 1] = -1;
        int cnt = f(0, 0);
        cout << cnt << nl;
    }
    return 0;
}
