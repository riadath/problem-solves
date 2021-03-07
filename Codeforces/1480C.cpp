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
    int n;
    cin>>n;
    int arr[n + 10];
    arr[0] = arr[n+1] = 1e7;
    int lo = 1,hi = n;
    while(lo < hi){
        int mid = (lo + hi)/2;
        int qm,qm1;
        
        if(mid == 0)qm = 1e7;
        else {
            cout<<"? "<<mid<<nl;
            cout.flush();
            cin>>qm;
        }
        if(mid + 1 == n+1)qm1 = 1e7;
        else {
            cout<<"? "<<mid + 1<<nl;
            cout.flush();
            cin>>qm1;
        }
        if(qm < qm1){
            hi = mid;
        }else{
            lo = mid + 1;
        }
    }
    cout<<"! "<<lo<<nl;
    return 0;
}
