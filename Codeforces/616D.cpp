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
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n + 10];
    fl(i, 0, n) scanf("%d", &arr[i]);
    int st = 0, en = -1, cur_size = 0, ast = 1, een = 1, took = 0;
    map<int, int> count;
    while (true)
    {
        // cout << st + 1 << sp << en + 1 << nl;
        if (took < k)
        {
            if (en == n - 1)
                break;
            en++;
            if (count[arr[en]] == 0)
                took++;
            count[arr[en]]++;
            if (en - st + 1 > cur_size && took <= k)
            {
                cur_size = en - st + 1;
                ast = st + 1, een = en + 1;
            }
        }
        else if (took == k)
        {
            if (en < n - 1)
            {
                while (count[arr[en + 1]] != 0)
                {
                    // cout << "=>" << en + 1 << sp << arr[en] << nl;
                    if (en < n - 1)
                    {
                        count[arr[en + 1]]++;
                        en++;
                    }
                    else
                        break;
                }
            }
            if (en - st + 1 > cur_size && took <= k)
            {
                cur_size = en - st + 1;
                ast = st + 1, een = en + 1;
            }
            while (count[arr[st]] >= 2)
            {
                count[arr[st]]--;
                st++;
            }
            count[arr[st]]--, took--, st++;
        }
    }
    cout << ast << sp << een << nl;
    return 0;
}
