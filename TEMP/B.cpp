#include <bits/stdc++.h>
using namespace std;

#ifdef IHAVETOPEE
#include "debug.h"
#else
#define debug(args)
#endif
#define FIO ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);

int n,m;
vector<vector<int>>graph(1009);
int d[1009],f[1009],low[1009],parent[1009],color[1009],time_in = 0;
bool visited[1009],if_ap[1009];
map<pair<int,int>,string>edge_type;
vector<int>top_sort;

void dfs(int u){
    visited[u] = true;
    d[u] = time_in++;
    low[u] = d[u];
    for(int v : graph[u]){
        if(parent[u] == v)continue;
        if(visited[v]){
            low[u] = min(low[v],d[u]);
        }
        else{
            parent[v] = u;
            dfs(v);
            low[u] = min(low[u],low[v]);
            if(d[u] <= low[v] && u != 1)if_ap[u] = true;
        }
    }
    f[u] = time_in++;
}

void dfs1(int u){
    color[u] = 1;
    cout<<u<<"____> : \n";
    d[u] = time_in++;
    for(int v : graph[u]){
        if(color[v] == 0){
            debug(v);
            edge_type[{u,v}] = edge_type[{v,u}] = "TREE_EDGE";
            dfs1(v);
        }
        else if(color[v] == 1){
            if(edge_type[{u,v}] != "")continue;
            edge_type[{u,v}] = edge_type[{v,u}] = "BACK_EDGE";
        }
        else if(color[v] == 2){
            if(edge_type[{u,v}] != "")continue;
            edge_type[{u,v}] = edge_type[{v,u}] = "CORSS/FORWARD";
        }
    }
    color[u] = 2;
    f[u] = time_in++;
    // cout<<u<<" -> "<<f[u]<<"\n";
    top_sort.push_back(u);
}
int main()
{
    FIO;
    #ifdef IHAVETOPEE 
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    cin>>n>>m;
    vector<pair<int,int>>edges;
    for (size_t i = 0; i < m; i++)
    {
        int u,v;cin>>u>>v;
        edges.push_back({u,v});
        graph[u].push_back(v);
        // graph[v].push_back(u);
    }
    // dfs(1);
    // if(graph[1].size() > 1)if_ap[1] = true;
    // for(int i = 0;i < n;i++){
    //     if(if_ap[i+1])cout<<i+1<<" is a ap\n";
    // }
   

    // for(int i = 1;i <= n;i++){
    //     if(color[i] == 0)dfs1(i);
    // }
    debug(edge_type);
    for(pair<int,int>t : edges){
        cout<<t.first<<"-"<<t.second<<" "<<edge_type[t]<<'\n';
    }
    reverse(top_sort.begin(),top_sort.end());
    for(int i : top_sort){
        cout<<i<<" ";
    }cout<<"\n";
    return 0;
}
