#include <bits/stdc++.h>
using namespace std;

int fact[3000];
int multiply(int x, int fact_size)
{
    int carry = 0;
    for(int i = 0; i < fact_size; i++)
    {
        int product = fact[i] * x + carry;
        fact[i] = product%10;
        carry = product / 10;
    }
    for(; carry != 0; fact_size++)
    {
        fact[fact_size] = carry%10;
        carry /= 10;
    }
    return fact_size;
}
int factorial(int n)
{
    fact[0] = 1;
    int fact_size = 1;
    for(int i = 2; i <= n; i++)
    {
        fact_size = multiply(i,fact_size);
    }
    return fact_size;
}
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        int count_arr[10];
        for(int i = 0;i < 10;i++){
            count_arr[i] = 0;
        }
        int fact_size = factorial(n);
        for(int i = 0; i < fact_size; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                if(fact[i] == j)count_arr[j]++;

            }
        }
        cout<<n<<"!"<<" --"<<endl;
        for(int i = 0;i< 10;i++){
            printf("   (%d)",i);
            if(count_arr[i] > 99)cout<<"  ";
            else if(count_arr[i] > 9)cout<<"   ";
            else cout<<"    ";
            printf("%d",count_arr[i]);
            if(i == 4)printf("\n");
        }
        cout<<endl;
    }
    return 0;
}













