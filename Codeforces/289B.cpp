#include <bits/stdc++.h>
using namespace std;

#ifdef IHAVETOPEE
#include "debug.h"
#else
#define debug(args...)
#endif

#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
#define pi4 pair<pii, pii>
#define all(a) a.begin(), a.end()

bool comp(const pii &a, const pii &b)
{
    return a.fi < b.fi;
}
int mat[109][109];
int main()
{
    FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int n,m,d;
    cin>>n>>m>>d;
    vector<int>arr;
    fl(i,0,n)fl(j,0,m)cin>>mat[i][j],arr.pb(mat[i][j]);
    sort(all(arr));
    int len = (int)arr.size();
    int mn_move = 1e8;
    for(int k = len/4;k <= (3 * len)/4;k++){
        int to_comp = arr[k],temp_move = 0;
        fl(i,0,n){
            fl(j,0,m){
                int diff = abs(to_comp - mat[i][j]);
                if(diff % d != 0){
                    temp_move = -1;
                    break;
                }else{
                    temp_move += diff/d;
                }
            }
            if(temp_move == -1)break;
        }
        if(temp_move != -1)
            mn_move = min(mn_move,temp_move);
    }
    if(mn_move == 1e8)cout<<-1<<nl;
    else cout<<mn_move<<nl;
    return 0;
}