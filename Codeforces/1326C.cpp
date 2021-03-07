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
#define MOD 998244353
void solve()
{
    ll n,k;
    cin>>n>>k;
    ll arr[n];
    ll sr[n];
    fl(i,0,n){
        cin>>arr[i];
        sr[i] = arr[i];
    }
    srta(sr,n);
    map<ll,bool>mxx;
    lf(i,n-1,(n-1)-(k-1)){
        mxx[sr[i]] = true;
    }
    vector <ll> mxp;
    fl(i,0,n){
        if(mxx[arr[i]])mxp.pb(i+1);
    }
    ll ans1 = (n*(n+1)/2) - ((n-k)*((n-k)+1)/2);
    ll ans2 = 1;
    fl(i,1,mxp.size()){
        ans2 *= (mxp[i] - mxp[i-1]);
        ans2 = ans2%MOD;
    }
    cout<<ans1<<sp<<ans2<<nl;
}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}

