#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fi first
#define se second

vector<vector<pii>>graph(1009);
vector<pair<int,pii>>e;
int n,m,INF = 1e7;
int dist[1009][1009],h[1009];

template <typename T> struct priorityQueue{
    vector<T> arr;
    int left(int i){return (2*i+1);}
    int right(int i){return left(i)+1;}
    int root(int i){return ((i+1)/2 - 1);}
    bool empty() {
        return !arr.size();
    }
    void push(T x) {
        arr.push_back(x);
        int i = arr.size() - 1;
        int rt = root(i);
        while (rt >= 0 && arr[i] < arr[rt]) {
                swap(arr[i], arr[rt]);
                i = rt, rt = root(i);
        }
    }
    T top() {
        assert(!arr.empty());
        return arr[0];
    }

    T pop() {
        assert(!arr.empty());
        T ret = arr[0];
        swap(arr[0], arr.back());
        arr.pop_back();
        int i = 0;
        while (left(i) < (int)arr.size()) {
                int j = left(i);
                if (j + 1 < (int)arr.size() && arr[j + 1] < arr[j]) j++;
                if (arr[j] >= arr[i]) break;
                swap(arr[i], arr[j]);
                i = j;
        }
        return ret;
    }
};

void dijkstra(int src){
    for(int i = 0;i <= n;i++){
        dist[src][i] = INF;
    }
    dist[src][src] = 0;
    priorityQueue<pii>node;
    node.push({0,src});
    while(!node.empty()){
        pii t = node.top();node.pop();
        int u = t.se;
        if(dist[src][u] < t.fi)continue;
        for(int i = 0;i < graph[u].size();i++){
            int v = graph[u][i].fi;
            int w = graph[u][i].se + h[u] - h[v];
            if(dist[src][v] > dist[src][u]+w){
                dist[src][v] = dist[src][u] + w;
                node.push({dist[src][v],v});
            }
        }
    }
}

bool bellman_ford(int src){
    vector<int> d(1009,INF);
    d[src] = 0;
    for(int i = 1;i <= n+2;i++){
        bool flag = true;
        for(int j = 0;j < (int)e.size();j++){
            if(d[e[j].fi] < INF){
                if(d[e[j].se.fi] > d[e[j].fi] + e[j].se.se){
                    if(i == n+2)return false;
                    d[e[j].se.fi] = d[e[j].fi] + e[j].se.se;
                    flag = false;
                }
            }
        }
        if(flag)break;
    }
   
    for(int i = 1;i <= n;i++)h[i] = d[i];
     for(int i = 1;i <= n;i++){
        cout<<"h["<<i<<"] : "<<h[i]<<"\n";
    }
    return true;
}

void jhonsons(){
    for(int i = 1;i <= n;i++){
        e.push_back({n+1,{i,0}});
    }
    if(!bellman_ford(n+1)){
        cout<<"Graph has negative-weight cycle\n";
        return;
    }
    for(int i = 1;i <= n;i++){
        dijkstra(i);
    }
    cout<<"Distance from i => j : \n";
    for(int u = 1;u <= n;u++){
        for(int v = 1;v <= n;v++){
            if(dist[u][v] == INF)continue;
            dist[u][v] = dist[u][v] + h[v] - h[u];
            cout<<u<<" => "<<v<<" : "<<dist[u][v]<<"\n";
        }
    }
}

int main(){
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    cin>>n>>m;
    for (int i = 0; i < m; i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        e.push_back({u,{v,w}});
    }
    
    jhonsons();

    return 0;
}