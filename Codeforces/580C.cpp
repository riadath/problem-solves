
#include <bits/stdc++.h>
using namespace std;
long long oll = 0;
#define ll long long
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define pii pair<int,int>
#define lcm(a,b) a*b/__gcd(a,b)
#define fl(i,a,b) for(int i = a;i < b;i++)
#define lf(i,a,b) for(int i = b;i >= a;i--)
#define MEM(x,y) memset(x,y,sizeof(x))
#define mp make_pair
vector <int> graph[100010];
bool cats[100010],visited[100010],pos[100010];
int nc[100010];
int sz,m;
void bfs_cats()
{
    queue <int> node;
    MEM(visited,false);
    MEM(nc,0);
    MEM(pos,true);
    node.push(1);
    visited[1] = true;
    if(cats[1])nc[1] = 1;
    while(!node.empty()){
        int n = node.front();
        node.pop();
        for(int i = 0;i < graph[n].size();i++){
            if(!visited[graph[n][i]]){
                int x = graph[n][i];
                if(cats[n] && cats[x]){
                    nc[x] = nc[n] + 1;
                    if(nc[x] > m){
                        pos[x] = false;
                    }
                }
                else if(cats[x] && !cats[n]) {
                   if(nc[n] > m){
                        pos[x] = false;
                        nc[x] = nc[n];
                   }else{
                        nc[x] = 1;
                   }
                }
                else if(!cats[x]){
                    if(nc[n] > m){
                        pos[x] = false;
                        nc[x] = nc[n];
                    }else{
                        nc[x] = 0;
                    }
                }
                visited[x] = true;
                node.push(x);
            }
        }
    }
}

void solve()
{
    cin>>sz>>m;
    for(int i = 1;i <= sz;i++){
        cin>>cats[i];
    }
    for(int i = 0;i < sz-1;i++){
        int x,y;
        cin>>x>>y;
        graph[x].pb(y);
        graph[y].pb(x);
    }
    bfs_cats();
    int ans = 0;
    for(int i = 2;i <= sz;i++){
        //cout << "i : " << i << " Possible: " << pos[i] << " \n";
        if(graph[i].size() == 1 && pos[i]){
            ans++;
        }
    }
    cout << ans << endl;

}

int main()
{
    FIO;
    // freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}
