#include <bits/stdc++.h>
using namespace std;
#ifdef IHAVETOPEE
#include "debug.h"
#else
#define debug(args...)
#endif

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
int cnt[200009];
set<int> pls_notle;
int main()
{
    FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        MEM(cnt, 0);
        int n;
        cin >> n;
        int arr[n + 1];
        fl(i, 0, n) cin >> arr[i];
        fl(i, 0, n)
        {
            cnt[arr[i]]++;
            pls_notle.insert(arr[i]);
        }
        // int other = 0, canc = 0;
        for (int i : pls_notle)
        {
            // debug(i);
            if (cnt[i] > 1)
            {
                // debug(i);
                cnt[i + 1]++, cnt[i]--;
            }
        }
        int cctt = 0;
        fl(i, 0, 2 * n + 10)
        {
            if (cnt[i] != 0)
                cctt++;
            // debug(cnt[i]);
        }
        // int tot = (int)pls_notle.size() + other;
        cout << cctt << nl;
        pls_notle.clear();
    }
    return 0;
}
