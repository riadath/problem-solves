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
        int n, x, y;
        cin >> n >> x >> y;
        // int cnt = 0;
        int cur_td = 1e9;
        vector<int> list;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if ((y - x) % (j - i) == 0)
                {
                    int td = (y - x) / (j - i);
                    if (x - i * td > 0)
                    {
                        // cnt++;
                        int st = x - i * td;
                        int fin = x - i * td + (n - 1) * td;
                        // cout << "FINAL : " << fin << nl;
                        if (fin < cur_td)
                        {
                            list.clear();
                            cur_td = fin;
                        }
                        fl(i, 0, n)
                        {
                            list.pb(st);
                            st += td;
                        }
                    }
                }
            }
        }
        fl(i, 0, n) cout << list[i] << sp;
        cout << nl;
    }
    return 0;
}
