#include <bits/stdc++.h>
using namespace std;

#ifdef IHAVETOPEE
#include "debug.h"
#else
#define debug(args)
#endif

#define ll long long
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define lcm(a, b) a *b / __gcd(a, b)
#define fl(i, a, b) for (ll i = (int)a; i < (int)b; i++)
#define MEM(x, y) memset(x, y, sizeof(x))
#define PI acos(0)*2
#define fi first
#define se second
#define all(a) a.begin(), a.end()

bool comp(const pii &a, const pii &b){return a.fi < b.fi;}
ll mod = 1e9 + 7;
ll n,dp[2000009];
ll f(ll sum){
    if(sum >= n){
        return sum == n;
    }
    ll &ret = dp[sum];
    if(ret != -1)return ret;
    ret = 0;
    for(int i = 0;i <= 6;i++){
        ret += f(sum + i)%mod;
    }
    return ret%mod;
}   

int main()
{
    FIO;
    #ifdef IHAVETOPEE 
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    cin>>n;
    MEM(dp,-1);
    cout<<f(0)<<"\n";


    return 0;
}
