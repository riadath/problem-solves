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

bool comp(const pll &a, const pll &b)
{
    return a.se > b.se;
}
#define SZ 100009
int prime[100009];
void sieve()
{
    prime[0] = 1, prime[1] = 1;
    for (int i = 4; i < SZ; i += 2)
        prime[i] = 1;
    for (int i = 3; i * i <= SZ; i += 2)
    {
        for (int j = 2; i * j < SZ; j++)
            prime[i * j] = 1;
    }
}

int main()
{
    FIO;
    sieve();
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        ll n, svn;
        cin >> n;
        svn = n;
        vector<pll> factor;
        for (ll i = 2; i * i <= n; i += 1)
        {
            // cout << i << nl;
            if (!prime[i] && n % i == 0)
            {
                ll cnt = 0;
                // cout << "=>" << svn << "---->" << i << nl;
                while (n % i == 0)
                {
                    cnt++;
                    n /= i;
                }
                factor.pb(mp(i, cnt));
            }
        }

        if (n != 1)
        {
            factor.pb(mp(n, 1));
        }
        sort(all(factor), comp);
        ll div = 1;
        vector<ll> ans;
        fl(i, 0, factor[0].se - 1)
        {
            ans.pb(factor[0].fi);
            div *= factor[0].fi;
        }
        ans.pb(svn / div);
        cout << ans.size() << nl;
        fl(i, 0, ans.size()) cout << ans[i] << sp;
        cout << nl;
    }
    return 0;
}
