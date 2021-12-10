#include <bits/stdc++.h>
using namespace std;
#ifdef IHAVETOPEE
#include "debug.h"
#else
#define debug(args)
#endif
#define FIO ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);




#define size 2000009
#define ll long long


ll n,e,arr[200009];
vector<int>prime(size,1);
// ll dp[200009][3];


void sieve(){
    prime[0] = prime[1] = 0;
    for(int i = 2;i < size;i += 1){
        if(prime[i] && (long long)i*i < size)
            for(int j = i*i;j < size;j += i)prime[j] = 0;
    }
}



// ll f(int i,bool flag)
// {
//     debug(arr[i]);debug(flag);
//     if(i >= n){
//         return 0;
//     }
//     if(dp[i][flag] != -1)return dp[i][flag];
//     ll a = 0,b = 0;
//     if(!flag){
//         if(prime[arr[i]] && i + e < n){
//             b = 1 + f(i + e,prime[arr[i]]);
//         }
//         else if(arr[i] == 1 && i + e < n){
//             b = f(i + e,flag);
//         }
//     }
//     else{
//         // debug(i);debug(arr[i]);
//         if(arr[i] == 1 && i + e < n)b = 1 + f(i + e,flag);
//     }

//     if(!flag && i + e + 1 < n)
//         a = f(i + 1,flag);
//     // debug(a);debug(b);
//     return dp[i][flag] = (a + b);
// }

int main()
{
    FIO;
    #ifdef IHAVETOPEE   
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    sieve();

    int T;
    cin>>T;
    while(T--){

        // memset(dp,-1,sizeof(dp));
        cin>>n>>e;
        for(int i = 0;i < n;i++){
            cin>>arr[i];
        }

        ll total = 0;
        for(int i = 0;i < n;i++){
            if(prime[arr[i]]){
                ll k = 1;
                ll t1 = 0,t2 = 0;
                while(i - k*e >= 0){
                    if(arr[i-k*e] == 1)t1++;
                    else break;
                    k++;
                }
                k = 1;
                while(i + k*e < n){
                    if(arr[i+k*e] == 1)t2++;
                    else break;
                    k++;
                }
                if(t1 > 0 && t2 > 0)total += t1*t2;
                total += (t1+t2);
            }
        }
        cout << total <<"\n";

        // ll ans = f(0,0);
        // cout<<ans<<"\n";
    }

    return 0;
}


/*

2
0
4
0
5
0

*/