#include <bits/stdc++.h>
using namespace std;

int main()
{
    double a,b,c;
    while(scanf("%lf %lf %lf",&a,&b,&c)!= EOF)
    {
        double s = (a+b+c)/2.0;
        double ans = sqrt((s-a)*(s-b)*(s-c)/s);
        if(a == 0 && b == 0 && c == 0)ans = 0;
        printf("The radius of the round table is: %0.03lf\n",ans);
    }
    return 0;
}














































