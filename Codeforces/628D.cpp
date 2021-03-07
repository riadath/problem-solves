
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
#define MOD 1000000007
string a,b,str;
ll len,d,m, dp[2009][2][2009];
ll fnc(int pos ,int sfl, int rem)
{
    if(pos >= len){
        if(!rem){
            return 1;
        }
        return 0;
    }
    ll &ret = dp[pos][sfl][rem];
    if(ret != -1)return ret;
    int t = pos;
    ret = 0;
    int mx = 9,st;
    if(!sfl)mx = str[pos] - '0';
    if(pos == 0)st = 1;
    else st = 0;
    if(pos%2 == 1)
    {
        if(d <= mx)
            ret += fnc(pos+1,d < mx || sfl,(rem*10+d)%m)%MOD;
    }
    else
    {
        for(int l = st; l <= mx; l++)
        {
            if(l == d)continue;
            ret += fnc(pos+1,l < mx || sfl,(rem*10+l)%m)%MOD;
        }
    }
    return ret%MOD;
}
int sum(string t)
{
    str = t;
    MEM(dp,-1);
    len = str.size();
    //cout<<"Call for "<<str<<nl;
    return fnc(0,0,0);
}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    cin>>m>>d;
    cin>>a>>b;
    string save = a;
    string temp = a;
    if(a.size() == 1 && a[0] == '0'){}
    else{
        for(int i = temp.size()-1;i >= 0;i--){
            int t = temp[i] - '0';
            if(t != 0){
                temp[i] = (t-1) + '0';
                break;
            }
            else{
                temp[i] = '9';
            }
        }
    }
    int st = 0;
    a.clear();
    if(temp.size() == 1){
        a = temp;
    }
    else{
        while(temp[st] == '0')st++;
        for(int i = st;i < temp.size();i++){
            a += temp[i];
        }
    }
    ll sa = 0,sb = 0;
    if(a.size() < save.size())sa = 0;
    else sa = sum(a);
    sb = sum(b);
    //cout<<a<<nl;
    //cout<<sa<<sp<<sb<<nl;
    int ans = sb - sa;
    if(ans < 0)ans += MOD;
    cout<<ans<<nl;
    return 0;
}















