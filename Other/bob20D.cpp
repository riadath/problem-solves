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
#define SIZE 1000009
// vector<int> prime_list;
int prime[1000009];
void sieve()
{
    prime[0] = 1, prime[1] = 1;
    for (int i = 4; i < SIZE; i += 2)
        prime[i] = 1;
    for (int i = 3; i * i <= SIZE; i += 2)
    {
        for (int j = 2; i * j < SIZE; j++)
            prime[i * j] = 1;
    }
    //     for (int i = 2; i < SIZE)
    //         if (!prime[i])
    //             prime_list.pb(i);
}
int main()
{
    sieve();
    // FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T, kas = 1;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        if (!prime[n])
        {
            cout << n << nl;
            continue;
        }
        int ctu = 0, ctd = 0, up, down;
        for (int i = n + 1; i < SIZE; i++)
        {
            ctu++;
            if (!prime[i])
            {
                up = i;
                break;
            }
        }
        for (int i = n - 1; i >= 2; i--)
        {
            ctd++;
            if (!prime[i])
            {
                down = i;
                break;
            }
        }
        if (ctu < ctd)
            cout << up << nl;
        else if (ctu >= ctd)
            cout << down << nl;
        // printf("Case %d: ", kas++);
    }
    return 0;
}
