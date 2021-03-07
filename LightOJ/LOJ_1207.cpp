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
#define MX 400000
int tree[4*MX];
bool post[4*MX];
int n;

void update(int nd,int st,int en,int i,int j,int id)
{
    if(i > en || j < st)return;
    if(st >= i && en <= j){
        tree[nd] = id;
        return;
    }
    int mid = (st+en)/2;
    int left = 2*nd,right = left+1;
    update(left,st,mid,i,j,id);
    update(right,mid+1,en,i,j,id);
}

void query(int nd,int st,int en,int prop)
{
    if(st == en){
        int id = max(prop,tree[nd]);
        post[id] = true;
        return;
    }
    int mid = (st+en)/2;
    int left = 2*nd,right = left+1;
    query(left,st,mid,max(prop,tree[nd]));
    query(right,mid+1,en,max(prop,tree[nd]));
}

void solve()
{
    int T;
    int kas = 1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        map<int,bool>exist;
        map<int,int> mapping;
        vector <int> point;
        vector<pii> range;
        fl(i,0,n){
            int x,y;
            scanf("%d %d",&x,&y);
            range.pb(mp(x,y));
            if(!exist[x]){
                exist[x] = true;
                point.pb(x);
            }
            if(!exist[y]){
                exist[y] = true;
                point.pb(y);
            }
        }
        srt(point);
        int mx = point.size();
        fl(i,0,mx){
            mapping[point[i]] = i+1;
        }
        //cout<<1<<"---"<<mx<<nl;
        fl(i,0,n){
            int x = range[i].fi;
            int y = range[i].se;
            x = mapping[x];
            y = mapping[y];
            int id = i+1;
            //cout<<x<<sp<<y<<nl;
            update(1,1,mx,x,y,id);
        }
        query(1,1,mx,0);

       /*
        fl(i,1,2*mx+2){
            cout<<i<<" ==>"<<tree[i].fi<<sp<<tree[i].se<<nl;
        }
        */
        int cn = 0;
        fl(i,1,n+1)
            if(post[i]){
                cn++;
            }

        printf("Case %d: %d\n",kas++,cn);
        MEM(tree,0),MEM(post,false);
    }
}

int main()
{
    //FIO;
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}


