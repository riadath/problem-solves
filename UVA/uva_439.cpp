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
#define bs(x,y) binary_search(x.begin(),x.end(),y)
#define nl "\n"
#define sp " ";
int dirx[] = {2,-2,2,-2,1,-1,1,-1};
int diry[] = {1,1,-1,-1,2,2,-2,-2};

int bfs_p(pii sr,pii des)
{
    if(sr == des)
        return 0;
    bool visited[10][10];
    int dist[10][10];
    MEM(dist,-1);
    MEM(visited,false);
    visited[sr.first][sr.second] = true;
    dist[sr.first][sr.second] = 0;
    queue <pii> nodes;
    nodes.push(sr);
    while(!nodes.empty())
    {
        pii top = nodes.front();
        nodes.pop();
        fl(i,0,8)
        {
            int x = top.first + dirx[i];
            int y = top.second + diry[i];
            if(x>=1&&x<=8&&y>=1&&y<=8 && !visited[x][y])
            {
                dist[x][y] = dist[top.first][top.second] + 1;
                visited[x][y] = true;
                if(x==des.first&&y==des.second)
                    return dist[x][y];
                nodes.push(mp(x,y));
            }
        }
    }
    return dist[des.first][des.second];
}
void solve()
{
    string a,b;
    while(cin>>a>>b)
    {
        pii sr,des;
        sr = mp(a[0]-'a'+1,a[1]-'0');
        des = mp(b[0]-'a'+1,b[1]-'0');
        int ans = bfs_p(sr,des);
        cout<<"To get from "<<a<<" to "<<b<<" takes "<<ans<<" knight moves."<<nl;
    }
}

int main()
{
    // FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}
