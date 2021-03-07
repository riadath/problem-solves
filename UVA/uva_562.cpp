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
#define sp " ";
int n;
int total;
int coin[101];
int dp[101][50001];
int diff = INT_MAX;
int f(int i,int cost)
{
    if(i >= n){
        return abs(total-2*cost);
    }
    if(dp[i][cost] != -1){
        return dp[i][cost];
    }

    int a = f(i+1,cost+coin[i]);
    int b = f(i+1,cost);
    int mn = INT_MAX;
    mn = min(a,b);
    dp[i][cost] = mn;
    return dp[i][cost];
}

void solve()
{
   int T;
   cin>>T;
   while(T--){
    MEM(dp,-1);
    cin>>n;
    total = 0;
    fl(i,0,n){
        cin>>coin[i];
        total += coin[i];
    }
    diff = INT_MAX;
    int ans = f(0,0);
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

