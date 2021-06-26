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
    int T;
    cin >> T;
    while (T--)
    {
        ll n,l,r;cin>>n>>l>>r;
        vector<ll>arr(n);
        fl(i,0,n)cin>>arr[i];
        vector<ll>brr;
        fl(i,0,n){
            if(arr[i] < r)brr.pb(arr[i]);
        }
        sort(all(brr));
        ll sum = 0;
        // debug(brr);
        n = brr.size();
        fl(i,0,n){

            int idx = -1;
            int lo = i + 1,hi = n - 1;
            // debug(lo);
            // debug(hi);
            while(lo <= hi){
                int mid = (lo + hi)/2;
                if(brr[mid] + brr[i] >= l){
                    idx = mid;
                    hi = mid - 1;
                }else{
                    lo = mid + 1;
                }
            }
            int idx2 = -1;
            lo = i + 1,hi = n-1;
            while(lo <= hi){
                int mid = (lo + hi)/2;
                if(brr[mid] + brr[i] <= r){
                    idx2 = mid;
                    lo = mid + 1;
                }else{
                    hi = mid - 1;
                }
            }
            // debug(idx);
            // debug(idx2);
            if(idx != -1 && idx2 != -1)
                sum += (idx2 - idx + 1);
        }
        cout<<sum<<nl;

    }
    return 0;
}
