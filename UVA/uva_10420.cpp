#include <stdio.h>
#include <string.h>


int main()
{
	int i,j;
    char arr[2002][76];
    int count_arr[2002];
    int n;
    scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
        scanf(" %[^\n]",arr[i]);
    }
    char temp[2002][76];
    for(i = 0;i < n;i++){
		j = 0;
		while(arr[i][j] != ' '){
			temp[i][j] = arr[i][j];
			j++;
		}
    }
    char temp0[76];
	for(i = 0;i < n;i++){
		for(j = i;j < n;j++){
			if(strcmp(temp[i],temp[j]) > 0){
				strcpy(temp0,temp[i]);
				strcpy(temp[i],temp[j]);
				strcpy(temp[j],temp0);
			}
		}
	}
	char arr_new[2002][76];
	/*for(i = 0;i < n;i++){
		printf("temp[%d]: %s\n",i,temp[i]);
	}*/
	int len = 0;
	for(i = 0,j = 0;i < n;i = j){
		int counter = 0;
		while(strcmp(temp[i],temp[j]) == 0){
		    counter++;
		    j++;
		}
		strcpy(arr_new[len],temp[i]);
		count_arr[len] = counter;
		len++;
	}
	for(i = 0;i < len;i++){
		printf("%s %d\n",arr_new[i],count_arr[i]);
	}
    return 0;
}













