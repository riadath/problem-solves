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

int main()
{
    FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    string str;
    cin >> str;
    int m, to_ad[str.size() + 100];
    MEM(to_ad, 0);
    cin >> m;
    vector<int> arr;
    map<int, bool> chek;
    fl(i, 0, m)
    {
        int x;
        cin >> x;
        if (!chek[x - 1])
        {
            arr.pb(x - 1);
            chek[x - 1] = true;
        }
        to_ad[x - 1] += 1;
    }
    srt(arr);
    int ad = 0, cur = 0;
    int ar2[str.size() + 100];
    MEM(ar2, 0);
    fl(i, 0, str.size() / 2)
    {
        // cout << ad << sp << cur << nl;
        if (cur < (int)arr.size())
            if (i == arr[cur])
            {
                cur++, ad += to_ad[i];
            }
        ar2[i] += ad;
        ar2[str.size() - i - 1] += ad;
        // cout << str[i] << sp << ar2[i] << nl;
    }
    fl(i, 0, str.size())
    {
        // cout << str[i] << sp << ar2[i] << nl;
        if (ar2[i] % 2 == 0)
            cout << str[i];
        else
            cout << str[str.size() - i - 1];
    }
    cout << nl;
    return 0;
}
