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
int n,m;
vector<vector<int>>G(1009),adj_G(1009);
int visited[1009],time_in = 0;
vector<int>order,component;
void dfs1(int u){
    visited[u] = true;
    for(int v : G[u]){
        if(!visited[v])dfs1(v);
    }
    order.push_back(u);
}
void dfs2(int u){
    visited[u] = true;
    component.push_back(u);
    for(int v : adj_G[u]){
        if(!visited[v])dfs2(v);
    }
}
int main()
{
    FIO;
    #ifdef IHAVETOPEE 
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    cin>>n>>m;
    for (size_t i = 0; i < m; i++)
    {
        int u,v;cin>>u>>v;
        G[u].push_back(v);
        adj_G[v].push_back(u);
    }
    for(int i = 1;i <= n;i++){
        if(!visited[i])dfs1(i);
    }
    memset(visited,0,sizeof visited);
    reverse(order.begin(),order.end());
    for(int node : order){
        component.clear();
        if(!visited[node])dfs2(node);
        if(component.size() == 0)continue;
        for(int t : component){
            cout<<t<<" ";
        }cout<<"\n";
    }

    return 0;
}
