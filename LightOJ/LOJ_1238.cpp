#include <bits/stdc++.h>
using namespace std;

#ifdef IHAVETOPEE
#include "debug.h"
#else
#define debug(args)
#endif
#define FIO ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);

int dirx[] = {1,-1,0,0};
int diry[] = {0,0,1,-1};
string mat[109];
int n,m;
bool check(int x,int y){
    if(mat[x][y] == 'm' || mat[x][y] == '#' 
    || x >= n || y >= m || x < 0 || y < 0)return false;
    return true;
}
int bfs(pair<int,int> src, pair<int,int>dest){
    int distance[109][109];
    memset(distance,-1,sizeof distance);
    distance[src.first][src.second] = 0;
    queue<pair<int,int>>node;
    node.push(src);
    while(!node.empty()){
        pair<int,int> u = node.front();
        node.pop();
        for(int k = 0;k < 4;k++){
            pair<int,int> v = {u.first + dirx[k],u.second + diry[k]};
            if(check(v.first,v.second)){
                if(distance[v.first][v.second] == -1){
                    distance[v.first][v.second] = 1 + distance[u.first][u.second];
                    node.push(v);
                    if(v == dest){
                        return distance[v.first][v.second];
                    }
                }
            }
        }
    }
    return -1;
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
        pair<int,int> s1,s2,s3,dest;
        for(int i = 0;i < n;i++){
            cin>>mat[i];
            for(int j = 0;j < m;j++){
                if(mat[i][j] == 'a')s1 = {i,j};
                else if(mat[i][j] == 'b')s2 = {i,j};
                else if(mat[i][j] == 'c')s3 = {i,j};
                else if(mat[i][j] == 'h')dest = {i,j};
            }
        }
        debug(s1);debug(s2);debug(s3);debug(dest);
        int d1 = bfs(s1,dest);
        int d2 = bfs(s2,dest);
        int d3 = bfs(s3,dest);
        cout<<max(d1,max(d2,d3))<<"\n";
    }

    return 0;
}
