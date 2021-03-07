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

void solve()
{
    int n;
    cin>>n;
    ll arr[n];
    ll ans[n];
    ll t_arr[n];
    ll cur_mx = 0;
    fl(i,0,n)cin>>t_arr[i];
    fl(id,0,n){
        fl(i,0,n){
            arr[i] = t_arr[i];
        }
        ll cur = arr[id];
        ll total = 0;
        fl(i,id,n){
            if(arr[i] > cur)arr[i] = cur;
            cur = arr[i];
            total += arr[i];
        }
        cur = arr[id];
        lf(i,id-1,0){
            if(arr[i] > cur)arr[i] = cur;
            cur = arr[i];
            total += arr[i];
        }
        if(total > cur_mx){
            cur_mx = total;
            fl(i,0,n)ans[i] = arr[i];
        }
    }
    fl(i,0,n)cout<<ans[i]<<sp;
}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    //cin>>T;
    //while(T--)
        solve();
    return 0;
}

