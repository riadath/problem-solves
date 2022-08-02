#include <bits/stdc++.h>
using namespace std;

#ifdef IHAVETOPEE
#include "debug.h"
#else
#define debug(args)
#endif
#define FIO ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);

int s,t;
int dp[1009];
int prime[10009];
vector<vector<int>>graph(1009);
void sieve(){
    int n = 10008;
    prime[0] = prime[1] = true;
    for (int i = 2; i <= n; i++) {
        if (!prime[i] && i * i <= n) {
            for (int j = i * i; j <= n; j += i)
                prime[j] = true;
        }
    }
}

int bfs(){
    int distance[1009];
    // bool visited[1009];
    // memset(visited,0,sizeof visited);
    memset(distance,-1,sizeof distance);

    // visited[s] = true;
    distance[s] = 0;
    queue<int>node;
    node.push(s);

    while(!node.empty()){
        int u = node.front();
        node.pop();
        
        for(int i = 0;i < graph[u].size();i++){
            int v = graph[u][i];
            if(distance[v] == -1 || (distance[v] != -1 && (distance[u] + 1 < distance[v]))){
                if(distance[v] == -1){
                    distance[v] = 1 + distance[u];
                }
                else 
                    distance[v] = min(distance[v],distance[u] + 1);
                node.push(v);
            }
        }

    }
    return distance[t];
}

int main()
{
    FIO;
    #ifdef IHAVETOPEE 
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    sieve();
    int T;cin>>T;
    int kas = 1;
    // for(int i = 0;i < 100;i++){
    //     cout<<i << " : "<< ((prime[i])?"False":"True")<<"\n";
    // }

    while(T--){
        
        cin>>s>>t;
        queue<int>node;
        node.push(s);
        bool visited[2009];
        memset(visited,0,sizeof visited);
        while(!node.empty()){
            int num = node.front();
            node.pop();
            for(int i = 2;i * i <= num;i++){
                if(num%i == 0){
                    if(num + i <= t && !visited[num + i] && !prime[i]){
                        graph[num].push_back(num+i);
                        node.push(num + i);
                        visited[num + i] = true;
                    }
                    int add = num/i;
                    if(!prime[add] && (num + add <= t)){
                        if(visited[num + add])continue;
                        graph[num].push_back(num + add);
                        node.push(num + add);   
                        visited[num + add] = true;                     
                    }
                }
            }
        }
        // for(int i = s;i <= t;i++){
        //     if(graph[i].size() != 0){
        //         cout<<i<<" : ";
        //         for(int j = 0;j < graph[i].size();j++){
        //             cout<<graph[i][j]<<" ";
        //         }cout<<"\n";
        //     }
        // }

        cout<<"Case "<<kas++<<": ";
        if(s == t){
            cout<<"0\n";
        }else{
            cout<<bfs()<<"\n";
        }
        //clear

        for(int i = 0;i < 1009;i++)graph[i].clear();
    }

    return 0;
}
