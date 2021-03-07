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
#define bs(x,y) binary_search(x.begin(),x.end(),y)
#define nl "\n"
#define sp " ";
#define mp make_pair

int coin[101],favor[101];
int dp[101][10001];
int mx_cost;
int n;

int f(int i,int cost)
{
    if(i >= n){
        if(cost<=mx_cost)return 0;
        else if(cost > 2000 && cost <= mx_cost+200)return 0;
        else return -1*INT_MAX;
    }
    if(dp[i][cost] != -1)return dp[i][cost];
    int a = -1e9,b = -1e9;
    if(cost+coin[i]<=mx_cost+200)a = favor[i] + f(i+1,cost+coin[i]);
    b = f(i+1,cost);
    dp[i][cost] = max(a,b);
    return dp[i][cost];
}

void solve()
{
    int dk = 1;
    while(scanf("%d %d",&mx_cost,&n) != EOF)
    {
        fl(i,0,n){
            cin>>coin[i]>>favor[i];
        }
        MEM(dp,-1);
        //cout<<"Case #"<<dk++<<":";
        int ans = f(0,0);
        cout<< ans << nl;
    }
}

int main()
{
    //FIO;

    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}
