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

ll coin[201];
ll dp[201][201][201];
ll N,Q,D,M;

ll f(int i,int j,int cost)
{
    if(j >= M){
        if(cost == 0)return 1;
        else return 0;
    }
    if(i >= N)return 0;
    if(dp[i][j][cost] != -1)return dp[i][j][cost];
    int a = f(i+1,j+1,(cost+coin[i])%D);
    int b = f(i+1,j,cost%D);
    dp[i][j][cost] = a + b;
    return dp[i][j][cost];
}

void solve()
{
    int s = 1;
    while(cin>>N>>Q && (N||Q))
    {
        cout<<"SET "<<s++<<":\n";
        int qu = 1;
        fl(i,0,N)cin>>coin[i];
        while(Q--){
            cin>>D>>M;
            MEM(dp,-1);
            ll ans = f(0,0,0);
            cout<<"QUERY "<<qu++<<": "<<ans<<nl;
        }
    }
}

int main()
{
     FIO;
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}

