
#include <bits/stdc++.h>
using namespace std;

int main()
{
   // freopen("input_file.txt","r",stdin);
    //freopen("output_file.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for (int y = 1;y<=T;y++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        int ans = 0;
        if(a < b) ans = (b-a);
        else if(a > b && a%b != 0){
            int i = floor(a/b);
            ans  = b - (a - (i)*b);
        }
        else if(a%b == 0)ans = 0;
        printf("%d\n",ans);
    }
    return 0;
}













































