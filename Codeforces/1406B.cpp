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
int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<ll> neg, pos, list;
        fl(i, 0, n)
        {
            ll temp;
            cin >> temp;
            if (temp < 0)
                neg.pb(temp);
            else
                pos.pb(temp);
        }
        srt(neg), srt(pos);
        if (n >= 5)
        {
            ll ret = 1;
            if (n == 5)
            {
                fl(i, 0, neg.size())
                {
                    ret *= neg[i];
                }
                fl(i, 0, pos.size())
                {
                    ret *= pos[i];
                }
                list.pb(ret);
            }
            ret = 1;
            if (neg.size() >= 5)
            {
                lf(i, neg.size() - 1, neg.size() - 5)
                {
                    ret *= neg[i];
                }
                list.pb(ret);
            }
        }
        if (pos.size() >= 1 && neg.size() >= 4)
        {
            ll ret = 1;
            ret *= pos[pos.size() - 1];
            fl(i, 0, 4)
            {
                // cout << neg[i] << nl;
                ret *= neg[i];
            }
            list.pb(ret);
            // cout << "++>" << ret << nl;
        }
        if (pos.size() >= 3 && neg.size() >= 2)
        {
            ll ret = 1;
            lf(i, pos.size() - 1, pos.size() - 1 - 2)
            {
                ret *= pos[i];
            }
            ret *= neg[0] * neg[1];
            list.pb(ret);
        }
        if (pos.size() >= 5)
        {
            ll ret = 1;
            lf(i, pos.size() - 1, pos.size() - 1 - 4)
            {
                ret *= pos[i];
            }
            list.pb(ret);
        }
        ll mx = -1e18;
        fl(i, 0, list.size())
        {
            // cout << "->>" << list[i] << nl;
            mx = max(mx, list[i]);
        }
        cout << mx << nl;
    }
    return 0;
}
