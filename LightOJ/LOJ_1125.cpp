#include <bits/stdc++.h>
using namespace std;

#ifdef IHAVETOPEE
#include "debug.h"
#else
#define debug(args)
#endif

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

ll n,q,d,m, arr[209], dp[209][20][21];

ll f(int i,int cnt,int rem)
{
    if(rem < 0)rem += d;
    if(cnt == m){
        return (rem == 0);
    }
    if(i >= n){
        return ((cnt == m) && (rem == 0));
    }

    ll &ret = dp[i][cnt][rem];
    if(ret != -1)return ret;

    ll aa = f(i + 1,cnt+1,(arr[i] + rem)%d);
    ll bb = f(i + 1,cnt,rem);
    
    ret = (aa + bb);
    return ret;
}

int main()
{
    // FIO;

    #ifdef IHAVETOPEE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    int T, kas = 1;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lld %lld",&n,&q);
        fl(i,0,n)scanf("%lld",&arr[i]);

        printf("Case %d:\n", kas++);

        while(q--){
            MEM(dp,-1);
            scanf("%lld %lld",&d,&m);
            ll ans = f(0,0,0);
            printf("%lld\n",ans);
        }   
    }
    return 0;
}
