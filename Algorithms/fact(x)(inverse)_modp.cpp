#include <bits/stdc++.h>
using namespace std;

#ifdef IHAVETOPEE
#include "debug.h"
#else
#define debug(args)
#endif
#define FIO ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);

#define ll long long

ll mod = 1e9 + 7,pow2[200009],inverse[200009],invfact[200009];
int main()
{
    FIO;
    #ifdef IHAVETOPEE 
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    

    /*
        calculate (x!)^-1 (mod p)
    */

    inverse[1] = 1;
    for (int i = 2; i <= 2e5;i++)
        inverse[i] = (mod - ((mod/i)*inverse[mod%i])%mod)%mod;
    invfact[1] = inverse[1];
    for(int i = 2;i <= 2e5;i++)
        invfact[i] = (invfact[i-1] * inverse[i])%mod;


    debug(inverse[5]);
    debug(invfact[5]);

    return 0;
}
