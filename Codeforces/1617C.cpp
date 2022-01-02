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
        int n;
        cin>>n;
        vector<ll>arr(n);
        map<ll,int>cnt;
        vector<ll>conv,to_conv;
        fl(i,0,n){
            cin>>arr[i];
            if(arr[i] > n)conv.pb(arr[i]);
            cnt[arr[i]]++;
        }
        fl(i,1,n+1){
            if(cnt[i] > 1){
                fl(k,0,cnt[i]-1)conv.pb(i);
            }
            if(cnt[i] == 0)to_conv.pb(i);
        }
        sort(all(conv));sort(all(to_conv));
        debug(conv);debug(to_conv);
        bool flag = true;
        fl(i,0,conv.size()){
            ll tt = conv[i]/2 + 1;
            tt = (conv[i] - tt);
            debug(conv[i]);debug(to_conv[i]);debug(tt);
            if(to_conv[i] > tt){
                flag = false;
                break;
            }
        }
        if(flag)cout<<conv.size()<<"\n";
        else cout<<-1<<"\n";
        
    }
    return 0;
}
