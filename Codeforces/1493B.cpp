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
int h,m;
string ss;
map<int,int>reflecc;
int chekk(string hr,string minu)
{
    string hrr,minuu;
    hrr = hr,minuu = minu;
    // cout<<"=>"<<hrr<<":"<<minuu<<nl;
    if(reflecc[hr[0] - '0'] == -1 || reflecc[hr[1] - '0'] == -1)return false;
    if(reflecc[minu[0] - '0'] == -1 || reflecc[minu[1] - '0'] == -1)return false;
    hrr[0] = '0' + reflecc[minu[1] - '0'],hrr[1] = '0' + reflecc[minu[0] - '0'];
    minuu[0] = '0' + reflecc[hr[1] - '0'],minuu[1] = '0' + reflecc[hr[0] - '0'];
    // cout<<"=>"<<hrr<<":"<<minuu<<nl;
    int hcnt = (hrr[0] - '0') * 10 + (hrr[1] - '0');
    int mcnt = (minuu[0] - '0')*10 + (minuu[1] - '0');
    // cout<<"=>"<<hcnt<<sp<<mcnt<<nl;
    if(hcnt < h && mcnt < m)return true;
    return false;
}
int main()
{
    FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T;
    cin>>T;
    while(T--){
        reflecc[0] = 0,reflecc[1] = 1,reflecc[2] = 5,reflecc[3] = -1,reflecc[4] = -1;
        reflecc[5] = 2,reflecc[6] = -1,reflecc[7] = -1,reflecc[8] = 8,reflecc[9] = -1;
        cin>>h>>m;
        cin>>ss;
        // debug(ss);
        string hr,minu;
        hr.pb(ss[0]),hr.pb(ss[1]);
        minu.pb(ss[3]),minu.pb(ss[4]);
        // cout<<"is true : "<<chekk(hr,minu)<<nl;
        while(true)
        {
            if(chekk(hr,minu))break;
            // cout<<hr<<":"<<minu<<nl;
            int hcnt = (hr[0] - '0') * 10 + (hr[1] - '0');
            int mcnt = (minu[0] - '0')*10 + (minu[1] - '0');
            hcnt = (hcnt + 1) % h;
            mcnt = (mcnt + 1) % m;

            minu[1] = '0' + mcnt%10;
            mcnt /= 10;
            minu[0] = '0' + mcnt%10;

            if(minu == "00"){
                hr[1] = '0' + hcnt%10;
                hcnt /= 10;
                hr[0] = '0' + hcnt%10;
            }
            
        }
        // cout<<"--------->"<<nl;
        cout<<hr<<":"<<minu<<nl;
    }
    return 0;
}