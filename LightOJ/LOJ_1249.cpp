#include <bits/stdc++.h>
using namespace std;

// #ifdef IHAVETOPEE
// #include "debug.h"
// #else
// #define debug(args)
// #endif

// #pragma GCC target("avx2")
// #pragma GCC optimization("O3")
// #pragma GCC optimization("unroll-loops")

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
struct detum{
    string name;
    int x,y,z;
};
int main()
{
    // FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T, kas = 1;
    cin >> T;
    while (T--)
    {
        int n;
        cin>>n;
        struct detum arr[n + 1];
        fl(i,0,n){
            cin>>arr[i].name>>arr[i].x>>arr[i].y>>arr[i].z;
        }
        int min_vol = 1e8,mx_vol = 0;
        string min_name,mx_name;
        fl(i,0,n){
            int cur_v = arr[i].x * arr[i].y * arr[i].z;
            if(cur_v < min_vol){
                min_vol = cur_v;
                min_name = arr[i].name;
            }
            if(cur_v > mx_vol){
                mx_vol = cur_v;
                mx_name = arr[i].name;
            }
        }
        cout << "Case " << kas++ << ": ";
        if(min_vol == mx_vol){
            cout<<"no thief"<<nl;
        }else{
            cout<<mx_name<<" took chocolate from "<<min_name<<nl;
        }
    }
    return 0;
}
