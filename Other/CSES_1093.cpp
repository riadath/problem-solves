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
ll n, sum, arr[509],dp[500][62625];

ll f(int i, int sm)
{
    if (i == n-1 || sm <= 0) {
        return (sm == 0);
    }
    ll &ret = dp[i][sm];
    if(ret != -1)return ret;

    ll a = 0,b = 0;
    b = f(i + 1, sm);
    if (sm - arr[i] >= 0)a = f(i + 1, sm - arr[i]);

    return ret = (a + b)%mod;
}
int main()
{
    FIO;

    #ifdef IHAVETOPEE 
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    MEM(dp,-1);
    cin>>n;
    sum = n * (n + 1) / 2;
    if (sum % 2){
        printf("0\n");
        return 0;
    }
    for (int i = 0; i < n; i++)arr[i] = i + 1;
    cout<<f(0,sum/2)<<"\n"; 
    
    return 0;
}