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
#define MOD 1000000007
#define MX 300009
int n,m;
ll lc[MX];
ll ppc[MX];
ll arr[MX];
vector <ll> prime;
bool flag[MX];

ll bigmod(ll a,ll b,ll M)
{
    if(b == 0)return 1;
    if(b%2 == 1)return ((a%M) * bigmod(a,b-1,M)%M)%M;
    else {
        ll x = bigmod(a,b/2,M)%M;
        return (x*x)%M;
    }
}

void sieve()
{
    flag[0] = 1;
    flag[1] = 1;
    prime.pb(2);
    for(int i = 3;i*i <= MX;i += 2){
        if(flag[i] == 0){
            for(int j = i*i;j <= MX;j += 2*i){
                flag[j] = 1;
            }
        }
    }
    for(int i = 3;i < MX;i += 2){
        if(!flag[i]){
            //cout<<i<<nl;
            prime.pb(i);
        }
    }
}

void pre_pro(){
    ll bb = 1;
    lc[1] = 1;
    fl(i,2,MX){
        ll nn = i;
        ll szz = sqrt(nn);
        for(int j = 0;j < prime.size() && prime[j] <= szz;j++){
            if(nn%prime[j] == 0){
                ll cc = 0;
                while(nn%prime[j] == 0){
                    cc++;
                    nn /= prime[j];
                }
                szz = sqrt(nn);
                ll pp = max(oll,cc - ppc[prime[j]]);
                ll tt = bigmod(prime[j],pp,MOD);
                ppc[prime[j]] = max(cc,ppc[prime[j]]);
                bb = (bb*tt)%MOD;
            }
        }
        if(nn > 1){
            if(!ppc[nn]){
                bb = (bb*nn)%MOD;
                ppc[nn] = 1;
            }
        }
        lc[i] = bb;
    }
}

struct data
{
    ll fir,sec,prop;
};
data tree[4*MX];

void build(int nd,int st,int en)
{
    if(st == en)
    {
        tree[nd].fir = arr[st];
        tree[nd].sec = arr[st];
        tree[nd].prop = 0;
        return;
    }
    int mid = (st+en)/2;
    int left = 2*nd,right = left + 1;
    build(left,st,mid);
    build(right,mid+1,en);
    tree[nd].fir = max(tree[left].fir,tree[right].fir);
    tree[nd].sec = min(tree[left].sec,tree[right].sec);
}

void update(int nd,int st,int en,int i,int j,int v)
{
    if(i > en || j < st)return;
    if(st >= i && en <= j)
    {
        tree[nd].fir += v;
        tree[nd].sec += v;
        tree[nd].prop += v;
        return;
    }
    int mid = (st+en)/2;
    int left = 2*nd,right = left + 1;
    update(left,st,mid,i,j,v);
    update(right,mid+1,en,i,j,v);
    tree[nd].fir = max(tree[left].fir,tree[right].fir) + tree[nd].prop;
    tree[nd].sec = min(tree[left].sec,tree[right].sec) + tree[nd].prop;
}

ll query(int nd,int st,int en,int i,int j,ll lazy,int what)
{
    if(i > en || j < st){
        if(what == 1){
            return (ll)0;
        }
        else {
            return (ll)1e15;
        }
    }
    if(st >= i && en <= j){
        if(what == 1){
            return tree[nd].fir + lazy;
        }
        else{
            return tree[nd].sec + lazy;
        }
    }
    int mid = (st+en)/2;
    int left = 2*nd,right = left + 1;
    ll pp = query(left,st,mid,i,j,lazy + tree[nd].prop,what);
    ll qq = query(right,mid+1,en,i,j,lazy + tree[nd].prop,what);
    if(what == 1){
        return max(pp,qq);
    }
    else if(what == 2){
        return min(pp,qq);
    }
}

void solve()
{
    sieve();
    pre_pro();
    //fl(i,1,MX)cout<<"LCM "<<i<<": "<<lc[i]<<"\n";
    cin>>n>>m;
    fl(i,1,n+1)cin>>arr[i];
    build(1,1,n);
    fl(i,0,m)
    {
        int com,p,q;
        cin>>com>>p>>q;
        p++,q++;
        if(com == 0){
            int v;
            cin>>v;
            update(1,1,n,p,q,v);
        }
        else{
            ll ans;
            if(com == 1)
                ans = query(1,1,n,p,q,0,1);
            else if(com == 2)
                ans = query(1,1,n,p,q,0,2);
            //cout<<"---> "<<ans<<nl;
            cout<<lc[ans]<<nl;
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



