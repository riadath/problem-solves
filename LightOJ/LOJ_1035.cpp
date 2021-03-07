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
#define SIZE 2000
bool if_prime[SIZE];
void sieve()
{
    if_prime[0] = 1, if_prime[1] = 1;
    for (int i = 4; i < SIZE; i += 2)
        if_prime[i] = 1;
    for (int i = 3; i * i <= SIZE; i += 2)
    {
        for (int j = 2; i * j < SIZE; j++)
            if_prime[i * j] = 1;
    }
}

int main()
{
    sieve();
    // FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T, kas = 1;
    cin >> T;
    while (T--)
    {
        int n, flag = 0;
        cin >> n;
        int prime[1009];
        MEM(prime, 0);
        for (int k = 1; k <= n; k++)
        {
            int cur = k;
            for (int i = 2; i <= cur; i++)
            {
                if (!if_prime[i] && cur % i == 0)
                {
                    int cnt = 0;
                    while (cur % i == 0)
                    {
                        cnt++;
                        cur /= i;
                    }
                    prime[i] += cnt;
                }
            }
        }
        cout << "Case " << kas++ << ": ";
        cout << n << " = ";
        for (int i = 2; i <= n; i++)
        {
            if (prime[i] != 0)
            {
                if (flag)
                    cout << " * ";
                cout << i << sp << "(" << prime[i] << ")";
                flag = 1;
            }
        }
        cout << nl;
    }
    return 0;
}
