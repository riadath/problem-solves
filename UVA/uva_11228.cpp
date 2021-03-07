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
#define pll pair<ll,ll>
#define lcm(a, b) a *b / __gcd(a, b)
#define fl(i, a, b) for (ll i = a; i < b; i++)
#define lf(i, b, a) for (ll i = b; i >= a; i--)
#define MEM(x, y) memset(x, y, sizeof(x))
#define mp make_pair
#define bs(x, y) binary_search(x.begin(), x.end(), y)
#define nl "\n"
#define sp " "
#define srt(x) sort(x.begin(), x.end())
#define pi 3.141592653589793238
#define db double
#define fi first
#define se second
#define pi4 pair<pii,pii>
#define all(a) a.begin(),a.end()

bool comp(const pii &a,const pii &b){
    return a.second < b.second;
}

vector <int> graph[1009];
map <pii,db> cost;
vector <db> roads,rails;
int n;
double r;
void prims()
{
    int vis_cnt = 1;
    bool visited[n+1];

    MEM(visited,false);
    visited[1] = true;

    priority_queue <pair<db,int>> node;

    for(int i = 0;i < graph[1].size();i++){
        int v = graph[1][i];
        db x = cost[mp(1,v)];
        node.push(mp(-1 * x,v));
    }
    while(vis_cnt < n){
        pair<db,int> u = node.top();
        node.pop();
        db c = abs(u.fi);
        int x = u.se;
        if(!visited[x]){
            if(c <= r)roads.pb(c);
            else rails.pb(c);
            visited[x] = true;
            vis_cnt++;
            for(int i = 0; i < graph[x].size(); i++){
                int v = graph[x][i];
                if(!visited[v]){
                    db c = cost[mp(x,v)];
                    node.push(mp(-1 * c,v));
                }
            }
        }
    }
}

db dist(pii x,pii y){
    db ret = sqrt((x.fi - y.fi)*(x.fi - y.fi)
                + (x.se - y.se)*(x.se - y.se));
    return ret;
}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int kas = 1;
    int T;
    cin>>T;
    while(T--){
        cin>>n>>r;
        vector <pii> point;
        map <pii,int> flag;
        int st = 1;
        fl(i,0,n){
            int x,y;
            cin>>x>>y;
            point.pb(mp(x,y));
            if(!flag[mp(x,y)]){
                flag[mp(x,y)] = st++;
            }
        }

        fl(i,0,n){
            fl(j,i+1,n){
                int u = flag[point[i]];
                int v = flag[point[j]];
                graph[u].pb(v);
                graph[v].pb(u);
                cost[mp(u,v)] = dist(point[i],point[j]);
                cost[mp(v,u)] = dist(point[i],point[j]);
                //cout<<point[i].fi<<sp<<point[i].se<<"---"<<point[j].fi<<sp<<point[j].se<<" ---> ";
                //cout<<dist(point[i],point[j])<<nl;
            }
        }
        prims();
        db mnr = 0,mnrl = 0;
        fl(i,0,roads.size()){
            mnr += roads[i];
        }
        fl(i,0,rails.size()){
            mnrl += rails[i];
        }
        cout<<"Case #"<<kas++<<": ";
        cout<<rails.size()+1<<sp<<round(mnr)<<sp<<round(mnrl)<<nl;

        fl(i,0,n+1){
            graph[i].clear();
        }
        roads.clear();
        rails.clear();
        cost.clear();
    }
    return 0;
}















