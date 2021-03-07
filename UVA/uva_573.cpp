
#include <stdio.h>

int main()
{
	int h,u,d,f;
    while(true)
    {
        scanf("%d %d %d %d",&h,&u,&d,&f);
        float temp = u,frc = u*f;
        if(h == 0)break;
        float climbed = 0;
        int days = 0;
        while(true)
        {
        	days++;
            climbed += temp;
            if(climbed > h)
            {
                break;
            }
            climbed -= d;
            if(climbed < 0)
            {
                break;
            }
            if(temp>0)temp = temp - (frc/100);
        }
        if(climbed < 0){
			printf("failure on day %d\n",days);
        }else{
			printf("success on day %d\n",days);
        }
    }
    return 0;
}
