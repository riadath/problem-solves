#include <bits/stdc++.h>
using namespace std;
vector <int> graph[100];
map <int,int> m;
int mod_bfs(int source,int ttl,int n)
{
    int level[n];
    bool visited[n];
    for(int i = 0; i < n; i++)
    {
        visited[i] = false;
        level[i] = INT_MAX;
    }
    visited[source] = true;
    level[source] = 0;
    queue <int> nodes;
    nodes.push(source);
    int can_reach = 0;
    while(!nodes.empty())
    {
        int i = nodes.front();
        nodes.pop();
        for(int j = 0; j < graph[i].size(); j++)
        {
            if(level[i] != INT_MAX && level[graph[i][j]] == INT_MAX && !visited[graph[i][j]])
            {
                level[graph[i][j]] = level[i] + 1;
                visited[graph[i][j]] = true;
                nodes.push(graph[i][j]);
                if(level[graph[i][j]] <= ttl)
                    can_reach++;
            }
        }
    }
    return can_reach;
}

int main()
{
    int kase = 1;
    int nc;
    while(scanf("%d",&nc) && nc)
    {
        map <int,int> m;
        m.clear();
        int num_nodes = 1;
        for(int i = 0; i < nc; i++)
        {
            int p,q;
            scanf("%d %d",&p,&q);
            if(m[p] == 0){
                m[p] = num_nodes++;
            }
            if(m[q] == 0){
                m[q] = num_nodes++;
            }
            graph[m[p]].push_back(m[q]);
            graph[m[q]].push_back(m[p]);
        }
        //----------
        /*cout<<m.size()<<endl;
        for(int i = 0;i < num_nodes;i++){
                cout<<i<<"------> ";
            for(int j = 0;j < graph[i].size();j++){
                cout<<graph[i][j]<<" ";
            }
            cout<<endl;
        }*/
        int source,ttl;
        while(scanf("%d %d",&source,&ttl) && source)
        {
            int can_reach = mod_bfs(m[source],ttl,num_nodes);
            //cout<<"Can reach: "<<can_reach<<endl;
            int ans = (num_nodes - can_reach) - 2;
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",kase++,ans,source,ttl);
        }
        for(int i = 0;i < num_nodes;i++){
            graph[i].clear();
        }
    }
    return 0;
}










