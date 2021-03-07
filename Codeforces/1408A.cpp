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

int main()
{
    FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T, kas = 1;
    cin >> T;
    while (T--)
    {
        int a[200], b[200], c[200];
        int n;
        cin >> n;
        fl(i, 0, n) cin >> a[i];
        fl(i, 0, n) cin >> b[i];
        fl(i, 0, n) cin >> c[i];
        vector<int> p;
        fl(i, 0, n)
        {
            if (i == 0)
                p.pb(a[i]);
            else if (i == n - 1)
            {
                if (p[0] != a[i] && p[i - 1] != a[i])
                    p.pb(a[i]);
                else if (p[0] != b[i] && p[i - 1] != b[i])
                    p.pb(b[i]);
                else
                    p.pb(c[i]);
            }
            else
            {
                if (p[i - 1] != a[i])
                    p.pb(a[i]);
                else if (p[i - 1] != b[i])
                    p.pb(b[i]);
                else
                    p.pb(c[i]);
            }
        }
        fl(i, 0, n) cout << p[i] << sp;
        cout << nl;
    }
    return 0;
}
