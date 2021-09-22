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
        int arr[n + 1],zero_cnt = 0;
        fl(i,1,n+1){
            cin>>arr[i];
            zero_cnt += !arr[i];
        }
        if(arr[n] == 0){
            fl(i,1,n+2)cout<<i<<sp;
            cout<<nl;
        }else
        {
            if(zero_cnt == 0){
                cout<<n+1<<sp;
                fl(i,1,n+1)cout<<i<<sp;
                cout<<nl;
            }else{
                fl(i,1,n){
                    if(arr[i] == 0 && arr[i + 1] == 1){
                        fl(j,1,i+1)cout<<j<<sp;
                        cout<<n+1<<sp;
                        fl(j,i+1,n+1)cout<<j<<sp;
                        cout<<nl;
                        break;
                    }
                }
            }
        }
        
    }
    return 0;
}
