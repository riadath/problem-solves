#include <bits/stdc++.h>
using namespace std;
int arr_one[500],arr_two[500],arr_sum[500];
int size_one,size_two,size_sum;
void multiply(int a,int n)
{
    for(int i = 0; i < 500; i++)
    {
        arr_one[i] = 0;
        arr_two[i] = 0;
        arr_sum[i] = 0;
        size_one = 0,size_two = 0,size_sum = 0;
    }
    int carry = 0;
    for(int l = 2; l <= n; l++)
    {
        int p = a;
        while(p != 0)
        {
            arr_two[size_two++] = p%10;
            p = p/10;
        }
        for(int i = 0; i < l-1; i++)
        {
            size_one = 0;
            for(int j = 0; j < size_two; j++)
            {
                int temp = arr_two[j]*a + carry;
                carry = temp/10;
                arr_one[size_one] = temp%10;
                size_one++;
            }

            while(carry != 0)
            {
                arr_one[size_one] = carry%10;
                carry = carry/10;
                size_one++;
            }
            for(int k = 0; k < size_one; k++)
            {
                arr_two[k] = arr_one[k];

            }
            size_two = size_one;
        }
        for(int i = 0; i < size_one; i++)
            arr_two[i] = 0;
        size_two = 0;
        carry = 0;
        for(int i = 0; i < size_one; i++)
        {
            int temp = l * arr_one[i] + carry;
            arr_two[size_two++] = temp%10;
            carry = temp/10;
        }
        while(carry != 0)
        {
            arr_two[size_two++] = carry%10;
            carry /= 10;
        }
        size_sum = 0;
        for(int i = 0; i < size_two; i++)
        {
            int temp = arr_sum[i] + arr_two[i] + carry;
            arr_sum[size_sum++] = temp%10;
            carry = temp/10;
        }
        while(carry != 0)
        {
            arr_sum[size_sum++] = carry%10;
            carry /= 10;
        }
        size_one = 0,size_two Z 0;
        for(int i = 0; i < size_two+200; i++)
            arr_two[i] = 0;

    }
    int p = a;
    while(p != 0)
    {
        arr_two[size_two++] = p%10;
        p = p/10;
    }

    int s = size_sum;
    size_sum = 0;
    for(int i = 0; i < s; i++)
    {
        int temp = arr_sum[i] + arr_two[i] + carry;
        arr_sum[size_sum++] = temp%10;
        carry = temp/10;
    }
    while(carry != 0)
    {
        arr_sum[size_sum++] = carry%10;
        carry /= 10;
    }
}

int main()
{
    int a,n,i;
    while(scanf("%d %d",&n,&a) && n)
    {
        multiply(a,n);
        for(i = size_sum-1; i >= 0; i--)
        {
            printf("%d",arr_sum[i]);
        }
        printf("\n");
    }
    return 0;
}

