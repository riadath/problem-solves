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
        vector<int>arr(n);
        int mn = 1000000,mni = 0,mx = 0,mxi = 0;
        fl(i,0,n){
            cin>>arr[i];
            if(arr[i] < mn){
                mn = arr[i],mni = i;
            }
            if(arr[i] > mx){
                mx = arr[i];
                mxi = i;
            }
        }
        int asn = 1000000;
        if(mni > mxi)swap(mni,mxi);
        mni++,mxi++;
        asn = mni + n - mxi + 1;
        asn = min(asn,(mni + mxi - mni));
        asn = min(asn,n - mxi + 1 + (mxi - mni));
        cout<<asn<<nl;
    }
    return 0;
}
