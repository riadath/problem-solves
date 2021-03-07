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

int main()
{
    FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    ll n, k;
    cin >> n >> k;
    ll ln = n % 10, lk = n % 10;
    // cout << "Case " << kas++ << ": ";
    vector<int> lst;
    lst.pb((ln * lk) % 10);
    ln = (ln * lk) % 10;
    // cout << ln << nl;
    while ((ln * lk) % 10 != lst[0])
    {
        lst.pb((ln * lk) % 10);
        ln = (ln * lk) % 10;
    }
    // fl(i, 0, lst.size()) cout << lst[i] << nl;
    if (lst.size() == 1)
    {
        cout << lst[0] << nl;
    }
    else
    {
        ll rem = (k - 1) % (lst.size());
        if (rem == 0)
            cout << lst[lst.size() - 1] << nl;
        else
            cout << lst[rem - 1] << nl;
    }

    return 0;
}
