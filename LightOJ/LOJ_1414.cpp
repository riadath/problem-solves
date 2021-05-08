#include <bits/stdc++.h>
using namespace std;

#ifdef IHAVETOPEE
#include "debug.h"
#else
#define debug(args)
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

bool if_leap(ll num){
    if(num%400 == 0)return true;
    if(num%100 == 0)return false;
    if(num%4 == 0)return true;
    return false;
}

int main()
{
    // FIO;
    map<string,int>montInt;
    montInt["January"]=1;
    montInt["February"]=2;
    montInt["March"]=3;
    montInt["April"]=4;
    montInt["May"]=5;
    montInt["June"]=6;
    montInt["July"]=7;
    montInt["August"]=8;
    montInt["September"]=9;
    montInt["October"]=10;
    montInt["November"]=11;
    montInt["December"]=12;

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T, kas = 1;
    cin >> T;
    while (T--)
    {
        string sm,em;
        ll etY,stY,ds,de;
        char garb;
        cin>>sm>>ds>>garb>>stY;
        cin>>em>>de>>garb>>etY;
        ll cnt = 0;

        if(montInt[sm] > 2)stY++;
        if(montInt[em] < 2 || (montInt[em] == 2 && de < 29))etY--;
        --stY;
        ll div4 = (etY/4) - (stY/4);
        ll div400 = (etY/400) - (stY/400);
        ll div100 = (etY/100) - (stY/100);
        cnt += div4 - div100 + div400;
        debug(div4);debug(div100);debug(div400);
        cout << "Case " << kas++ << ": ";
        
        cout<<cnt <<nl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#ifdef IHAVETOPEE
#include "debug.h"
#else
#define debug(args)
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

bool if_leap(ll num){
    if(num%400 == 0)return true;
    if(num%100 == 0)return false;
    if(num%4 == 0)return true;
    return false;
}

int main()
{
    // FIO;
    map<string,int>montInt;
    montInt["January"]=1;
    montInt["February"]=2;
    montInt["March"]=3;
    montInt["April"]=4;
    montInt["May"]=5;
    montInt["June"]=6;
    montInt["July"]=7;
    montInt["August"]=8;
    montInt["September"]=9;
    montInt["October"]=10;
    montInt["November"]=11;
    montInt["December"]=12;

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T, kas = 1;
    cin >> T;
    while (T--)
    {
        string sm,em;
        ll etY,stY,ds,de;
        char garb;
        cin>>sm>>ds>>garb>>stY;
        cin>>em>>de>>garb>>etY;
        ll cnt = 0;

        if(montInt[sm] > 2)stY++;
        if(montInt[em] < 2 || (montInt[em] == 2 && de < 29))etY--;
        --stY;
        ll div4 = (etY/4) - (stY/4);
        ll div400 = (etY/400) - (stY/400);
        ll div100 = (etY/100) - (stY/100);
        cnt += div4 - div100 + div400;
        debug(div4);debug(div100);debug(div400);
        cout << "Case " << kas++ << ": ";
        
        cout<<cnt <<nl;
    }
    return 0;
}
