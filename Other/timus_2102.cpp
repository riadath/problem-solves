#include <bits/stdc++.h>
using namespace std;

#ifdef IHAVETOPEE
#include "debug.h"
#else
#define debug(args...)
#endif

// #pragma GCC target("avx2")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
ll n;
#define SIZE 20000009
bool prime[SIZE];
void sieve(){
    prime[0] = 1,prime[1] = 1;
    for(int i = 4;i < SIZE;i += 2)prime[i] = 1;
    for(int i = 3;i * i <= SIZE;i += 2){
        for(int j = 2;i*j <= SIZE;j++){
            prime[i*j] = 1;
        }
    }
    // fl(i,0,50)if(!prime[i])cout<<i<<sp<<prime[i]<<nl;
}
int prime_power(ll n){
    int sum = 0;
    for(int i = 2;i <= n;i += 1){
        if(i >= SIZE)break;
        if(!prime[i] && n%i == 0){
            // debug(i);
            // debug(n);
            int cnt = 0;
            while(n%i == 0){
                cnt++,n /= i;
                // debug(n);
            }
            sum += cnt;
            // debug(sum);
            if(sum > 20)return 0;
        }
    }

    if(n > 1)sum += 1;
    // debug(sum);
    // debug(n);
    return (sum == 20);
}
int main()
{
    sieve();
    FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ll n;
    cin>>n;
    if(prime_power(n))cout<<"Yes"<<nl;
    else cout<<"No"<<nl;
    return 0;
}