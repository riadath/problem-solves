
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
char str[20];
int a,b,len;
int dp[9][2][50][50][2];
int fnc(int pos,int sfl,int evsum,int odsum,int ifzero)
{
    if(str[pos] == 0) return evsum - odsum == 1;
    int &ret = dp[pos][sfl][evsum][odsum][ifzero];
    if(ret != -1)return ret;
    ret = 0;
    int mx = 9;
    if(!sfl)mx = str[pos] - '0';

    for(int l = 0;l <= mx;l++){
       if(ifzero && l == 0){
            ret += fnc(pos+1,l<mx||sfl,evsum,odsum,0);
       }else{
            if((len-pos)%2)
                ret += fnc(pos+1,l<mx||sfl,evsum,odsum+l,1);
            else
                ret += fnc(pos+1,l<mx||sfl,evsum+l,odsum,1);
       }
    }
    return ret;
}

int sum(int n)
{
    if(n < 10)return 0;
    sprintf(str, "%d", n);
    MEM(dp,-1);
    len = strlen(str);
    return fnc(0,0,0,0,0);
}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        cin>>a>>b;
        int res = sum(b) - sum(a-1);
        cout<<res<<nl;
    }
    return 0;
}















