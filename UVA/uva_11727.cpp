#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    int kase = 1;
    while(T--)
    {
        int arr[5];
        for(int i = 0; i < 3; i++)
        {
            scanf("%d",&arr[i]);
        }
        sort(arr,arr+3);
        printf("Case %d: %d\n",kase,arr[1]);
        kase++;
    }
    return 0;
}







































































































