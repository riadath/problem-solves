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
#define SIZE 10000009
bool prime[SIZE + 100];
vector<ll> list_prime;
void sieve()
{
    prime[0] = 1, prime[1] = 1;
    for (ll i = 2; i * i <= SIZE; i++)
    {
        if (!prime[i])
        {
            for (ll j = i * i; j <= SIZE; j += i)
            {
                prime[j] = 1;
            }
        }
    }
    fl(i, 2, SIZE) if (!prime[i]) list_prime.pb(i);
}

int main()
{
    FIO;
    sieve();
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ll n;
    // cin >> n;
    while (cin >> n)
    {
        if (n < 8)
        {
            cout << "Impossible." << nl;
            continue;
            // return 0;
        }
        ll tt = n - 6, tw = 2, tr = 2, fr = 2;
        ll cur = 2, st = 1;
        bool flag = prime[tt];
        while (prime[tt] && tt > 1)
        {
            ll diff = list_prime[st++] - cur;
            if (!prime[cur + diff])
            {
                if (!prime[tt - diff])
                {
                    flag = false;
                    tt -= diff, tw += diff;
                    break;
                }
                else if (!prime[tt - 2 * diff])
                {
                    flag = false;
                    tt -= 2 * diff, tw += diff, tr += diff;
                    break;
                }
                else if (!prime[tt - 3 * diff])
                {
                    flag = false;
                    tt -= 3 * diff, tw += diff, tr += diff, fr += diff;
                    break;
                }
            }
            if (st >= (int)list_prime.size())
                break;
        }
        if (flag)
            cout << "Impossible." << nl;
        else
            cout << tt << sp << tw << sp << tr << sp << fr << nl;
    }
    return 0;
}
