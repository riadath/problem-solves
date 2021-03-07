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
vector <int> mat[101];
int n,m,bench = 0;
int color[101];
void odd_cycle(int sr)
{
    queue <int> node;
    node.push(sr);
    color[sr] = 1;
    while(!node.empty())
    {
        int n = node.front();
        node.pop();
        for(int i = 0; i < mat[n].size(); i++)
        {
            int t = mat[n][i];
            if(color[t] == -1){
                color[t] = 1-color[n];
                node.push(t);
            }
            else if(color[t] == color[n]){
                bench++;
                return;
            }
        }
    }
}

void solve()
{
    MEM(color,-1);
    int n,m;
    cin>>n>>m;
    fl(i,0,m)
    {
        int x,y;
        cin>>x>>y;
        mat[x].pb(y);
        mat[y].pb(x);
    }
    for(int i = 1; i <= n; i++)
    {
        if(color[i]==-1)
            odd_cycle(i);
    }
    int remain = n-bench;
    if(remain%2 == 1)bench++;
    cout << bench << "\n";
}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}

