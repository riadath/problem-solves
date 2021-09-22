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
#define nl "\n"
#define sp " "
#define srt(x) sort(x.begin(), x.end())
#define pi 3.141592653589793238
#define db double
#define fi first
#define se second
#define pi4 pair<pii, pii>
#define all(a) a.begin(), a.end()

bool comp(const pii &a, const pii &b)
{
    return a.fi < b.fi;
}

 int degree[200000 + 1],power[200000+1];

int main()
{

    FIO;
    #ifdef IHAVETOPEE 
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    int n,m;cin>>n>>m;
    fl(i,0,m){
        int u,v;
        cin>>u>>v;
        int mx = max(u,v);
        int mn = min(u,v);
        degree[mx]++,degree[mn]++;
        power[mx]++;
    }
    int cnt = 0;
    fl(i,1,n+1)if(degree[i] == power[i])cnt++;
    int q;cin>>q;
    while(q--){
        int mode;
        cin>>mode;
        if(mode == 1){
            int u,v;cin>>u>>v;
            if(degree[u] == power[u])cnt--;
            if(degree[v] == power[v])cnt--;
            degree[u]++,degree[v]++;
            power[max(u,v)]++;

            if(degree[u] == power[u])cnt++;
            if(degree[v] == power[v])cnt++;
        }else if(mode == 2){
            int u,v;cin>>u>>v;
            if(degree[u] == power[u])cnt--;
            if(degree[v] == power[v])cnt--;
            degree[u]--,degree[v]--;
            power[max(u,v)]--;

            if(degree[u] == power[u])cnt++;
            if(degree[v] == power[v])cnt++;
        }else if(mode == 3){
            cout<<cnt<<nl;
        }
    }
    return 0;
}
