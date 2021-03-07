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
#define pll pair<long, long>
#define lcm(a, b) a *b / __gcd(a, b)
#define fl(i, a, b) for (ll i = a; i < b; i++)
#define lf(i, b, a) for (ll i = b; i >= a; i--)
#define MEM(x, y) memset(x, y, sizeof(x))
#define mp make_pair
#define bs(x, y) binary_search(x.begin(), x.end(), y)
#define nl "\n"
#define sp " "
#define srt(x) sort(x.begin(), x.end())
#define srta(x,n) sort(x,x+n)
#define pi 3.141592653589793238
#define db double
#define fi first
#define se second
#define pi4 pair<pii,pii>

bool comp(const int a,const int b)
{
    return a > b;
}
double dt(int x1,int y1,int x2,int y2)
{
    return sqrt(pow(x1-x2,2) + pow(y1-y2,2));
}

vector <int> graph[50];
int n,m;
int cx,cy;
int dirx[] = {1,-1,0,0};
int diry[] = {0,0,1,-1};
int bfs(int x,int y){
    int cn = 0;
    bool visited[30][30];
    MEM(visited,false);
    visited[x][y] = true;
    graph[x][y] = 0;
    cn++;
    queue <pii> node;
    node.push(mp(x,y));
    while(!node.empty()){
        pii top = node.front();
        node.pop();
        int sx = top.fi,sy = top.se;
        fl(k,0,4){
            int dx = sx + dirx[k];
            int dy = sy + diry[k];
            if(dy == m)dy = 0;
            if(dy == -1)dy = m-1;
            if(dx >= 0 && dx < n && dy >= 0 && dy < m){
                if(!visited[dx][dy] && graph[dx][dy]){
                    visited[dx][dy] = true;
                    graph[dx][dy] = 0;
                    cn++;
                    node.push(mp(dx,dy));
                }
            }
        }
    }
    return cn;
}

void solve()
{
    while(cin>>n>>m){
        string mat[n];
        fl(i,0,n)cin>>mat[i];
        cin>>cx>>cy;
        fl(i,0,n){
            fl(j,0,m){
                if(mat[i][j] == mat[cx][cy])graph[i].pb(1);
                else graph[i].pb(0);
            }
        }
        /*fl(i,0,n){
            fl(j,0,m)cout<<graph[i][j]<<sp;
            cout<<nl;
        }*/
        bfs(cx,cy);
        int mx = 0;
        fl(i,0,n){
            fl(j,0,m){
                if(graph[i][j]){
                    int temp = bfs(i,j);
                    mx = max(mx,temp);
                }
            }
        }
        cout<<mx<<nl;
        fl(i,0,50)graph[i].clear();
    }

}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}



