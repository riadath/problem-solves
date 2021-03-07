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
        int n,k;
        cin>>n>>k;
        vector<int>ans,temp1,temp2;
        int sum = 0;
        fl(i,1,k){
            sum += i;
            if(sum >= k)break;
            temp1.pb(i);
        }
        for(int i = k-1;i >= 1;i--){
            if(i + i - 1 > k)temp2.pb(i);
            else {
                temp2.pb(i);
                break;
            }
        }
        // debug(temp2);
        if(temp2.size() >= temp1.size()){
            fl(i,0,temp2.size())ans.pb(temp2[i]);
        }else fl(i,0,temp1.size())ans.pb(temp1[i]);
        fl(i,k+1,n+1)ans.pb(i);
        cout<<ans.size()<<nl;
        fl(i,0,ans.size())cout<<ans[i]<<" ";
        if(ans.size() != 0)cout<<nl;
    }
    return 0;
}
