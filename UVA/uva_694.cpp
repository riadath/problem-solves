    #include<bits/stdc++.h>
using namespace std;
int main()
{

    long long int a,l;
    int kase = 1;
    while( scanf("%lld %lld",&a,&l) && a>0 && l>0)
    {
        long long int term = 0;
        if(a < 0 && l < 0)
            break;
        long long int temp = a;
        while(temp <= l)
        {
            if(temp%2 == 0)
            {
                temp = temp / 2;
                term++;
            }
            else
            {
                temp = 3*temp + 1;
                term++;
            }
            if(temp == 1)
            {
                term++;
                break;
            }
        }
        printf("Case %d: A = %lld, limit = %lld, number of terms = %lld\n",kase,a,l,term);
        kase++;

    }
    return 0;
}






