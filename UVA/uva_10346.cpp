#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int main()
{
    unsigned long long int n,k,p;
    while(scanf("%llu %llu",&n,&k)!=EOF)
    {
        if(k > 1)
        {
			p = n + (n-1)/(k-1);
            printf("%llu\n",p);
        }

    }
    return 0;
}
