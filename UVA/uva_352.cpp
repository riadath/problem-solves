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
int dirx[] = {0,1,-1,0,0,1,-1,1,-1};
int diry[] = {0,0,0,1,-1,1,1,-1,-1};
map <pii,vector<pii>> graph;
int n;
int bfs_p(int sx,int sy,int dx,int dy)
{
    bool visited[25][25];
    int dist[25][25];
    MEM(visited,false);
    fl(i,0,25)fl(j,0,25)dist[i][j] = INT_MAX;
    queue <pii>gp;
    gp.push(mp(sx,sy));
    dist[sx][sy] = 0;
    visited[sx][sy] = true;
    while(!gp.empty()){
        pii top = gp.front();
        gp.pop();
        for(auto i = graph[top].begin();i != graph[top].end();i++){
            int x = i->first,y = i->second;
            if(!visited[x][y] && dist[x][y]==INT_MAX){
                dist[x][y] = dist[top.first][top.second] + 1;
                if(x == dx&&y==dy)return dist[x][y];
                visited[x][y] = true;
                gp.push(mp(x,y));
            }
        }
    }
    return INT_MAX;
}

void solve()
{
    int T = 1;
    while(scanf("%d",&n)!=EOF)
    {
        graph.clear();
        int cnt = 0;
        vector <int> mat[n];
        fl(i,0,n){
            string a;
            cin>>a;
            fl(j,0,n){
                int temp = a[j]-'0';
                mat[i].pb(temp);
            }
        }
        fl(i,0,n){
            fl(j,0,n){
                if(mat[i][j]==1){
                    fl(k,0,9){
                        if(i+dirx[k]<n&&i+dirx[k]>=0&&j+diry[k]<n&&j+diry[k]>=0){
                            if(mat[i+dirx[k]][j+diry[k]] == 1){
                                graph[mp(i,j)].pb(mp(i+dirx[k],j+diry[k]));
                            }
                        }
                    }
                }
            }
        }

        int eagles = 0;
        fl(i,0,n)fl(j,0,n){
            if(mat[i][j]==1){
                eagles++;
                fl(k,0,n)fl(l,0,n){
                    if(mat[k][l] == 1){
                        if(k==i&&l==j)continue;
                        if(bfs_p(i,j,k,l)!=INT_MAX)mat[k][l] = 0;
                    }
                }
                mat[i][j] = 0;
            }
        }
        printf("Image number %d contains %d war eagles.\n",T++,eagles);

    }
}
int main()
{
    //FIO;

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}

