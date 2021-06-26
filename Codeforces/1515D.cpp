#include <bits/stdc++.h>
using namespace std;
#ifdef IHAVETOPEE
#include "debug.h"
#else
#define debug(args)
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
#define fl(i, a, b) for (ll i = (int)a; i < (int)b; i++)
#define lf(i, b, a) for (ll i = (int)b; i >= (int)a; i--)
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
    return a.se < b.se;
}

int main()
{
    FIO;
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        int n, l, r;
        cin >> n >> l >> r;
        vector<pii> arr, brr;
        vector<int> lcnt(n + 1, 0), rcnt(n + 1, 0);

        fl(i, 0, l + r){
            int x;
            cin >> x;
            if (i < l) {
                lcnt[x]++;
            }
            else {
                rcnt[x]++;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (lcnt[i] && rcnt[i]) {
                int p = min(lcnt[i], rcnt[i]);
                rcnt[i] -= p, lcnt[i] -= p;
            }
        }

        int money = 0;

        fl(i,1,n + 1)if(lcnt[i])arr.pb(mp(i,lcnt[i]));
        fl(i,1,n + 1)if(rcnt[i])brr.pb(mp(i,rcnt[i]));
        sort(all(arr),comp),sort(all(brr),comp);
        
        int sum1 = 0,sum2 = 0;
        fl(i,0,arr.size())sum1 += arr[i].se;
        fl(i,0,brr.size())sum2 += brr[i].se;
        if (sum1 < sum2)swap(arr, brr),swap(sum1,sum2);

        fl(i,0,arr.size()){
            money += min((arr[i].se/2) * 2,sum1 - sum2)/2;
            sum1 -= min((arr[i].se/2) * 2,sum1 - sum2);
        }

        cout << money + sum1 << nl;
    }
    return 0;
}
