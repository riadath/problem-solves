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
#define srt(x) sort(x.begin(),x.end())
int coin[100],cost[100],dept[100],dp[100][10001],path[100][10001];
int mx_cost,w,n,t;
vector<int>in;
int f(int i,int wei)
{
    if(i >= n){
        return 0;
    }
    if(dp[i][wei] != -1)return dp[i][wei];
    int a = 0,b = 0;
    if(wei+cost[i]<=mx_cost)a = coin[i]+f(i+1,wei+cost[i]);
    b = f(i+1,wei);
    if(a > b)path[i][wei] = 1;
    else path[i][wei] = 2;
    return dp[i][wei] = max(a,b);
}

void print(int i,int wei)
{
    if(path[i][wei]==-1)return;
    else if(path[i][wei]==1){
        in.pb(i);
        print(i+1,wei+cost[i]);
    }
    else if(path[i][wei]==2)print(i+1,wei);

}

void solve()
{
    while(scanf("%d %d",&mx_cost,&w)==2)
    {
        if(t)cout<<nl;
        t = 1;
        cin>>n;
        fl(i,0,n)
        {
            cin>>dept[i]>>coin[i];
            cost[i] = dept[i]*w*3;
        }

        MEM(dp,-1);
        MEM(path,-1);
        int mx = f(0,0);
        cout<<mx<<nl;
        print(0,0);
        cout<<in.size()<<nl;
        fl(i,0,in.size())cout<<dept[in[i]]<<" "<<coin[in[i]]<<nl;
        in.clear();
    }
}

int main()
{
    //FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}

