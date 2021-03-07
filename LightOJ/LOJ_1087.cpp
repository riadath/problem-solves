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
pii tree[1000000];
void update(ll nd,ll st,ll en,ll i,ll x)
{
    if(st == en){
        tree[nd].fi = 1;
        tree[nd].se = x;
        return;
    }
    int left = 2*nd,right = left+1;
    int mid = (st+en)/2;
    if(i <= mid)update(left,st,mid,i,x);
    else update(right,mid+1,en,i,x);
    tree[nd].fi = tree[left].fi + tree[right].fi;
}

ll query(ll nd,ll st,ll en,ll i)
{
    tree[nd].fi--;
    if(st == en)return tree[nd].se;
    int mid = (st+en)/2;
    int left = 2*nd,right = left+1;
    ll a = 0,b = 0;
    if(i<=tree[left].fi)return query(left,st,mid,i);
    else return query(right,mid+1,en,i - tree[left].fi);
}

void solve()
{
    ll T;
    scanf("%lld",&T);
    fl(kas,1,T+1)
    {
        ll n,q;
        scanf("%lld %lld",&n,&q);
        ll mx = n+q+500;
        fl(i,1,n+1)
        {
            ll x;
            scanf("%lld",&x);
            update(1,1,mx,i,x);
        }
        printf("Case %lld:\n",kas);
        fl(i,0,q)
        {
            char a;
            ll b;
            scanf(" %c",&a);
            if(a == 'a')
            {
                scanf("%lld",&b);
                n++;
                update(1,1,mx,n,b);
            }
            else
            {
                //cout<<"--->"<<tree[1].sum<<nl;
                scanf("%lld",&b);
                if(tree[1].fi < b)printf("none\n");
                else{
                    ll ans = query(1,1,mx,b);
                    printf("%lld\n",ans);
                }
            }
        }
        MEM(tree,0);
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

