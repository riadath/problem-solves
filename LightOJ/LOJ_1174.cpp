#include <bits/stdc++.h>
using namespace std;

#ifdef IHAVETOPEE
#include "debug.h"
#else
#define debug(args)
#endif

#define ll long long
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define lcm(a, b) a *b / __gcd(a, b)
#define MEM(x, y) memset(x, y, sizeof(x))
#define PI acos(0)*2
#define fi first
#define se second
#define all(a) a.begin(), a.end()

int n,m,s,d;
vector<vector<int>>graph(200);
int dist1[200],dist2[200];

void bfs(int src,int type){
    int distance[200];
    bool visited[200];

    MEM(visited,false);
    for (int i = 0; i < n; i++)distance[i] = 1e5;

    visited[src] = true;
    distance[src] = 0;

    queue<int>node;
    node.push(src);

    while(!node.empty()){
        int u = node.front();
        node.pop();
        for(int i = 0;i < graph[u].size();i++){
            int v = graph[u][i];
            if(!visited[v]){
                node.push(v);
                visited[v] = true;
                distance[v] = min(distance[v],distance[u] + 1);
            }
        }
    }
    for(int i = 0;i < n;i++){
        if(type == 1)dist1[i] = distance[i];
        else dist2[i] = distance[i];
    }
}

int main()
{
    FIO;
    #ifdef IHAVETOPEE 
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    
    int T,kas = 1;cin>>T;
    while(T--){
        cout<<"Case "<<kas++<<": ";

        cin>>n>>m;
        for(int i = 0;i < m;i++){
            int u,v;
            cin>>u>>v;
            graph[u].pb(v);
            graph[v].pb(u);
        }
        cin>>s>>d;
        debug(s);debug(d);
        // debug(graph);
        bfs(s,1);
        bfs(d,2);

        int mx1 = 0;
        for(int i = 0;i < n;i++){
            debug(i);debug(dist1[i]);debug(dist2[i]);
            mx1 = max(mx1,dist1[i]+dist2[i]);
        }
        
        cout<<mx1<<"\n";
        

        //clear
        for(int i = 0;i < 200;i++)graph[i].clear();
        MEM(dist1,0);MEM(dist2,0);
    }
    return 0;       
}
// aaabbbccaa#abb