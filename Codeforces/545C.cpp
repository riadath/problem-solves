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
int n,arr[100009],h[100009];
int dp[100009][5];
int f(int i,int j){
    //cout<<arr[i]<<sp<<j<<nl;
    if(i >= n)return 0;
    if(dp[i][j] != -1)return dp[i][j];
    int a = 0,b = 0,c = 0;
    if(j == 1 || j == 3){
        if(i < n-1)
        if(arr[i] + h[i] < arr[i+1]) a = 1+f(i+1,2);
        if(i == n-1) a = 1+f(i+1,2);

        if(i == 0)b = 1 + f(i+1,3);
        else
            if(arr[i-1] < arr[i]-h[i])b = 1+f(i+1,3);
        c = f(i+1,1);
    }
    if(j == 2){
        if(i < n-1)
        if(arr[i] + h[i] < arr[i+1])a = 1+f(i+1,2);
        if(i == n-1) a = 1+f(i+1,2);
        if(i == 0)b = 1+f(i+1,3);
        else if(arr[i-1]+h[i-1] < arr[i]-h[i])b = 1+f(i+1,3);
        c = f(i+1,1);
    }
    int mx = max(max(a,b),c);
    dp[i][j] = mx;
    return dp[i][j];
}

void solve()
{
    cin>>n;
    fl(i,0,n){
        cin>>arr[i];
        cin>>h[i];
    }
    MEM(dp,-1);
    int ans = f(0,1);
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

