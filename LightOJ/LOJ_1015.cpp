#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    for(int k = 1;k <= T;k++){
        int n,sum = 0,temp;
        scanf("%d",&n);
        for(int i = 0;i < n;i++){
            scanf("%d",&temp);
            if(temp < 0)temp = 0;
            sum += temp;
        }
        printf("Case %d: %d\n",k,sum);
    }
    return 0;
}




