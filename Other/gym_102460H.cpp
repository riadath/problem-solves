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
    int T;
    cin >> T;
    while (T--)
    {
        ll n;
        cin >> n;
        ll temp = n * (n + 1);
        ll temp2 = n + 1;
        string bit1 = "", bit2 = "";
        while (temp != 0)
        {

            bit1 += '0' + temp % 2;
            temp /= 2;
        }
        while (temp2 != 0)
        {
            bit2 += '0' + temp2 % 2;
            temp2 /= 2;
        }

        int diff = bit1.size() - bit2.size();
        fl(i, 0, diff)
        {
            bit2 += "0";
        }
        reverse(all(bit1));
        reverse(all(bit2));
        // cout << bit1 << sp << bit2 << nl;
        string ans = "";
        fl(i, 0, bit1.size())
        {
            if (bit2[i] == '0' && bit1[i] == '1')
            {
                ans.pb('1');
            }
            else if (bit2[i] == '1' && bit1[i] == '0')
            {
                ans.pb('1');
            }
            else if (bit2[i] == '0' && bit1[i] == '0')
            {
                ans.pb('0');
            }
            else if (bit2[i] == '1' && bit1[i] == '1')
            {
                ans.pb('0');
            }
        }
        ll res = 0;
        ll mul = 1;
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            ll t = ans[i] - '0';
            res += t * mul;
            mul *= 2;
        }
        cout << res << nl;
    }
    return 0;
}