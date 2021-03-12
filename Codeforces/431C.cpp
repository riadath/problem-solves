#include <bits/stdc++.h>
using namespace std;

#ifdef IHAVETOPEE
#include "debug.h"
#else
#define debug(args)
#endif

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
    if(a.fi == b.fi)return a.se > b.se;
    return a.fi < b.fi;
}

int n,k,d;
ll mod = 1e9 + 7,dp[109][109];
ll f(int sum,int cur){
    // cout<<sp<<sum<<sp<<cur<<nl;
    if(sum >= n){
        return (sum == n && cur >= d);
    }
    ll &ret = dp[sum][cur];
    if(ret != -1)return ret;
    ll a = 0,b = 0;
    for(int l = 1;l <= k;l++)
        a += f(sum + l,max(cur,l))%mod;
    return ret = (a + b)%mod;
}
int main()
{
    FIO;
    MEM(dp,-1);
    cin>>n>>k>>d;
    cout<<f(0,0)%mod<<nl;
    return 0;
}