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
#define pi 3.141592653589793238
#define db double
#define fi first
#define se second
#define pi4 pair<pii,pii>
#define all(a) a.begin(),a.end()

bool comp(const pii &a,const pii &b)
{
    return a.second < b.second;
}
int a,b,k;
char str[20];
int dp[12][2][100][100];
int fnc(int i,bool sfl,int rem,int dsum)
{
    if(str[i] == 0){
        if(rem == 0 && dsum == 0)return 1;
        return 0;
    }
    int &opt = dp[i][sfl][rem][dsum];
    //cout<<opt<<nl;
    if(opt != -1)return opt;
    int mx = 9;
    if(!sfl)mx = str[i] - '0';
    opt = 0;
    for(int l = 0;l <= mx;l++){
        bool flag = l < mx || sfl;
        opt += fnc(i+1,flag,(rem*10+l)%k,(dsum + l)%k);
    }

    return opt;
}
int sum(int l){
    sprintf(str, "%d", l);
    MEM(dp,-1);
    return fnc(0,0,0,0);
}
int main()
{
    //FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    int kas = 1;
    while(T--){
       scanf("%d %d %d",&a,&b,&k);
       int ans = 0;
       if(k <= 90){
            ans = sum(b) - sum(a-1);
       }
       printf("Case %d: %d\n",kas++,ans);

    }
    return 0;
}















