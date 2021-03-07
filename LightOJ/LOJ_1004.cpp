#include <bits/stdc++.h>
using namespace std;
int arr[200][200];
int mem[200][200];
int n;
int f(int p,int q)
{
    if (arr[p][q] == 0)
        return 0;

    if(mem[p][q] != -1){
        return mem[p][q];
    }
    int ret = 0;
    if(p < n/2)
    {
        ret = max(f(p+1,q),f(p+1,q+1)) + arr[p][q];
        mem[p][q] = ret;

    }
    else
    {
        ret = max(f(p+1,q-1),f(p+1,q)) + arr[p][q];
        mem[p][q] = ret;

    }

    return ret;

}

int main()
{
    int T;
    scanf("%d",&T);
    for(int k = 1; k <= T; k++)
    {
        scanf("%d",&n);
        for(int i = 0; i < 200; i++)
        {
            for(int j = 0; j < 200; j++)
            {
                mem[i][j] = -1;
                arr[i][j] = 0;
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < i+1; j++)
            {
                scanf("%d",&arr[i][j]);

            }
        }
        int l = n-1;
        for(int i = n; i < 2*n-1; i++)
        {
            for(int j = 0; j < l; j++)
            {
                scanf("%d",&arr[i][j]);
            }
            l--;
        }
        n = 2*n-1;
        /* for(int i = 0;i < n;i++){
             for(int j = 0;j< n;j++)cout<<arr[i][j]<<" ";
             cout<<endl;
         }*/
        int mx = f(0,0);
        printf("Case %d: %d\n",k,mx);
    }
    return 0;
}
