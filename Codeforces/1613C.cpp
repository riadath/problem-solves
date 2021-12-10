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

ll n,h,arr[109];

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
        cin>>n>>h;
        fl(i,0,n)cin>>arr[i];       
        ll cur_mx = 0,mx_dist = 0;
        fl(i,0,n-1){
            mx_dist = max(mx_dist,(arr[i + 1]-arr[i] + 1));
        } 
       
        ll total = (arr[n-1]+mx_dist) - arr[0] ;
        //  debug(mx_dist);debug(total);
        if(total <= h){
            cout<<mx_dist + (h - total)<<"\n";
        }
        else{
            ll nt = 0;
            ll avg = h/n + (h%n != 0);
            int pp = 0;
            while(true){
                nt = 0;
                debug(avg);
                fl(i,0,n-1){
                    if(arr[i] + avg >= arr[i + 1]){
                        nt += (arr[i+1]-arr[i]);
                    }else nt += avg;
                }
                nt += (avg);
                if(nt >= h)break;
                else{
                    avg += (h - nt)/n + ((h-nt)%n != 0);
                }
                debug(nt);
            }
            cout<<avg<<"\n";
        }


    }
    return 0;
}
