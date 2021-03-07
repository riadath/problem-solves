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
#define pi 3.141592653589793238
#define db double
#define fi first
#define se second
#define pi4 pair<pii,pii>
#define all(a) a.begin(),a.end()

bool comp(const pii &a,const pii &b)
{
    return a.second < b.second;
}
vector <int> graph[101][101];
int n,m,q;

bool bfs_col(int sr,int des,int col)
{
    bool visited[109];
    MEM(visited,false);
    visited[sr] = true;
    queue<int>node;
    node.push(sr);
    while(!node.empty())
    {
        int top = node.front();
        node.pop();
        fl(k,0,graph[col][top].size())
        {
            int v = graph[col][top][k];
            if(v == des)return true;
            if(visited[v] == false)
            {
                visited[v] = true;
                node.push(v);
            }
        }

    }
    return false;
}

int main()
{
    FIO;
    //freopen("input.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    cin>>n>>m;
    vector <int> colors;
    map<int,bool> chk;
    fl(i,0,m)
    {
        int x,y,c;
        cin>>x>>y>>c;
        graph[c][x].pb(y);
        graph[c][y].pb(x);
        if(!chk[c])
        {
            chk[c] = true;
            colors.pb(c);
        }
    }
    cin>>q;
    fl(i,0,q)
    {
        int u,v;
        cin>>u>>v;
        int cn = 0;
        fl(i,0,colors.size())
        {
            bool flag = bfs_col(u,v,colors[i]);
            if(flag)cn++;
        }
        cout<<cn<<nl;
    }
    return 0;
}















