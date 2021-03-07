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
    string a, b;
    cin >> a >> b;
    int slen = a.size();
    ll sum = 0;
    int zero[b.size() + 10], one[b.size() + 1];
    MEM(zero, 0), MEM(one, 0);
    if (b[0] == '0')
    {
        zero[0] = 1;
    }
    else
        one[0] = 1;
    fl(i, 1, b.size())
    {
        if (b[i] == '0')
        {
            zero[i] = zero[i - 1] + 1;
            one[i] = one[i - 1];
        }
        else
        {
            one[i] = one[i - 1] + 1;
            zero[i] = zero[i - 1];
        }
    }
    // fl(i, 0, b.size())
    // {
    //     cout << i << sp << zero[i] << sp << one[i] << nl;
    // }
    fl(i, 0, a.size())
    {
        int t = a.size() - i - 1;
        if (a[i] == '0')
        {
            int cnt = 0;
            if (i == 0)
                cnt = one[b.size() - 1 - t];
            else
                cnt = one[b.size() - 1 - t] - one[i - 1];
            sum += cnt;
        }
        else
        {
            int cnt = 0;
            if (i == 0)
                cnt = zero[b.size() - 1 - t];
            else
                cnt = zero[b.size() - 1 - t] - zero[i - 1];
            sum += cnt;
        }
    }
    cout << sum << nl;
    return 0;
}
