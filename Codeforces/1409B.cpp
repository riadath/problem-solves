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
    int T;
    cin >> T;
    while (T--)
    {
        ll a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;
        ll dma = a - x, dmb = b - y;
        if (dma + dmb <= n)
        {
            // cout << "-> " << a << sp << b << nl;
            cout << (a - dma) * (b - dmb) << nl;
        }
        else
        {
            vector<ll> list;
            if (dma >= n)
            {
                list.pb((a - n) * b);
            }
            if (dmb >= n)
            {
                list.pb((b - n) * a);
            }
            list.pb((a - min(dma, n)) * (b - max(oll, (n - min(dma, n)))));
            list.pb((b - min(dmb, n)) * (a - max(oll, (n - min(dmb, n)))));
            ll mn = 1e18;
            fl(i, 0, list.size())
            {
                // cout << list[i] << "-";
                mn = min(mn, list[i]);
            }
            // cout << nl;
            cout << mn << nl;
        }
    }
    return 0;
}
