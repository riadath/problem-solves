#include <bits/stdc++.h>
using namespace std;

// #ifdef IHAVETOPEE
// #include "debug.h"
// #else
// #define debug(args...)
// #endif

// #pragma GCC target("avx2")
// #pragma GCC optimization("O3")
// #pragma GCC optimization("unroll-loops")

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
    return a.fi < b.fi;
}

string add_string(string a, string b)
{
    if (a.size() > b.size())
        swap(a, b);

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    string total = "";
    int carry = 0;
    fl(i, 0, a.size())
    {
        int temp;
        temp = a[i] - '0' + b[i] - '0' + carry;
        //cout<<temp<<endl;
        total.pb(temp % 10 + '0');
        carry = temp / 10;
    }
    if (a.size() != b.size())
    {
        fl(i, a.size(), b.size())
        {
            int temp = b[i] - '0' + carry;
            total.pb(temp % 10 + '0');
            carry = temp / 10;
        }
    }
    while (carry != 0)
    {
        total.pb(carry % 10 + '0');
        carry /= 10;
    }
    reverse(total.begin(), total.end());
    return total;
}

string multiply(string a, string b)
{
    if (a.size() < b.size())
        swap(a, b);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    string total = "";
    int carry = 0;
    fl(i, 0, b.size())
    {
        string res = "";
        fl(j, 0, a.size())
        {
            int temp = (a[j] - '0') * (b[i] - '0') + carry;
            res.pb(temp % 10 + '0');
            carry = temp / 10;
        }
        while (carry != 0)
        {
            res.pb(carry % 10 + '0');
            carry = carry / 10;
        }
        if (total.size() == 0)
        {
            total = res;
            reverse(all(total));
            // cout << total << nl;
        }
        else
        {
            reverse(res.begin(), res.end());
            // reverse(total.begin(), total.end());
            for (int p = 0; p < i; p++)
                res.pb('0');
            // cout << res << " " << total << endl;
            total = add_string(res, total);
            //cout<<total<<endl;
        }
    }
    // reverse(total.begin(), total.end());
    return total;
}

int main()
{
    FIO;
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    string a = "12", b = "12";
    cout << multiply(a, b) << nl;
    return 0;
}
