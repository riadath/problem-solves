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
#define srt(x) sort(x.begin(), x.end())
#define pi 3.141592653589793238
#define fi first
#define se second
#define all(a) a.begin(), a.end()

bool comp(const pii &a, const pii &b)
{
    return a.fi < b.fi;
}
ll n,k,dp[2009][2009];
ll mod = 1e9+7;

ll f(ll i,ll prev){
    // debug(i);
    // debug(prev);
    if(i >= k){
        return 1;
    }
    if(dp[i][prev] != -1)return dp[i][prev];
    ll a = 0;


    for(ll m = 1;m*prev <= n;m++){
        if(m*prev <= n)
            a += f(i + 1,m*prev);
        else break;
    }
    dp[i][prev] = (a)%mod;


    return dp[i][prev];

}
int main()
{
    FIO;
    #ifdef IHAVETOPEE 
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif


    cin>>n>>k;
    memset(dp,-1,sizeof(dp));
    ll ans = f(0,1)%mod;
    cout<<ans<<"\n";
    return 0;
}
