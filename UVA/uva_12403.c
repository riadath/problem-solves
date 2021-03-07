#include <stdio.h>
int main()
{
    int T,acnt = 0;
    scanf("%d",&T);
    while(T--){
		int donation;
		char command[8];
		scanf("%s",command);
		if(command[0] == 'd'){
			scanf("%d",&donation);
			acnt += donation;
		}else if(command[0] == 'r'){
			printf("%d\n",acnt);
		}else{
			break;
		}
    }
    return 0;
}















