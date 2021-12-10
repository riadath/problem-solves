#include <bits/stdc++.h>
using namespace std;

#ifdef IHAVETOPEE
#include "debug.h"
#else
#define debug(args)
#endif

long long oll = 0;
#define ll long long
#define ull unsigned long long
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define pb push_back
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define lcm(a, b) a *b / __gcd(a, b)
#define fl(i, a, b) for (ll i = (int)a; i < (int)b; i++)
#define lf(i, b, a) for (ll i = (int)b; i >= (int)a; i--)
#define MEM(x, y) memset(x, y, sizeof(x))
#define mp make_pair
#define bs(x, y) binary_search(x.begin(), x.end(), y)
#define srt(x) sort(x.begin(), x.end())
#define pi 3.141592653589793238
#define fi first
#define se second
#define all(a) a.begin(), a.end()

bool comp(const pii &a, const pii &b)
{
    return a.se > b.se;
}

int n,dis[30],fin[30],dfsTimer = 0;
bool flag = true, visited[30],visited2[30];
vector<string>str;
vector<vector<int>>graph(26);
string ans = "";

void DFS(int u){
     if(visited2[u]){
        flag = 0;
        return;
    }
     if(visited[u]){
        return;
    }
    dis[u] = dfsTimer++;

    visited[u] = true;
    visited2[u] = true;

    fl(i,0,graph[u].size()){
        int v = graph[u][i];
        if(visited2[v]){
            flag = false;
            return;
        }
        if(!visited[v])DFS(v);
    }
    fin[u] = dfsTimer++;
    visited2[u] = false;
}

int main()
{
    FIO;
#ifdef IHAVETOPEE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    cin >> n;
    fl(i, 0, n) {
        string ttemp;
        cin>>ttemp;
        str.pb(ttemp);
    }

    fl(i,0,n-1){
        bool tflag = 0;
        fl(j,0,min(str[i].size(),str[i+1].size())){
            int u = str[i][j] - 'a',v = str[i+1][j] - 'a';
            if(u != v){
                graph[u].pb(v);
                tflag = 1;
                break;
            }
        }
        if(!tflag && str[i].size() > str[i+1].size()){
            flag = false;
            break;
        }
    }
    // fl(i,0,26){
    //     char c = 'a' + i;
    //     cout<<c<<" : ";
    //     fl(j,0,graph[i].size()){
    //         char ch = 'a' + graph[i][j];
    //         cout<<ch<<" ";
    //     }cout<<"\n";
    // }
    
    fl(i,0,26)if(!visited[i])DFS(i);

    if(!flag){
        cout<<"Impossible\n";
        return 0;
    }
    vector<pii>srlist;
    for(int i = 0;i < 26;i++){
        srlist.pb(mp(i,fin[i]));
    }
    sort(all(srlist),comp);
    for(int i = 0;i < 26;i++){
        char c = 'a' + srlist[i].first;
        ans.pb(c);
    }
    cout<<ans<<"\n";

    return 0;
}
