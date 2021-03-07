#include <bits/stdc++.h>
using namespace std;

#define arr_size 1000008
int prime_ara[arr_size], arr[80000], n_primes;

void prime_store()
{
    int i, j;
    prime_ara[0] = 0;
    prime_ara[1] = 0;
    for (i = 0; i < arr_size; i++)
    {
        prime_ara[i] = 1;
    }
    for (i = 2; i * i <= arr_size; i++)
    {
        for (j = 2; i * j <= arr_size; j++)
        {
            prime_ara[i * j] = 0;
        }
    }

    for (i = 2, j = 0; i < arr_size; i++)
    {
        if (prime_ara[i])
        {
            arr[j] = i;
            j++;
        }
    }
    n_primes = j;
}
int main()
{
    int i, j, n;
    bool flag = false;
    prime_store();
    printf("Enter a positve Integer : ");
    scanf("%d", &n);
    for (int k = 0; k <= n_primes; k++)
    {
        i = arr[k];
        if (k == n_primes && !flag)
        {
            printf("This integer cannot be represented as the sum of two primes.\n");
            break;
        }

        for (int l = k; l <= n_primes && arr[l] + arr[k] <= n; l++)
        {
            j = arr[l];
            if ((i + j) == n)
            {
                printf("%d = %d + %d\n", n, i, j);
                flag = true;
            }
        }
    }

    return 0;
}
