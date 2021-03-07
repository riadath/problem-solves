#include <bits/stdc++.h>
using namespace std;

// #ifdef IHAVETOPEE
// #include "debug.h"
// #else
// #define debug(args...)
// #endif

// #pragma GCC target("avx2")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
int n, cur_mx = 0, arr[200009];
int LIS[200009], LDS[200009];
int INF[200109], INFF[200109];
void LONGEST()
{
    fl(i, 0, n)
    {
        int pos = lower_bound(INF, INF + n + 1, arr[i]) - INF;
        INF[pos] = arr[i], LIS[i] = pos;
    }
    lf(i, n - 1, 0)
    {
        int lo = 0, hi = cur_mx;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (INFF[mid] < arr[i])
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        INFF[lo] = arr[i];
        LDS[i] = lo;
        if (cur_mx < lo)
            cur_mx = lo;
    }
}
int main()
{
    // FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int kas = 1, T;
    scanf("%d", &T);
    while (T--)
    {
        MEM(LIS, 0);
        MEM(LDS, 0);
        scanf("%d", &n);
        fl(i, 0, n) scanf("%d", &arr[i]);
        fl(i, 0, n + 1) INF[i] = INT_MAX, INFF[i] = INT_MAX;
        INF[0] = -INT_MAX, INFF[0] = -INT_MAX;
        LONGEST();
        // fl(i, 0, n) cout << LIS[i] << " \n"[i == n - 1];
        // fl(i, 0, n) cout << LDS[i] << " \n"[i == n - 1];
        int mx = 1;
        fl(i, 0, n)
        {
            mx = max(mx, (min(LIS[i], LDS[i]) - 1) * 2 + 1);
        }
        printf("Case %d: %d\n", kas++, mx);
    }
    return 0;
}