#include <bits/stdc++.h>
using namespace std;

int fact[3000];
int multiply(int x, int fact_size)
{
    int carry = 0;
    for (int i = 0; i < fact_size; i++)
    {
        int product = fact[i] * x + carry;
        fact[i] = product % 10;
        carry = product / 10;
    }
    for (; carry != 0; fact_size++)
    {
        fact[fact_size] = carry % 10;
        carry /= 10;
    }
    return fact_size;
}
int factorial(int n)
{
    fact[0] = 1;
    int fact_size = 1;
    for (int i = 2; i <= n; i++)
    {
        fact_size = multiply(i, fact_size);
    }
    return fact_size;
}
int main()
{
    int n;
    while (scanf("%d", &n) == 1)
    {
        int fact_size = factorial(n);
        printf("%d!\n", n);
        for (int i = fact_size - 1; i >= 0; i--)
        {
            printf("%d", fact[i]);
        }
        printf("\n");
    }
    return 0;
}
