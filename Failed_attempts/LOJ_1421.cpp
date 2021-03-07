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
int n;
int arr[100109], dp1[100109], dp2[100109];

int main()
{
    // FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T, kas = 1;
    scanf("%d", &T);
    while (T--)
    {
        MEM(dp1, 0), MEM(dp2, 0);
        scanf("%d", &n);
        fl(i, 0, n) scanf("%d", &arr[i]);
        dp1[0] = 1;
        int cur = 1, cur_mx = arr[0];
        fl(i, 1, n)
        {
            if (arr[i] > arr[i - 1])
            {
                cur++;
                if (arr[i] > cur_mx)
                {
                    dp1[i] = max(cur, dp1[i - 1] + 1);
                }
                else
                    dp1[i] = max(cur, dp1[i - 1]);
            }
            else
            {
                dp1[i] = dp1[i - 1];
                if (arr[i] != arr[i + 1])
                    cur = 1;
                cur_mx = max(cur_mx, arr[i]);
            }
        }
        fl(i, 0, n) cout << "->" << arr[i] << sp << dp1[i] << nl;
        dp2[n - 1] = 1;
        cur = 1;
        cur_mx = arr[n - 1];
        lf(i, n - 2, 0)
        {
            // cout << "++> " << arr[i] << sp << arr[i + 1] << sp << cur << nl;
            if (arr[i] > arr[i + 1])
            {
                cur++;
                if (arr[i] > cur_mx)
                {
                    dp2[i] = max(cur, dp2[i + 1] + 1);
                }
                else
                    dp2[i] = max(cur, dp2[i + 1]);
            }
            else
            {
                dp2[i] = dp2[i + 1];
                if (arr[i] != arr[i + 1])
                    cur = 1;
                cur_mx = max(cur_mx, arr[i]);
            }
        }
        // cout << "===\n";
        lf(i, n - 1, 0) cout << "=>" << arr[i] << sp << dp2[i] << nl;
        int mx = 0;
        fl(i, 1, n - 1)
        {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
            {
                int temp = 2 * min(dp1[i], dp2[i]) - 1;
                mx = max(mx, temp);
            }
        }
        printf("Case %d: ", kas++);
        printf("%d\n", max(1, mx));
    }
    return 0;
}
