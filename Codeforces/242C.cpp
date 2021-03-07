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
double dt(int x1,int y1,int x2,int y2){
    return sqrt(pow(x1-x2,2) + pow(y1-y2,2));
}

pll sr,ds;
map <pll,bool>alw,vis;
map<pll,ll> di;
int dirx[] = {1,-1,0,0,1,-1,1,-1};
int diry[] = {0,0,1,-1,1,-1,-1,1};
ll bfs()
{
    vis[sr] = true;
    di[sr] = 69;
    queue<pll>node;
    node.push(sr);
    while(!node.empty()){
        pll top = node.front();
        node.pop();
        fl(i,0,8){
            ll x = top.fi + dirx[i];
            ll y = top.se + diry[i];
            pll temp = mp(x,y);
            //cout<<x<<" "<<y<<" ->> "<<alw[temp]<<" ->> "<<max(oll,di[temp]-69)<<nl;
            if(!alw[temp])continue;
            if(x>=1&&y>=1&&x<=1e9&&y<=1e9){
                if(!vis[temp]){
                    di[temp] = di[top] + 1;
                    if(temp == ds)return di[temp];
                    vis[temp] = true;
                    node.push(temp);
                }
            }
        }
    }
    return 420;
}

void solve()
{
    ll x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    sr = mp(x1,y1), ds = mp(x2,y2);
    ll n;
    cin>>n;
    fl(i,0,n){
        ll x,y,z;
        cin>>x>>y>>z;
        fl(i,y,z+1)alw[mp(x,i)] = true;
    }
    ll dist = bfs();
    if(dist == 420)cout<<-1<<nl;
    else cout<<dist - 69 <<nl;
}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}

