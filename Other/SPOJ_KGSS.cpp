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
#define sp " ";
#define srt(x) sort(x.begin(), x.end())
#define srta(x,n) sort(x,x+n)
#define pi 3.141592653589793238
#define db double
#define fi first
#define se second

bool comp(const pii &a,const pii &b){
    return a.second < b.second;
}
double dt(double x1,double y1,double x2,double y2){
    return sqrt(pow(x1-x2,2) + pow(y1-y2,2));
}
ll n,sz,ns,arr[100001], mxa[10000];
void pre_process()
{
    sz = sqrt(n);
    if(ns%sz != 0)ns++;
    ll st = -1;
    fl(i,0,n){
        if(i%sz == 0)st++;
        mxa[st] = max(mxa[st],arr[i]);
    }
}

ll mn_value(ll l,ll r)
{
    ll l0 = l,mx1 = 0,mx2 = 0,pos,segment = -1;
    while(l < r && l%sz != 0){
        if(arr[l] > mx1){
            mx1 = arr[l];
            pos = l;
        }
        l++;
    }
    while(l+sz <= r){
        int seg = l/sz;
        if(mxa[seg] > mx1){
            mx1 = mxa[seg];
            segment = seg;
        }
        l += sz;
    }
    while(l <= r){
        if(arr[l] > mx1){
            segment = -1;
            pos = l;
            mx1 = arr[l];
        }
        l++;
    }
    if(segment != -1){
        pos = -1;
        int cn = 0;
        fl(i,segment*sz,(segment*sz)+sz){
            if(mx1 == arr[i]){
                cn++;
            }
            else mx2 = max(mx2,arr[i]);
        }
        if(cn >= 2)return 2*mx1;

    }
    l = l0;
    while(l < r && l%sz != 0){
        if(l == pos){
            l++;
            continue;
        }
        if(arr[l] > mx2){
            mx2 = arr[l];
        }
        l++;
    }
    while(l+sz <= r){
        int seg = l/sz;
        if(seg == segment){
            l += sz;
            continue;
        }
        if(mxa[seg] > mx2){
            mx2 = mxa[seg];
        }
        l += sz;
    }
    while(l <= r){
        if(l == pos){
            l++;
            continue;
        }
        if(arr[l] > mx2){
            mx2 = arr[l];
        }
        l++;
    }
    return (mx1+mx2);
}

void update(ll i,ll x)
{
    arr[i] = x;
    ll seg = i/sz;
    mxa[seg] = 0;
    fl(i,seg*sz,(seg*sz)+sz)
        mxa[seg] = max(arr[i],mxa[seg]);

}

void solve()
{
    ll q;
    cin>>n;
    fl(i,0,n)cin>>arr[i];
    pre_process();
    cin>>q;
    fl(i,0,q){
        char c;
        cin>>c;
        if(c == 'Q'){
            ll l,r;
            cin>>l>>r;
            ll ans = mn_value(l-1,r-1);
            cout<<ans<<nl;
        }
        if(c == 'U'){
            ll i,x;
            cin>>i>>x;
            update(i-1,x);
        }
    }
}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}

