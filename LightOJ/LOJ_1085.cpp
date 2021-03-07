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
#define MOD 1000000007
#define MX 100009
ll tree[4*MX];
ll n;

void update(int nd,int st,int en,int i,ll v)
{
    if(i < st || i > en)return ;
    if(st == en){
        tree[nd] = (tree[nd] + v)%MOD;
        return;
    }
    seg_tree;
    update(left,st,mid,i,v);
    update(right,mid+1,en,i,v);
    tree[nd] = (tree[left] + tree[right])%MOD;
}
ll query(int nd,int st,int en,int i,int j)
{
    if(i > en || j < st)return 0;
    if(st >= i && en <= j)return tree[nd];
    seg_tree;
    ll a = query(left,st,mid,i,j);
    ll b = query(right,mid+1,en,i,j);
    return (a + b)%MOD;
}
void solve()
{
    int T;
    scanf("%d",&T);
    int kas = 1;
    while(T--)
    {
        scanf("%lld",&n);
        ll arr[n+1000];
        map <ll,bool> point;
        vector <ll> range;
        map<ll,ll> mp;
        ll cn = 0;
        fl(i,0,n){
            scanf("%lld",&arr[i]);
            if(point[arr[i]] == 0){
                point[arr[i]] = 1;
                range.pb(arr[i]);
                cn++;
            }
        }
        srt(range);
        fl(i,0,cn){
            mp[range[i]] = i+1;
        }
        cn += 100000;
        ll val = mp[arr[0]];
        update(1,1,cn,val,1);
        fl(i,1,n){
            val = mp[arr[i]];
            ll sum = query(1,1,cn,1,val-1);
            update(1,1,cn,val,sum+1);
        }
        printf("Case %d: %lld\n",kas++,tree[1]%MOD);
        fl(i,0,4*MX)tree[i] = 0;
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


