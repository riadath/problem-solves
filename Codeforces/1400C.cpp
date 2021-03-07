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
#define all(a) a.begin(), a.end() cc

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
        int x, n;
        string s;
        cin >> s;
        cin >> x;
        n = s.size();
        string ans;
        fl(i, 0, n) ans.pb('1');
        fl(i, 0, n)
        {
            if (s[i] == '0')
            {
                if (i - x >= 0)
                    ans[i - x] = '0';
                if (i + x < n)
                    ans[i + x] = '0';
            }
        }
        bool flag = true;
        fl(i, 0, n)
        {
            bool flag_p = false;
            if (s[i] == '1')
            {
                if (i - x >= 0)
                    if (ans[i - x] == '1')
                        flag_p = true;
                if (i + x < n)
                    if (ans[i + x] == '1')
                        flag_p = true;
                if (!flag_p)
                {
                    flag = false;
                    break;
                }
            }
        }
        if (flag)
            cout << ans << nl;
        else
            cout << -1 << nl;
    }
    return 0;
}
