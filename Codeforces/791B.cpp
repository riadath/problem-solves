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
bool done[180000];
int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m;
    cin>>n>>m;
    vector <pii> pnts;
    vector <int> graph[n+100];
    map<pii,bool>check;
    fl(i,0,m){
        int x,y;
        cin>>x>>y;
        graph[x].pb(y);
        graph[y].pb(x);
        pnts.pb(mp(x,y));
        check[mp(x,y)] = true;
        check[mp(y,x)] = true;
    }
    bool flag = true;
    fl(i,0,m){
        int x = pnts[i].fi;
        int y = pnts[i].se;
        if(done[x] && done[y])continue;
        done[x] = true;
        done[y] = true;
        fl(k,0,graph[x].size()){
            int t = graph[x][k];
            if(t == y)continue;
            if(check[mp(y,t)] == false){
                flag = false;
                break;
            }
        }
        if(!flag)break;
        fl(k,0,graph[y].size()){
            int t = graph[y][k];
            if(t == x)continue;
            if(check[mp(x,t)] == false){
                flag = false;
                break;
            }
        }
        if(!flag)break;
    }
    if(flag)cout<<"YES"<<nl;
    else cout<<"NO"<<nl;
    return 0;
}
















