#include <bits/stdc++.h>
using namespace std;
long long oll = 0;
#define ll long long
#define ull unsigned long long
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define pb push_back
#define pii pair<int, int>
#define pdd pair<double,double>
#define pll pair<long, long>
#define lcm(a, b) a *b / __gcd(a, b)
#define fl(i, a, b) for (ll i = a; i < b; i++)
#define lf(i, b, a) for (ll i = b; i >= a; i--)
#define MEM(x, y) memset(x, y, sizeof(x))
#define mp make_pair
#define bs(x, y) binary_search(x.begin(), x.end(), y)
#define nl "\n"
#define sp " "
#define srt(x) sort(x.begin(), x.end())
#define srta(x,n) sort(x,x+n)
#define pi 3.141592653589793238
#define db double
#define fi first
#define se second
#define pi4 pair<pii,pii>

bool comp(const pii &a,const pii &b)
{
    return a.second < b.second;
}
double dt(int x1,int y1,int x2,int y2)
{
    return sqrt(pow(x1-x2,2) + pow(y1-y2,2));
}
int black[1008],white[1008];
int n,m,x,y;
int dp[1008][1008][5];
int f(int i,int j,int k){
    //cout<<i<<sp<<j<<sp<<k<<nl;
    //cout<<"------------------"<<nl;
    if(i >= m){
        if(j < x)return 1e7;
        else return 0;
    }
    if(dp[i][j][k] != -1)return dp[i][j][k];
    int a = 1e7,b = 1e7;
    if(k == 3){
        a = black[i] + f(i+1,1,1);
        b = white[i] + f(i+1,1,2);
    }
    if(k == 1){
        if(j < x)a = black[i] + f(i+1,j+1,1);
        else if(j >= y)a = white[i] + f(i+1,1,2);
        else{
            a = black[i] + f(i+1,j+1,1);
            b = white[i] + f(i+1,1,2);
        }
    }
    if(k == 2){
        if(j < x)a = white[i] + f(i+1,j+1,2);
        else if(j >= y)a = black[i] + f(i+1,1,1);
        else{
            a = white[i] + f(i+1,j+1,2);
            b = black[i] + f(i+1,1,1);
        }
    }
    //cout<<a<<sp<<b<<nl;
    dp[i][j][k] = min(a,b);
    return dp[i][j][k];
}

void solve()
{
    cin>>n>>m>>x>>y;
    string temp;
    fl(i,0,n){
        cin>>temp;
        fl(j,0,m){
            if(temp[j] == '.')white[j]++;
            else black[j]++;
        }
    }
    MEM(dp,-1);
    //fl(i,0,m)cout<<black[i]<<sp<<white[i]<<nl;
    int ans = f(0,0,3);
    cout<<ans<<nl;
}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}

