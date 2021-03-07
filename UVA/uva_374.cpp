#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int x;
int bigmod(long long int b,long long int p,int m)
{
    if(p == 0)
        return 1;
    if(!(p%2))
    {
        x = bigmod(b,p/2,m);
        x = (x*x)%m;
    }
    else
    {
        x = ((b%m)*bigmod(b,p-1,m))%m;
    }
    return x;
}
int main()
{
    long long int b,p,m;
    while(scanf("%lld %lld %lld",&b,&p,&m) == 3)
    {
        int rem = bigmod(b,p,m);
        cout<<rem<<endl;
        //cout<<endl;
    }
    return 0;
}

