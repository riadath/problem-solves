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

    int T;
    cin>>T;
    while(T--){
        long long n,num1 = 0,num2 = 0,m1 = 1,m2 = 1,ans = 0;
        string str;
        cin>>n;
        while(n > 0){
            int p = n%10;
            n /= 10;
            str.push_back('0' + p);
        }
        
        for(int i = 0;i < (int)str.size();i++){
            if(i%2){
                num1 += (str[i] - '0') * m1;
                m1 *= 10;
            }else{
                num2 += (str[i] - '0') * m2;
                m2 *= 10;
            }
        }
        ans = (num1 + 1) * (num2 + 1) - 2LL;
        cout<<ans<<"\n";
    }

    return 0;
}
