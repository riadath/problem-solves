#include <bits/stdc++.h>
using namespace std;
long long oll = 0;
#define ll long long
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define pii pair<int,int>
#define lcm(a,b) a*b/__gcd(a,b)
#define fl(i,a,b) for(int i = a;i < b;i++)
#define lf(i,a,b) for(int i = b;i >= a;i--)
#define MEM(x,y) memset(x,y,sizeof(x))
#define mp make_pair
#define bs(x,y) binary_search(x.begin(),x.end(),y)
#define nl "\n"
#define sp " "
#define srt(x) sort(x.begin(),x.end())
ll primes[500];
bool sps[1122];
ll make,k,n,dp[300][15][1122];
ll num_primes = 187;
void sieve()
{
    sps[0] = false,sps[1] = false;
    for(ll i = 4;i <= 1122;i += 2)sps[i] = false;
    for(ll i = 3;i*i <= 1122;i += 2){
        for(ll j = 3;i*j <= 1122;j++)sps[i*j] = false;
    }
    ll j = 0;
    fl(i,0,1122)
        if(sps[i]){
        primes[j] = i;
        j++;
    }
}

ll f(ll i,ll t,ll cost)
{
    if(t == k){
        if(cost == make)return 1;
        else return 0;
    }
    if(dp[i][t][cost] != -1)return dp[i][t][cost];
    ll a = 0,b = 0;
    if(cost+primes[i]<=make && i+1 <= n)
        a = f(i+1,t+1,cost+primes[i]);
    if(i+1 <= n)b = f(i+1,t,cost);
    return dp[i][t][cost] = a + b;

}

void solve()
{
    MEM(sps,true);
    MEM(primes,0);
    sieve();
    while(cin>>make>>k && (make||k)){
        MEM(dp,-1);
        n = 0;
        fl(i,0,num_primes){
            if(primes[i] > make)break;
            else n++;
        }
        if(n == 0)cout<<0<<nl;
        else{
            ll ans = f(0,0,0);
            cout<<ans<<nl;
        }
    }
}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}

