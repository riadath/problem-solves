#include <bits/stdc++.h>
using namespace std;

#ifdef IHAVETOPEE
#include "debug.h"
#else
#define debug(args)
#endif
#define FIO ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);

int main()
{
    FIO;
    #ifdef IHAVETOPEE 
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    int T;cin>>T;
    while(T--){
        int n;
        cin>>n;
        string str;
        cin>>str;
        int zerop = -1;
        for(int i = 0;i < (int)str.size();i++){
            if(str[i] == '0'){
                zerop = i;
                break;
            }
        }
        if(zerop != -1){
            if(n - zerop >= n/2+1){
                printf("%d %d %d %d\n",zerop+1,n,zerop+2,n);
            }else{
                printf("%d %d %d %d\n",1,zerop+1,1,zerop);
            }
        }
        else{
            if(n%2){
                printf("%d %d %d %d\n",1,n-1,1,n/2);
            }else{
                printf("%d %d %d %d\n",1,n,1,n/2);
            }
        }
    }

    return 0;
}
