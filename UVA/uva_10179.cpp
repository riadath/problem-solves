#include <bits/stdc++.h>

using namespace std;

int phi(int n)
{
    double result = n;
    for(int i = 2; i*i <= n; ++i)
    {
        if(n%i==0)
        {
            while(n%i == 0)
                n /= i;
            result *= (1.0 - (1.0/(double)i));
        }
    }
    if(n > 1)
    {
        result *= (1.0-1.0/(double)n);
    }
    return (int)result;
}

int main()
{
    unsigned long long n;
    while(cin>>n && n)
    {
        unsigned long long frctn = phi(n);
        cout<<frctn<<"\n";
    }
    return 0;
}













