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


int n,m;
string avail;

struct BAPA{
    string s1,s2;
    int m = 0,mm = 0;
}arr[5000];


bool comp(const BAPA &a, const BAPA &b)
{
    if(a.mm == b.mm){
        return a.m > b.m;
    }
    return a.mm < b.mm;
}

int main()
{
    FIO;
    // freopen("in.txt", "r", stdin);
    // freopen ("out.txt", "w", stdout);
    cin>>n>>m;
    fl(i,0,m){
        cin>>arr[i].s1>>arr[i].s2;
    }   
    cin>>avail;

    // fl(i,0,m)cout<<"-->"<<arr[i].s1<<sp<<arr[i].s2<<sp<<arr[i].m<<sp<<arr[i].mm<<nl;

    fl(i,0,m){
        int mat = 0,mmat = 0;
        fl(j,0,n){
            if(avail[j] == '1' && arr[i].s1[j] == '1')mat++;
            else if(arr[i].s1[j] == '1' && avail[j] == '0')mmat++;
        }
        arr[i].m = mat,arr[i].mm = mmat;
    }
    sort(arr,arr+m,comp);
    // fl(i,0,m)cout<<arr[i].s1<<sp<<arr[i].s2<<sp<<arr[i].m<<sp<<arr[i].mm<<nl;
    bool tor_bap_kaj_korbe = 1;
    int chek[5000];
    MEM(chek,0);
    while(tor_bap_kaj_korbe){
        tor_bap_kaj_korbe = 0;
        fl(i,0,m){
            if(chek[i])continue;
            string t1 = arr[i].s1;
            string t2 = arr[i].s2;
            bool flag = 1;
            fl(j,0,n){
                if(avail[j] == '0' && t1[j] == '1'){
                    flag = 0;
                    break; 
                }
            }
            if(flag){
                chek[i] = 1;
                tor_bap_kaj_korbe = 1;
                fl(j,0,n){
                    if(t2[j] == '1')avail[j] = '1';
                }
            }
        }
    }
    cout<<avail<<nl;
    return 0;
}


/*

3 2
001 010
010 001
001

*/
/*
4 3
0010 1100
0010 1000
1110 1111
0010
*/

/*
4 2
0101 1010
0001 0100
0001
*/
/*
4 3
0010 1100
0010 1011
0001 0001
0010


up1 = 1110
up2 = 1111
up3 = 1111

*/