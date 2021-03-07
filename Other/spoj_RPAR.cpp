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
#define seg_tree int mid=(st+en)/2,left = 2*nd,right = left+1
bool comp(const pii &a,const pii &b)
{
    return a.second < b.second;
}
double dt(int x1,int y1,int x2,int y2)
{
    return sqrt(pow(x1-x2,2) + pow(y1-y2,2));
}

#define MX 100109
#define MOD 10007
struct data
{
    bool flag;
    ll sum,a,b,c;
};
data tree[4*MX];
ll sum_sq(ll l,ll r)
{
    ll sum1 = 0,sum2 = 0;
    sum1 = (r*(r+1)*(2*r + 1)/6);
    if(l > 1)
    {
        l--;
        sum2 = (l*(l+1)*(2*l+1)/6);
    }
    return (sum1 - sum2);
}
ll sum_n(ll l,ll r)
{
    ll sum1 = 0,sum2 = 0;
    sum1 = (r*(r+1)/2);
    if(l > 1)
    {
        l--;
        sum2 = (l*(l+1)/2);
    }
    return (sum1 - sum2);
}

data make_data(int s,bool f)
{
    data ret;
    ret.sum = s;
    ret.flag = f;
    ret.a = 0;
    ret.b = 0;
    ret.c = 0;
    return ret;
}
data combine(data aa,data bb)
{
    data ret;
    ret.sum = (aa.sum + bb.sum)%MOD;
    ret.flag = 0;
    ret.a = 0,ret.b = 0,ret.c = 0;
    return ret;
}

void nd_update(int nd,int st,int en,ll aa,ll bb,ll cc)
{
    tree[nd].sum += (aa*sum_sq(st,en) + bb*sum_n(st,en)+cc*(en-st+1));
    tree[nd].a += aa;
    tree[nd].b += bb;
    tree[nd].c += cc;
    tree[nd].flag = true;
}
void lz_update(int nd,int st,int en)
{
    seg_tree;

    nd_update(left,st,mid,tree[nd].a,tree[nd].b,tree[nd].c);
    nd_update(right,mid+1,en,tree[nd].a,tree[nd].b,tree[nd].c);

    tree[nd].a = 0,tree[nd].b = 0,tree[nd].c = 0;
    tree[nd].flag = false;
}
void update(int nd,int st,int en,int i,int j,int p,int q,int r)
{
    if(st > j || en < i)return;
    if(st >= i && en <= j){
        nd_update(nd,st,en,p,q,r);
        return;
    }
    seg_tree;
    if(tree[nd].flag)lz_update(nd,st,en);

    update(left,st,mid,i,j,p,q,r);
    update(right,mid+1,en,i,j,p,q,r);

    tree[nd] = combine(tree[left],tree[right]);
}

data query(int nd,int st,int en,int i,int j)
{
    if(st > j || en < i)return make_data(0,0);
    if(st >= i && en <= j)
    {
        return tree[nd];
    }
    seg_tree;

    if(tree[nd].flag)lz_update(nd,st,en);

    data a = query(left,st,mid,i,j);
    data b = query(right,mid+1,en,i,j);

    return combine(a,b);
}

void solve()
{
    int n,q;
    cin>>n>>q;

    while(q--)
    {
        int cmd;
        cin>>cmd;
        if(cmd == 0)
        {
            int p,q,r;
            int i,j;
            cin>>i>>j;
            cin>>p>>q>>r;
            update(1,0,n-1,i,j,p,q,r);
        }
        else{
            int i,j;
            cin>>i>>j;
            data ans = query(1,0,n-1,i,j);
            cout<<ans.sum%MOD<<nl;
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


