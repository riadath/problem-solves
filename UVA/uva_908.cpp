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

vector <int> graph[1000009];
map <pii,int> cost;
int n,m,k;
int prims()
{
    int vis_cnt = 1;
    int ret = 0;
    bool visited[n+1];
    MEM(visited,false);
    visited[1] = true;
    priority_queue <pii> node;
    for(int i = 0;i < graph[1].size();i++){
        int v = graph[1][i];
        int x = cost[mp(1,v)];
        node.push(mp(-1 * x,v));
    }
    while(vis_cnt < n){
        pii u = node.top();
        node.pop();
        int c = u.fi;
        int x = u.se;
        if(!visited[x]){
            ret += abs(c);
            visited[x] = true;
            vis_cnt++;
            for(int i = 0; i < graph[x].size(); i++){
                int v = graph[x][i];
                if(!visited[v]){
                    int c = cost[mp(x,v)];
                    node.push(mp(-1 * c,v));
                }
            }
        }
    }
    return ret;
}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int kas = 1;
    while(cin>>n){
        map<int,bool>cnt;
        int tot = 0;
        if(kas++ != 1)cout<<nl;
        int init_cost = 0;
        fl(i,0,n-1){
            int u,v,x;
            cin>>u>>v>>x;
            init_cost += x;
        }
        cin>>k;
        fl(i,0,k){
            int u,v,x;
            cin>>u>>v>>x;
            if(!cnt[u]){
                cnt[u] = true;
                tot++;
            }
            if(!cnt[v]){
                cnt[v] = true;
                tot++;
            }
            if(cost[mp(u,v)] == 0){
                graph[u].pb(v);
                graph[v].pb(u);
                cost[mp(u,v)] = x;
                cost[mp(v,u)] = x;
            }
            else if(x < cost[mp(u,v)]){
                cost[mp(u,v)] = x;
                cost[mp(v,u)] = x;
            }
        }
        cin>>m;
        fl(i,0,m){
            int u,v,x;
            cin>>u>>v>>x;
            if(!cnt[u]){
                cnt[u] = true;
                tot++;
            }
            if(!cnt[v]){
                cnt[v] = true;
                tot++;
            }
            if(cost[mp(u,v)] == 0){
                graph[u].pb(v);
                graph[v].pb(u);
                cost[mp(u,v)] = x;
                cost[mp(v,u)] = x;
            }else if(x < cost[mp(u,v)]){
                cost[mp(u,v)] = x;
                cost[mp(v,u)] = x;
            }
        }
        n = tot;
        cout<<init_cost<<nl<<prims()<<nl;
        fl(i,0,n+1){
            graph[i].clear();
        }
        cost.clear();
    }
    return 0;
}















