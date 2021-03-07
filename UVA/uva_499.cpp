#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int i,j;
    char arr[100000];
    char arr_letters_up[27];
    char arr_letters_low[27];
    for(i = 1,j = 65; i <= 26; i++,j++)
    {
        arr_letters_up[i] = j;
        arr_letters_low[i] = j+32;
    }

    while(scanf(" %[^\n]",arr)==1)
    {
    	int arr_count_up[27];
		int arr_count_low[27];
		for(i = 0;i < 27;i++){
			arr_count_up[i] = 0;
			arr_count_low[i] = 0;
		}
        int len = strlen(arr);
        for(i = 0; i < len; i++)
        {
            for(j = 1; j <=26; j++)
            {
                if(arr[i] == arr_letters_up[j])
                {
                    arr_count_up[j] += 1;
                }
                if(arr[i] == arr_letters_low[j])
                {
                    arr_count_low[j] += 1;
                }
            }
        }
        int *max_up,*max_low;
        max_up = max_element(arr_count_up,arr_count_up+27);
        max_low = max_element(arr_count_low,arr_count_low+27);
        int maximum;
        if(*max_up > *max_low)
            maximum = *max_up;
        else
            maximum = *max_low;

        for(i = 1; i <= 26; i++)
        {
            if(arr_count_up[i] == maximum)
            {
                cout<<arr_letters_up[i];
            }
        }
		for(i = 1; i <= 26; i++)
        {
            if(arr_count_low[i] == maximum)
            {
                cout<<arr_letters_low[i];
            }
        }
        cout<<" "<<maximum<<"\n";
    }
    return 0;
}















