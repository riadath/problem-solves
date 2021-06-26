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
        int n;cin>>n;
        vector<ll>arr(n);
        ll mn = 1e18,mni = -1;
        fl(i,0,n){
            cin>>arr[i];
            if(arr[i] < mn){
                mn = arr[i];
                mni = i;
            }
        }
        cout<<n-1<<nl;
        ll st = 1;
        lf(i,mni-1,0){
            cout<<i+1<<sp<<mni + 1<<sp<<mn + st++ <<sp << mn<<nl;
            arr[i] = mn + st - 1;
        }
        while(__gcd(mn,mn + st) != 1)st++;
        fl(i,mni + 1,n){
            cout<<i+1<<sp<<mni + 1<<sp<<mn + st++ <<sp << mn<<nl;
            arr[i] = mni + st - 1;
        }
        debug(arr);

    }
    return 0;
}
