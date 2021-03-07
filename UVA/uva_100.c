
#include <stdio.h>
int main()
{
	long int n1,n2;
    while(scanf("%ld %ld",&n1,&n2)==2)
    {
        if(n1 > 0 && n1 < 1000000 && n2 > 0 && n2 < 1000000)
        {
        	long int c_len,i,j,max = 0,strt,end;
            if(n1 < n2)
            {
                strt = n1;
                end = n2;
            }
            else
            {
                strt = n2;
                end = n1;
            }
            for(i = strt; i <= end; i++)
            {
                for(j = i,c_len = 1; j != 1;)
                {
                    if(j%2 == 0)
                    {
                        j = j/2;
                    }
                    else
                    {
                        j = 3*j + 1;
                    }
                    c_len++;
                }
                if(c_len > max)
                {
                    max = c_len;
                }


            }
            printf("%ld %ld %ld\n",n1,n2,max);
        }
    }
    return 0;
}
