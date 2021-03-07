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
#define MX 1000009
pii tree[4*MX];
void update(int nd,int st,int en,int i,int j,int prop)
{
    if(st > j || en < i)return;
    if(st >= i && en <= j)
    {
        tree[nd].fi = (en-st+1) - tree[nd].fi;
        tree[nd].se += 1;
        return;
    }
    int left = 2*nd,right = left + 1;
    int mid = (st+en)/2;
    update(left,st,mid,i,j,prop + tree[nd].se);
    update(right,mid+1,en,i,j,prop + tree[nd].se);

    tree[nd].fi = tree[left].fi + tree[right].fi;

    if((tree[nd].se)%2)tree[nd].fi = (en-st+1) - tree[nd].fi;
}

int query(int nd,int st,int en,int i,int j,int prop)
{
    if(st > j || en < i)return 0;
    if(st >= i && en <= j)
    {
        //cout<<"PROP: "<<prop<<nl;
        //prop += tree[nd].se;
        if(prop%2 == 1)return (en-st+1) - tree[nd].fi;
        return tree[nd].fi;
    }
    int left = 2*nd,right = left+1;
    int mid = (st + en)/2;
    int a = query(left,st,mid,i,j,prop+tree[nd].se);
    int b = query(right,mid+1,en,i,j,prop+tree[nd].se);
    return a+b;
}

void solve()
{
    int n,m;
    cin>>n>>m;
    fl(i,0,m)
    {
        int o,a,b;
        cin>>o>>a>>b;
        if(o == 1)
        {
            ll ans = query(1,1,n,a,b,0);
            //cout<<"-->";
            cout<<ans<<nl;
        }
        else
        {
            update(1,1,n,a,b,0);
        }
    }
    //fl(i,1,2*n+1)cout<<i<<sp<<tree[i].fi<<sp<<tree[i].se<<nl;
}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}
