///LOJ 1164 "horrible queries"
///range sum, and range update

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

#define MX 500100
pll tree[3*MX];

void update(ll nd,ll st,ll en,ll i,ll j,ll v)
{
    if(st > j || en < i)return;
    if(st >= i && en <= j)
    {
        tree[nd].fi += (en-st+1)*v;
        tree[nd].se += v;
        return;
    }
    ll left = 2*nd,right = left+1;
    ll mid = (st+en)/2;
    update(left,st,mid,i,j,v);
    update(right,mid+1,en,i,j,v);
    tree[nd].fi = tree[left].fi + tree[right].fi + (en-st+1)*tree[nd].se;
}

ll query(ll nd,ll st,ll en,ll i,ll j,ll prop)
{
    if(st > j || en < i)return 0;
    if(st >= i && en <= j)
    {
        return tree[nd].fi + prop*(en-st+1);
    }
    ll left = 2*nd,right = left+1;
    ll mid = (st+en)/2;
    ll a = query(left,st,mid,i,j,prop + tree[nd].se);
    ll b = query(right,mid+1,en,i,j,prop + tree[nd].se);
    return a+b;
}

void solve()
{
    ll T;
    scanf("%lld",&T);
    fl(kas,1,T+1)
    {
        ll n,q;
        scanf("%lld %lld",&n,&q);
        printf("Case %lld:\n",kas);
        fl(i,0,q)
        {
            ll a,x,y,v;
            scanf("%lld",&a);
            if(a == 0){
                scanf("%lld %lld %lld",&x,&y,&v);
                update(1,1,n,x+1,y+1,v);
            }
            else if(a == 1){
                scanf("%lld %lld",&x,&y);
                ll ans = query(1,1,n,x+1,y+1,0);
                printf("%lld\n",ans);
            }
        }
        fl(i,0,3*n+1)tree[i].fi = 0,tree[i].se = 0;
    }
}

int main()
{
    //FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}


