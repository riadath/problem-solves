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
int n;
vector <pii> graph[30009];
int dxx[30009];
int dmx1[30009];
int dmx2[30009];
int mxx = 0;
int dijakstra(int src,int distance[])
{
    int ret = -1;
    MEM(distance,0);
    bool visited[n];
    MEM(visited,false);
    visited[src] = true;
    priority_queue<pii>node;
    node.push(mp(distance[src],src));
    while(!node.empty()){
        int a = node.top().se;
        node.pop();
        visited[a] = true;
        fl(i,0,graph[a].size()){
            int b = graph[a][i].fi;
            int w = graph[a][i].se;
            if(!visited[b]){
                visited[b] = true;
                if(distance[a] + w > distance[b]){
                    distance[b] = distance[a] + w;
                    mxx = max(mxx,distance[b]);
                    if(mxx == distance[b])ret = b;
                    node.push(mp(distance[b],b));
                }
            }
        }
    }
    return ret;
}
void solve()
{
    int T;
    scanf("%d",&T);
    int kas = 1;
    while(T--){
        scanf("%d",&n);
        fl(i,0,n-1){
            int x,y,w;
            scanf("%d %d %d",&x,&y,&w);
            graph[x].pb(mp(y,w));
            graph[y].pb(mp(x,w));
        }
        mxx = 0;
        int mx1 = dijakstra(0,dxx);
        mxx = 0;
        int mx2 = dijakstra(mx1,dmx1);
        mxx = 0;
        int noonecares = dijakstra(mx2,dmx2);
        //cout<<"--->"<<mx1<<sp<<mx2<<nl;
        printf("Case %d:\n",kas++);
        fl(i,0,n){
           // cout<<dmx1[i]<<sp<<dmx2[i]<<nl;
            printf("%d\n",max(dmx1[i],dmx2[i]));
        }
        fl(i,0,n+1)graph[i].clear();
        MEM(dmx1,0),MEM(dmx2,0),MEM(dxx,0);
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

