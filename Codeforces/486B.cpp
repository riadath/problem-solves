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
    return a.second < b.second;
}

int main()
{
    FIO;
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    int n, m;
    cin >> n >> m;

    int arr[n][m], ans[n][m], chk[n][m];
    MEM(chk, 0);
    MEM(ans, -1);
    fl(i, 0, n) fl(j, 0, m)
    {
        int t;
        cin >> t;
        arr[i][j] = t;
        if (!t)
        {
            fl(k, 0, m) ans[i][k] = 0;
            fl(k, 0, n) ans[k][j] = 0;
        }
    }
    fl(i, 0, n) fl(j, 0, m)
    {
        if (ans[i][j] == -1)
        {
            ans[i][j] = 1;
            fl(k, 0, m) chk[i][k] = 1;
            fl(k, 0, n) chk[k][j] = 1;
        }
    }
    bool flag = true;
    fl(i, 0, n)
    {
        fl(j, 0, m)
        {
            if (chk[i][j] != arr[i][j])
            {
                flag = false;
                break;
            }
        }
        if (!flag)
            break;
    }
    if (flag)
    {
        cout << "YES" << nl;
        fl(i, 0, n)
        {
            fl(j, 0, m) cout << ans[i][j] << sp;
            cout << nl;
        }
    }
    else
    {
        cout << "NO" << nl;
    }
    return 0;
}
