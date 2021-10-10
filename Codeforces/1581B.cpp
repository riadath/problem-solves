#include <bits/stdc++.h>
using namespace std;

#ifdef IHAVETOPEE
#include "debug.h"
#else
#define debug(args)
#endif
#define FIO ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);

#define ll long long

int main()
{
    FIO;
    #ifdef IHAVETOPEE 
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    
    int T;cin>>T;
    while(T--){
        ll n,m,k;
        cin>>n>>m>>k;
        if(k == 2){
            if(n == 1 && m == 0)cout<<"YES\n";
            else cout<<"NO\n";
        }
        else if(k < 2 || m > (n*(n-1)/2) || m < n-1){
            cout<<"NO\n";
            continue;
        }
        else if(k <= 3){
            ll need = n*(n-1)/2;
            if(m < need)cout<<"NO\n";
            else cout<<"YES\n";
        }else{
            ll jk = k-2;
            ll need = (n+1) - (k-2);
            if(m < need)cout<<"NO\n";
            else cout << "YES\n";
        }
    }

    return 0;
}
