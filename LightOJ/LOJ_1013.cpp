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
string a,b;
ll dp1[50][50];
ll dp2[50][50];
ll f1(int i,int j){

    ll &ret = dp1[i][j];
    if(i >= a.size() || j >= b.size()){
        ret = 0;
        return ret;
    }
    if(ret != -1)return ret;
    ret = 0;
    if(a[i] == b[j]){
        ret = 1 + f1(i+1,j+1);
    }
    else{
        ret = max(f1(i+1,j),f1(i,j+1));
    }
    return ret;
}

ll f2(int i,int j){
    if(i >= a.size() || j >= b.size())return 1;

    ll &ret = dp2[i][j];
    if(ret != -1)return ret;
    ret = 0;

    if(a[i] == b[j]){
        ret = f2(i+1,j+1);
    }
    else{
        if(dp1[i+1][j] > dp1[i][j+1])ret = f2(i+1,j);
        else if(dp1[i][j+1] > dp1[i+1][j])ret = f2(i,j+1);
        else ret = f2(i+1,j) + f2(i,j+1);
    }
    return ret;
}

int main()
{
    //FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    cin>>T;
    int kas = 1;
    while(T--)
    {
        cin>>a>>b;
        MEM(dp1,-1);
        MEM(dp2,-1);
        ll ans1 = a.size() + b.size() - f1(0,0);
        ll ans2 = f2(0,0);
        cout<<"Case "<<kas++<<": "<<ans1<<sp<<ans2<<nl;
    }
    return 0;
}















