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

vector <int> graph[109];
map <pii,db> cost;
int n,m,k;
db prims()
{
    int vis_cnt = 1;
    db ret = 0;
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
        db c = u.fi;
        int x = u.se;
        if(!visited[x]){
            ret += abs(c);
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
    return ret;
}
db dist(pdd x,pdd y){
    return sqrt((x.fi - y.fi)*(x.fi - y.fi)
                + (x.se - y.se)*(x.se - y.se));
}

int main()
{
    //FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int kas = 1;
    int T;
    cin>>T;
    while(T--){
        if(kas++ != 1)cout<<nl;
        cin>>n;
        map<pdd,int> mapping;
        vector <pdd> point;
        int st = 1;
        fl(i,0,n){
            db x,y;
            cin>>x>>y;
            mapping[mp(x,y)] = st++;
            point.pb(mp(x,y));
        }
        fl(i,0,n){
            fl(j,0,n){
                if(j == i)continue;
                int u = mapping[point[i]];
                int v = mapping[point[j]];
                graph[u].pb(v);
                cost[mp(u,v)] = dist(point[i],point[j]);
            }
        }
        printf("%0.2lf\n",prims());
        fl(i,0,n+1){
            graph[i].clear();
        }
        cost.clear();
    }
    return 0;
}















