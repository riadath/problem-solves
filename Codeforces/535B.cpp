#include <bits/stdc++.h>
using namespace std;
#ifdef IHAVETOPEE
#include "debug.h"
#else
#define debug(args...)
#endif

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
int n;
ll ans = 0, countr = 0, st = 2;
static ll cnt = 0;
string str, temp = "";
void f(int i)
{
    if (i >= n)
    {
        cnt++;
        // cout << temp << nl;
        if (temp == str)
        {
            // cout << "=>" << cnt << nl;
            cout << countr + cnt << nl;
            exit(0);
        }
        return;
    }
    // ll a = 0, b = 0;
    temp += '4';
    f(i + 1);
    temp.erase(temp.size() - 1);
    temp += '7';
    f(i + 1);
    temp.erase(temp.size() - 1);
}
int main()
{
    FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    cin >> str;
    n = str.size();
    fl(i, 1, n)
    {
        countr += st;
        st *= 2;
    }
    f(0);
    return 0;
}
