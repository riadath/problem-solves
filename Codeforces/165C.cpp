#include <bits/stdc++.h>
using namespace std;

#ifdef IHAVETOPEE
#include "debug.h"
#else
#define debug(args)
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

int main()
{
    FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int k,len;
    string s;
    cin>>k>>s;
    len = (int)s.size();
    s += "####";
    int st = 0,en = len - 1;
    int oneS = 0;
    fl(i,0,len)if(s[i] - '0')oneS++;
    if(oneS < k){
        cout<<0<<nl;
        return 0;
    }else if(k == 0){
        ll tot = 0,zeroCnt = 0;
        for(int i = 0;i < len;i++){
            if(s[i] == '0'){
                int st1 = i;
                while(s[st1] == '0')zeroCnt++,st1++;
                tot += (zeroCnt * (zeroCnt + 1))/2;
                zeroCnt = 0;
                i = st1 - 1;
            }
        }
        cout<<tot<<nl;
        return 0;
    }
    ll zeroSt = 0,zeroEnd = 0,curOne = 0;

    while(s[st] == '0'){
        zeroSt++,st++;
    }
    for(int i = st;curOne < k;i++){
        if(s[i] == '1')curOne++,en = i;
    }
    for(int i = en+1;i < len && s[i] != '1';i++)zeroEnd++;
    ll total_cnt = 0;
    while(st < len && en < len){
        // debug(zeroSt);
        // debug(zeroEnd);
        // debug(st);debug(en);
        total_cnt += (zeroSt + 1) * (zeroEnd + 1);
        st++;
        zeroSt = 0,zeroEnd = 0;
        if(st < len)
        while(s[st] == '0'){
            zeroSt++,st++;
        }
        en++;
        if(en < len){
            while(s[en] == '0'){
                en++;
            }
            int zcn = en+1;
            while(s[zcn++] == '0')zeroEnd++;
        }
    }
    cout<<total_cnt<<nl;
    return 0;
}