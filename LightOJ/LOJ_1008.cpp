
#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long T;
    scanf("%lld",&T);
    for(long long k = 1; k <=T; k++)
    {
        long long t;
        scanf("%lld",&t);
        long long x;
        x = ceil(sqrt(t));
        long long finish = x*x;
        long long start = finish - (x*2 - 2);
        long long p,q;
        if(x%2 == 0)
        {
          if(t >= start && t <= (finish-x+1)){
            q = x;
            p = (t-start)+1;
          }
          else{
            p = x;
            q = (finish-t)+1;
          }
        }
        else
        {
            if(t >= start && t <= (finish-x+1)){
            p = x;
            q = (t-start)+1;
          }
          else{
            q = x;
            p = (finish-t)+1;
          }
        }
        printf("Case %lld: %lld %lld\n",k,p,q);

    }

    return 0;
}
