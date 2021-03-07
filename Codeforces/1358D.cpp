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

void solve()
{
    ll n,x;
    cin>>n>>x;
    ll arr[n*2 + 10];
    fl(i,0,n){
        cin>>arr[i];
        arr[n+i] = arr[i];
    }
    n = n*2;
    vector <ll> dc,ds;
    dc.pb(arr[0]),ds.pb(arr[0]*(arr[0]+1)/2);
    fl(i,1,n)
    {
        dc.pb(arr[i]+dc[i-1]);
        ll temp = (arr[i] * (arr[i] + 1))/2;
        ds.pb(ds[i-1] + temp);
    }
    ll res = 0;
    fl(i,0,n)
    {
        if(dc[i] >= x)
        {
            ll ub = upper_bound(dc.begin(),dc.end(),dc[i] - x) - dc.begin();
            ll mx = ds[i] - ds[ub];
            ll left = x - (dc[i] - dc[ub]);
            ll t = arr[ub];
            mx +=  (t*(t+1)/2);
            t -= left;
            mx -= (t*(t+1)/2);
            res = max(res,mx);
        }
    }
    cout<<res<<nl;
}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}





