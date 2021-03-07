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

bool comp(const pii &a,const pii &b)
{
    return a.second < b.second;
}

vector <int> graph[202];
vector <int> m_graph[202];
map <pii,int> cost;
int n,m,sr,des;
void prims()
{
    int vis_cnt = 1;
    bool visited[n+1];
    map <pii,bool> flag;
    MEM(visited,false);
    visited[1] = true;
    priority_queue <pair<int,pii>> node;
    for(int i = 0; i < graph[1].size(); i++)
    {
        int v = graph[1][i];
        int x = cost[mp(1,v)];
        node.push(mp(x,mp(1,v)));
    }
    while(vis_cnt < n)
    {
        pair<int,pii> u = node.top();
        node.pop();
        int c = u.fi;
        int y = u.se.fi;
        int x = u.se.se;
        if(!visited[x])
        {
            visited[x] = true;
            vis_cnt++;
            if(!flag[mp(x,y)]){
                flag[mp(x,y)] = true;
                flag[mp(y,x)] = true;
                m_graph[x].pb(y);
                m_graph[y].pb(x);

            }
            for(int i = 0; i < graph[x].size(); i++)
            {
                int v = graph[x][i];
                if(!visited[v])
                {
                    int c = cost[mp(x,v)];
                    node.push(mp(c,mp(x,v)));
                }
            }
        }
    }
}

int dijkstra()
{
    bool visited[n+1];
    int distance[n+1];
    fl(i,0,n+1)distance[i] = INT_MAX;
    MEM(visited,false);

    visited[sr] = true;

    priority_queue <pii> node;
    node.push(mp(0,sr));
    while(!node.empty()){
        pii nd = node.top();
        int u = nd.se;
        node.pop();
        for(int i = 0;i < m_graph[u].size();i++){
            int v = m_graph[u][i];
            if(!visited[v]){
                visited[v] = true;
                distance[v] = min(distance[v],min(distance[u],cost[mp(u,v)]));
                node.push(mp(-distance[v],v));
            }
        }
    }
    return distance[des];
}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int kas = 1;
    while(true)
    {
        cin>>n>>m;
        if(n == 0 && m == 0)break;
        map <string,int> mapping;
        int st = 1;
        string a,b;
        fl(i,0,m)
        {
            int u,v,x;
            cin>>a>>b;
            cin>>x;
            if(mapping[a] == 0)
            {
                mapping[a] = st++;
            }
            if(mapping[b] == 0)
            {
                mapping[b] = st++;
            }
            u = mapping[a],v = mapping[b];
            if(cost[mp(u,v)] == 0){
                graph[u].pb(v);
                graph[v].pb(u);
                cost[mp(u,v)] = x;
                cost[mp(v,u)] = x;
            }else{
                if(x > cost[mp(u,v)]){
                    cost[mp(u,v)] = x;
                    cost[mp(v,u)] = x;
                }
            }

        }
        n = st-1;
        cin>>a>>b;
        sr = mapping[a];
        des = mapping[b];

        prims();
        //cout<<"\n==============\n"<<nl;

        /*cout<<"\n-----------------\n"<<nl;
        fl(i,1,n+1){
            cout<<i<<" -> ";
            fl(j,0,graph[i].size())cout<<graph[i][j]<<sp;
            cout<<nl;
        }
        cout<<nl;
        fl(i,1,n+1){
            cout<<i<<" -> ";
            fl(j,0,m_graph[i].size())cout<<m_graph[i][j]<<sp;
            cout<<nl;
        }
        cout<<"\n-----------------\n"<<nl;*/

        int ans = dijkstra();
        cout<<"Scenario #"<<kas++<<nl;
        cout<<ans<<sp<<"tons"<<nl<<nl;;

        fl(i,0,n+1){
            graph[i].clear();
            m_graph[i].clear();
        }
        cost.clear();
    }

    return 0;
}















