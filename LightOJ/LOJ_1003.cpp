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
vector <int> graph[10001];
int n_nodes;
bool cycle()
{
    for(int sr = 1;sr < n_nodes;sr++){
        bool visited[n_nodes+1];
        MEM(visited,false);
        queue <int> nodes;
        nodes.push(sr);
        visited[sr] = true;
        while(!nodes.empty())
        {
            int n = nodes.front();
            nodes.pop();
            fl(i,0,graph[n].size())
            {
                int t = graph[n][i];
                if(t == sr)return false;
                if(!visited[t]){
                    visited[t] = true;
                    nodes.push(t);
                }
            }
        }
    }
    return true;
}

void solve()
{
    int T;
    cin>>T;
    fl(kase,1,T+1){
        n_nodes = 1;
        int n;
        cin>>n;
        map<string,int> m;
        for(int i = 0; i < n; i++){
            string a,b;
            cin>>a>>b;
            if(m[a] == 0)m[a] = n_nodes++;
            if(m[b] == 0)m[b] = n_nodes++;
            graph[m[a]].pb(m[b]);
        }
        bool flag = cycle();
        if(flag)printf("Case %d: Yes\n",kase);
        else printf("Case %d: No\n",kase);
        fl(i,0,n_nodes+1)graph[i].clear();
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
