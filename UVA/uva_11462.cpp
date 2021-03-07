#include <bits/stdc++.h>
using namespace std;

void counting_sort(int temp[],int arr[],int n)
{
    for(int i = 0; i <= 100; i++)
    {
        temp[i] = 0;
    }
    for(int i = 0; i < n; i++)
    {
        temp[arr[i]]++;
    }

}

int main()
{
    int n;
    while(scanf("%d",&n) && n)
    {
        int arr[n];
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&arr[i]);
        }
        int temp[101];
        counting_sort(temp,arr,n);
        for( int i = 1; i <= 100; i++ )
        {
            for( int j = 0; j < temp[i]; j++ )
            {
                printf("%d",i);
                n--;
                if(n!= 0)
                    printf(" ");

            }
        }
        printf("\n");
    }
    return 0;
}



















































































































