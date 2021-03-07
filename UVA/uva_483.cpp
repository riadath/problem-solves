#include <bits/stdc++.h>
using namespace std;
char arr[1000];
bool if_space = true;
void rev(char arr[],int len)
{
    for(int i = len-1; i>=0; i--)
    {
        cout<<arr[i];
    }
    if(if_space)cout<<" ";
}

int main()
{
    while(gets(arr) && arr[0] != EOF)
    {
        if_space = true;
        char temp[100];
        int i,j;
        for(i = 0,j = 0; i < strlen(arr);)
        {
            if(arr[i] != ' ')
            {
                temp[j] = arr[i];
               // cout<<endl<<"arr[i]: "<<arr[i]<<" temp[j]: "<<temp[j]<<"i: "<<i<<" j:"<<j<<endl;
                j++;
                i++;
            }
            else
            {
               // cout<<endl<<"-------------------called"<<endl;
                rev(temp,j);
                for(int p = 0; p < 100; p++)
                {
                    temp[p] = '\0';
                }
                j = 0;
                i++;
            }
        }
        if_space = false;
        rev(temp,j);
        cout<<endl;
        for(int i = 0; i < 1000; i++)
        {
            arr[i] = '\0';
        }
    }
    return 0;
}











































































































