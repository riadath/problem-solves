#include <bits/stdc++.h>
using namespace std;

#ifdef IHAVETOPEE
#include "debug.h"
#else
#define debug(args...)
#endif

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
ll num,n;
string str;
ll dp[40][3][3][40];
ll foo(int i,int flag,int prev,int value)
{
    if(i >= n)return value;
    ll &ret = dp[i][flag][prev][value];
    if(ret != -1)return ret;
    ll cur = str[i] - '0';
    ll a = 0,b = 0;
    b += foo(i + 1,0 < cur || flag,0,value);
    if(flag || (flag == 0 && cur == 1)){
        if(prev)a +=  foo(i + 1,1 < cur || flag,1,value + 1);
        else a += foo(i + 1,1 < cur || flag,1,value);
    }
    return ret = a + b;
}
int main()
{
    FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T, kas = 1;
    cin >> T;
    while (T--)
    {
        MEM(dp,-1);
        str = "";
        cin>>num;
        ll temp = num;
        while(temp != 0){
            str.pb('0' + (temp % 2));
            temp /= 2;
        }
        reverse(all(str));
        n = (ll)str.size();
        cout << "Case " << kas++ << ": ";
        cout<<foo(0,0,0,0)<<nl;
    }
    return 0;
}
