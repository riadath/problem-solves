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
#define pii pair<ll, ll>
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
double dt(ll x1,ll y1,ll x2,ll y2)
{
    return sqrt(pow(x1-x2,2) + pow(y1-y2,2));
}
int tree[4*500000];
void update(int nd,int st,int en,int i,int j)
{
    if(st > j || en < i)return;
    if(st >= i && en <= j){
        tree[nd] += 1;
        return;
    }
    int left = 2*nd,right = left+1;
    int mid = (st+en)/2;
    update(left,st,mid,i,j);
    update(right,mid+1,en,i,j);
}

int query(int nd,int st,int en,int i,int carry)
{
    if(i < st || i > en)return 0;
    if(st == en){
        return tree[nd] + carry;
    }
    int left = 2*nd,right = left+1;
    int mid = (st+en)/2;
    int a = query(left,st,mid,i,carry + tree[nd]);
    int b = query(right,mid+1,en,i,carry + tree[nd]);
    return a+b;
}
void solve()
{
    int T;
    scanf("%d",&T);
    fl(kas,1,T+1)
    {
        int n,q,cunt = 0;
        scanf("%d %d",&n,&q);
        vector <pii> test;
        vector <ll> ranges,points;
        map <ll,ll> used;
        map <ll,ll> mapping;
        ll x,y;
        fl(i,0,n){
            scanf("%lld %lld",&x,&y);
            test.pb(mp(x,y));
            if(used[x] == 0){
                used[x] = 1;
                ranges.pb(x);
                cunt++;
            }
            if(used[y] == 0){
                used[y] = 1;
                ranges.pb(y);
                cunt++;
            }
        }
        fl(i,0,q){
            scanf("%lld",&x);
            points.pb(x);
            if(used[x] == 0){
                used[x] = 1;
                ranges.pb(x);
                cunt++;
            }
        }
        srt(ranges);
        fl(i,0,cunt){
            mapping[ranges[i]] = i+1;
        }
        fl(i,0,n){
            x = test[i].fi,y = test[i].se;
            x = mapping[x],y = mapping[y];
            update(1,1,cunt,x,y);
        }
        printf("Case %d:\n",kas);
        fl(i,0,q){
            x = points[i];
            x = mapping[x];
            ll ans = query(1,1,cunt,x,0);
            printf("%lld\n",ans);
        }
        fl(i,0,4*cunt+1)tree[i] = 0;
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

