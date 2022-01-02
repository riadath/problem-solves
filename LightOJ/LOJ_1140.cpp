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
#define PI 3.141592653589793238
#define fi first
#define se second
#define all(a) a.begin(), a.end()

bool comp(const pii &a, const pii &b)
{
    return a.fi < b.fi;
}

string str;
ll dp[12][2][12][2];

ll f(int pos,bool flag,int cnt,bool bFlag){
    if(str[pos] == 0)return cnt * bFlag;
    
    ll &ret = dp[pos][flag][cnt][bFlag];
    if(ret != -1)return ret;
    ret = 0;

    int lt = 9;
    if(!flag)lt = str[pos] - '0';

    for(int i = 0;i <= lt;i++){
        ret +=  f(pos + 1,i < lt || flag,cnt + (i == 0)*bFlag,i > 0 || bFlag);
    }
    
    return ret;
}

ll count(ll n){
    MEM(dp,-1);
    str = to_string(n);
    ll rt = f(0,0,0,0);
    debug(str);debug(rt);
    return rt;
}

int main()
{
    FIO;
    #ifdef IHAVETOPEE 
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    int T;cin>>T;
    fl(kas,1,T+1){

        ll mm,nn;
        cin>>mm>>nn;
        cout<<"Case "<<kas<<": ";
        ll c1,c2;
        if(mm == 0)c1 = 0;
        else c1 = count(mm-1);
        if(nn == 0)c2 = 1;
        else c2 = count(nn);
        ll ans = c2 - c1;
        if(mm == 0)ans += 1;
        if(nn == 0)ans -= 1;
        cout<<ans<<"\n";

    }

    
    return 0;
}
