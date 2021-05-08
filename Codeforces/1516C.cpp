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
int arr[200],n,sum;
bool dp[109][200009],flag[109][200009];
int f(int i,int s){
    if(i >= n){
        return (s == 0);
    }
    if(flag[i][s])return dp[i][s];
    bool a = 0,b = 0;
    if(s - arr[i] >= 0)
        a = f(i + 1,s - arr[i]);
    b = f(i + 1,s);
    dp[i][s] = (a | b);
    flag[i][s] = 1;
    return dp[i][s];
}
int main()
{
    FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    cin>>n;
    sum = 0;
    fl(i,0,n){
        cin>>arr[i];
        sum += arr[i];
    }
    if(sum%2){
        cout<<0<<nl;
        return 0;
    }
    sum /= 2;
    bool flagg = f(0,sum);

    if(!flagg){
        cout<<0<<nl;
        return 0;
    }
    ll gcd = arr[0];
    fl(i,1,n){
        gcd = __gcd((ll)arr[i],gcd);
    }
    fl(i,0,n)arr[i] /= gcd;
    int idx = -1;
    fl(i,0,n){
        if(arr[i]%2){
            idx = i + 1;
            break;
        }
    }
    cout<<1<<nl<<idx<<nl;
    return 0;
}
