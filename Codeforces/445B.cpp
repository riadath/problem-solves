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

bool comp(const pll &a,const pll &b)
{
    return a.second >= b.second;
}
bool av[100];
 vector <ll> graph[100];
int bfs(int sr)
{
    int cn = 1;
    bool visited[100];
    MEM(visited,false);
    visited[sr] = true;
    queue <int> node;
    node.push(sr);
    while(!node.empty())
    {
        int top = node.front();
        av[top] = true;
        node.pop();
        fl(i,0,graph[top].size()){
            int x = graph[top][i];
            if(!visited[x]){
                visited[x] = true;
                av[x] = true;
                cn++;
                node.push(x);
            }
        }
    }
    return cn;
}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ll n,m;
    cin>>n>>m;

    fl(i,0,m){
        ll x,y;
        cin>>x>>y;
        graph[x].pb(y);
        graph[y].pb(x);
    }
    ll danger = 1;
    fl(i,1,n+1){
        if(!av[i]){
            int cn = bfs(i);
            danger *= pow(2,cn-1);
        }
    }
    cout<<danger<<nl;
    return 0;
}















