#include <bits/stdc++.h>
using namespace std;
long long oll = 0;
#define ll long long
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define pii pair<int,int>
#define lcm(a,b) a*b/__gcd(a,b)
#define fl(i,a,b) for(ll i = a;i < b;i++)
#define lf(i,a,b) for(ll i = b;i >= a;i--)
#define MEM(x,y) memset(x,y,sizeof(x))
#define mp make_pair
#define bs(x,y) binary_search(x.begin(),x.end(),y)
#define nl "\n"
#define sp " ";
#define srt(x) sort(x.begin(),x.end())
ll n,arr[100010];
ll dp[100010];

void solve()
{
    ll T;
    cin>>T;
    while(T--){
        cin>>n;
        fl(i,1,n+1)cin>>arr[i];
        fl(i,0,n+1)dp[i] = 1;
        fl(i,1,n+1){
            for(int j = 2*i;j <= n;j += i){
                if(arr[i] < arr[j])
                dp[j] = max(dp[j],dp[i] + 1);
            }
        }
        ll ans = 0;
        fl(i,1,n+1)ans = max(ans,dp[i]);
        cout<<ans<<nl;
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

