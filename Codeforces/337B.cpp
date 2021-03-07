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
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    lf(i, min(a, b), 2)
    {
        if (a % i == 0 && b % i == 0)
        {
            a /= i;
            b /= i;
        }
    }
    lf(i, min(c, d), 2)
    {
        if (c % i == 0 && d % i == 0)
        {
            c /= i;
            d /= i;
        }
    }
    /*if (a * b < c * d)
    {
        swap(a, c);
        swap(b, d);
    }*/
    // cout << a << sp << b << nl;
    // cout << c << sp << d << nl;
    ll p = a * b - c * d, q = a * b;
    ll r = a * b - c * d, s = a * b;
    long db t = ((a * 1.0) / c * d);
    if (t <= b)
    {
        p = b * c - a * d;
        q = b * c;
    }
    t = ((b * 1.0) / d * c);
    if (t <= a)
    {
        r = a * d - c * b;
        s = a * d;
        if (((p * 1.0) / q) >= ((r * 1.0) / s))
        {
            p = r;
            q = s;
        }
    }
    lf(i, min(p, q), 2)
    {
        if (p % i == 0 && q % i == 0)
        {
            p /= i;
            q /= i;
        }
    }
    cout << p << "/" << q << nl;
    return 0;
}