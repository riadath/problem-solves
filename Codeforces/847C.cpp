#include <bits/stdc++.h>
using namespace std;

#ifdef IHAVETOPEE
#include "debug.h"
#else
#define debug(args)
#endif

#define ll long long
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define lcm(a, b) a *b / __gcd(a, b)
#define fl(i, a, b) for (ll i = (int)a; i < (int)b; i++)
#define MEM(x, y) memset(x, y, sizeof(x))
#define PI acos(0)*2
#define fi first
#define se second
#define all(a) a.begin(), a.end()

bool comp(const pii &a, const pii &b){return a.fi < b.fi;}

int main()
{
    FIO;
    #ifdef IHAVETOPEE 
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ll n,k;cin>>n>>k;
    if(k > (n*(n-1)/2LL)){
        cout<<"Impossible\n";
        return 0;
    }
    ll t_k = 0,t_r = 0,stp = 0;
    for(ll i = 1;t_k <= k;i++){
        if(t_k + i > k){
            t_r = k - t_k;
            break;
        }
        t_k += i,stp++;
    }stp++;
    debug(t_k);debug(t_r);
    ll rbr = 0;
    string ans = "";
    fl(i,0,t_r){
        rbr++;
        ans += "(";
    }
    if(t_r)ans += "()";

    debug(rbr);debug(stp);debug(ans);
    int lt = stp - rbr;
    for(int i = 0;i < lt;i++){
        ans += "(",rbr++;
    }
    debug(ans);
    fl(i,0,rbr)ans += ")";
    fl(i,0,n - (t_r != 0) - rbr)ans += "()";
    cout <<ans<<"\n";
    return 0;
}