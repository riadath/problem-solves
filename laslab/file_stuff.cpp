#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book{
    int id,year;
    char title[100],genre[100],author[100];
}bInf[1009];

int strLen(char str[])
{
    int len = 0;
    for (int i = 0; str[i] != 0; i++)
        len++;
    return len;
}
int strCmp(char str1[], char str2[])
{
    int len1 = strLen(str1), len2 = strLen(str2);
    for (int i = 0; str1[i] != 0 && str2[i] != 0; i++)
    {
        if(str1[i] != str2[i])return false;
    }
    return (len1 == len2);
}

void bubbleSrot(int n){
    for(int i = 0;i < n-1;i++){
        for(int j = 0;j < n-1-i;j++){
            if(bInf[j].id > bInf[j+1].id){
                struct book tt = bInf[j];
                bInf[j] = bInf[j + 1];
                bInf[j + 1] = tt;
            }
        }
    }
}
int main()
{
    FILE *inPtr = fopen("in.txt","r");
    if(inPtr == NULL){
        printf("Could not open in.txt\n");
        return 0;
    }

    FILE *outPtr = fopen("out.txt","w");
    if(outPtr == NULL){
        printf("Could not open out.txt\n");
        return 0;
    }

    char currentLine[300];

    int n,q;
    fgets(currentLine,200,inPtr);
    sscanf(currentLine,"%d",&n);

    for(int i = 0;i < n;i++){
        fgets(currentLine,200,inPtr);
        sscanf(currentLine,"%d %s %s %s %d",&bInf[i].id,
        bInf[i].title,bInf[i].genre,bInf[i].author,&bInf[i].year);
    }

    //sorting
    bubbleSrot(n);

    fgets(currentLine,20,inPtr);
    sscanf(currentLine,"%d",&q);

    while(q--){
        int cmd;
        char temp[100];
        fgets(currentLine,20,inPtr);
        sscanf(currentLine,"%d %s",&cmd,temp);
        if(cmd == 1){
            for(int i = 0;i < n;i++){
                if(strCmp(temp,bInf[i].genre)){
                    fprintf(outPtr,"%d %s %s %s %d\n",bInf[i].id,
                    bInf[i].title,bInf[i].genre,bInf[i].author,bInf[i].year);
                }
            }
        }
        else{
            int year;
            sscanf(temp,"%d",&year);
            for(int i = 0;i < n;i++){
                if(year == bInf[i].year){
                    fprintf(outPtr,"%d %s %s %s %d\n",bInf[i].id,
                    bInf[i].title,bInf[i].genre,bInf[i].author,bInf[i].year);
                }
            }
        }
    }

    fclose(inPtr);
    fclose(outPtr);

    return 0;
}