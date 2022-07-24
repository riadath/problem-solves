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
#define MEM(x, y) memset(x, y, sizeof(x))
#define PI acos(0)*2
#define fi first
#define se second
#define all(a) a.begin(), a.end()


int main()
{
    FIO;
    #ifdef IHAVETOPEE 
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    int T;cin>>T;
    while(T--){
        int n;cin>>n;
        if(n == 2){
            cout<<"2 1\n";
            continue;
        }
        cout<<1<<" ";
        for(int i = 3;i <= n;i++)cout<<i<<" ";
        if(n >= 2)cout<<2;
        cout<<"\n";
    }

    return 0;
}
