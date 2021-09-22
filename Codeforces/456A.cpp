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

int main()
{
    FIO;
    #ifdef IHAVETOPEE 
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
   
    int n;cin>>n;
    vector<pii>arr;
    fl(i,0,n){
        int u,v;cin>>u>>v;
        arr.pb(mp(u,v));
    }
    sort(all(arr));
    debug(arr);
    bool flag = false;
    fl(i,0,n){
        int lo = 0,hi = i;
        debug(lo);debug(hi);
        while(lo < hi){
            int mid = (lo + hi)/2;
            debug(mid);
            if(arr[mid].se >  arr[i].se && arr[mid].fi < arr[i].fi && i != mid){
                flag = true;
                break;
            }
            else if(arr[mid].fi >= arr[i].fi){
                hi = mid-1;
            }
            else lo = mid+1;

        }
        if(flag)break;
    }
    if(flag)cout<<"Happy Alex"<<nl;
    else cout<<"Poor Alex"<<nl;
    return 0;
}
