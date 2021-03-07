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

bool comp(const pair<pii, int> &a, const pair<pii, int> &b)
{
    return a.se > b.se;
}
int dirx[] = {1, -1, 0, 0};
int diry[] = {0, 0, 1, -1};
int mat[20][20], n, m;

int main()
{
    FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        int cur_sum = 0, les = 0;
        int mn = 1e8;
        fl(i, 0, n) fl(j, 0, m)
        {
            cin >> mat[i][j];
            cur_sum += abs(mat[i][j]);
            if (mat[i][j] <= 0)
                les++;
            mn = min(mn, abs(mat[i][j]));
        }
        if (les % 2 == 0)
        {
            cout << cur_sum << nl;
        }
        else
        {
            cout << cur_sum - 2 * mn << nl;
        }
    }
    return 0;
}
