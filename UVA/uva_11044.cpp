
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
      int n,m;
      scanf("%d %d",&n,&m);
      int counter = floor(n/3) * floor(m/3);
      printf("%d\n",counter);
    }
    return 0;
}
