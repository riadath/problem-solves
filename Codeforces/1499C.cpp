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
        int n;cin>>n;
        vector<ll>alC(n);fl(i,0,n)cin>>alC[i];
        vector<ll>odd(n,0),even(n,0),mino(n,1e17),mine(n,1e17);
        odd[0] = alC[0],even[0] = 0,mino[0] = alC[0],mine[0] = 1e17;
        fl(i,1,n){
            if(i%2){
                even[i] = alC[i] + even[i-1],odd[i] = odd[i-1];
                mine[i] = min(alC[i],mine[i-1]),mino[i] = mino[i-1];
            }else{
                odd[i] = alC[i] + odd[i-1],even[i] = even[i-1];
                mino[i] = min(alC[i],mino[i-1]),mine[i] = mine[i-1];
            }
        }
        // debug(even);debug(odd);
        ll cur_min = 7e18;
        fl(i,1,n){
            ll cnte = (i+1)/2,cnto = (i+1)/2 + (i+1)%2;
            ll cur = even[i] + (n-cnte)*mine[i] + odd[i] + (n-cnto)*mino[i];
            cur_min = min(cur_min,cur);
        }
        cout<<cur_min<<nl;
    }
    return 0;
}
