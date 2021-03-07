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

bool comp(const pii &a,const pii &b)
{
    return a.second < b.second;
}
double dt(int x1,int y1,int x2,int y2)
{
    return sqrt(pow(x1-x2,2) + pow(y1-y2,2));
}
int n;
int arr[200];
int dp[200][10];

int f(int i,int j)
{
    //cout<<i<<sp<<j<<sp<<arr[i]<<nl;
    if(i >= n){
       return 0;
    }
    if(dp[i][j] != -1)return dp[i][j];
    int a = 1e7 ,b = 1e7,c = 1e7;
    a = 1 + f(i+1,0);
    if(arr[i] == 1){
        if(j != 2){
            b = f(i+1,2);
        }
    }
    else if(arr[i] == 2){
        if(j != 1){
            b = f(i+1,1);
        }
    }
    else if(arr[i] == 3){
        if(j == 0){
            b = f(i+1,1);
            c = f(i+1,2);
        }
        if(j == 1){
            b = f(i+1,2);
        }
        if(j == 2){
            b = f(i+1,1);
        }
    }
    int mn = min(min(a,b),c);
    dp[i][j] = mn;
    return dp[i][j];
}

void solve()
{
    cin>>n;
    fl(i,0,n)cin>>arr[i];
    MEM(dp,-1);
    int ans = f(0,0);
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

