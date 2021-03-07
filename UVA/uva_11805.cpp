#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    for(int i = 0;i < T;i++)
    {
        int n,k,p;
        scanf("%d %d %d",&n,&k,&p);
        if((k+p)%n == 0){
            printf("Case %d: %d\n",i+1,n);
        }
        else{
            printf("Case %d: %d\n",i+1,(k+p)%n);
        }
    }
    return 0;
}
