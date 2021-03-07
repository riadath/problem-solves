#include <bits/stdc++.h>
using namespace std;

#ifdef IHAVETOPEE
#include "debug.h"
#else
#define debug(args...)
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
    return a.fi < b.fi;
}
int n;
map<int,bool>avail;
set<int>arr;
map<int,ll>cnt;

ll dp[100009];
ll f(int i){
    if(i >= 1e5+1){
        return 0;
    }
    if(dp[i] != -1)return dp[i];
    ll a = 0,b = 0;
    a = (ll)cnt[i] * (ll)i + f(i + 2);
    b = f(i + 1);
    return dp[i] = max(a,b);
}
int main()
{
    MEM(dp,-1);
    FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    cin>>n;
    fl(i,0,n){
        int x;
        cin>>x;
        arr.insert(x);
        cnt[x]++;
    }
    cout<<f(1)<<nl;
    // ll tot = 0;
    // for(int i : arr){
    //     debug(i);
    //     if(!avail[i]){
    //         if(i * cnt[i] > (!avail[i-1] * cnt[i-1]*max(0,(i-1))+cnt[i+1]*(i+1))){
    //             debug(cnt[i]);
    //             tot += i*cnt[i];
    //             avail[i+1] =1 ,avail[i-1] = 1;
                
    //         }
    //         else{
    //             if(!avail[i-1] && cnt[i-1] != 0){
    //                 debug(i-1);
    //                 tot += max(0,i-1) * cnt[i-1];
    //                 avail[i] = 1; 
    //             }
    //         }
    //     }
    // }
    // cout<<tot<<nl;
    return 0;
}