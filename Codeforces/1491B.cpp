#include <bits/stdc++.h>
using namespace std;
#ifdef IHAVETOPEE
#include "debug.h"
#else
#define debug(args...)
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

int main()
{
    FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {   
        ll n,u,v,mx = 0,mn = 1e18;
        cin>>n>>u>>v;
        vector<ll>arr(n);
        fl(i,0,n)cin>>arr[i],mx = max(mx,arr[i]),mn = min(mn,arr[i]);
        ll mx_dif = 0;
        fl(i,0,n-1){
            mx_dif = max(mx_dif,abs(arr[i] - arr[i + 1]));
        }
        // debug(mx_dif);
        if((mx == mn))cout<<min(u+v,2ll*v)<<nl;
        else if(mx_dif > 1)cout<<0<<nl;
        else cout<<min(u,v)<<nl;
    }
    return 0;
}
