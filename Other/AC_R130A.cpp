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
    int n;cin>>n;
    string s;cin>>s;
    long long total = 0;
    for(int i = 0;i < n-1;i++){
        if(s[i] == s[i + 1]){
            long long ct = 0;
            if(s[i] == s[i + 1]){
                while(s[i] == s[i + 1]){
                    ct++;
                    i++;
                    if(i >= n || s[i] != s[i + 1]){
                        ct++;
                        break;
                    }
                }
            }
            debug(ct);
            if(ct > 0)
                total += ((ct) * (ct - 1))/2;
        }
    }

    cout<<total<<"\n";
    return 0;
}
