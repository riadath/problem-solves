#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int numbers[70000];
int main()
{
    int p[6] = {2,3,5,7,13,17};
    int T,i,j = 0,num = 0,k;
    scanf("%d",&T);
    char arr[700000];
    scanf(" %[^\n]",arr);
    char *token = (char *)malloc(sizeof(char)*10);
    token = strtok(arr,",");
    while(token != NULL)
    {
        sscanf(token,"%d",&numbers[j]);
        j++;
        token = strtok(NULL,",");
    }
    int len = j;
    for(i = 0; i < len; i++)
    {
       // printf("Numbers[%d]:%d\n",i,numbers[i]);
        for(j = 0; j < 6; j++)
        {
            if(numbers[i] == p[j])
            {
                cout<<"Yes"<<"\n";
                break;
            }
        }
        if(j == 6)
            cout<<"No"<<endl;
    }
    return 0;
}












