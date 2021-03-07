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

int string_to(string temp)
{
    int num = 0;
    fl(i, 0, temp.size())
    {
        num *= 10;
        num += temp[i] - '0';
    }
    return num;
}

int main()
{
    // FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T, kas = 1;
    scanf("%d", &T);
    while (T--)
    {
        int n, k;
        scanf("%d %d", &n, &k);
        for (int i = 0; i < k; i++)
        {
            string temp = to_string(n);
            // cout << temp << nl;
            if (temp.size() < 4)
            {
                while ((int)temp.size() != 4)
                    temp = '0' + temp;
            }
            // cout << temp << nl;
            sort(all(temp));
            int smol = string_to(temp);
            reverse(all(temp));
            int big = string_to(temp);
            // cout << big - smol << nl;
            if (big - smol == n)
                break;
            n = big - smol;
        }
        // printf("Case %d: ", kas++);
        printf("%d\n", n);
    }
    return 0;
}
