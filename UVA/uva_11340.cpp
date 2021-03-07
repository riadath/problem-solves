#include <bits/stdc++.h>
using namespace std;
int amount[1000],temp[1000],size_arr,size_two;
char arr_count[101][1000],arr_char[101];
void add(int s)
{
    for(int i = 0,j = s - 1; i < s/2; i++,j--)
    {
        int y = temp[i];
        temp[i] = temp[j];
        temp[j] = y;
    }
    /* for(int i = s-1;i >=0;i--){
          cout<<temp[i];
      }
      cout<<endl;*/
    int carry = 0;
    if(s >= size_arr)
        size_two = s;
    else if(s < size_arr)
        size_two = size_arr;
    size_arr = 0;
    for(int i = 0; i < size_two; i++)
    {
        int x = amount[i] + temp[i] + carry;
        amount[size_arr++] = x%10;
        carry = x/10;
    }
    while(carry != 0)
    {
        amount[size_arr++] = carry%10;
        carry /= 10;
    }
    /*cout<<"amount:";
    for(int i = size_arr-1;i >= 0;i--){
        cout<<amount[i];
    }
    cout<<endl;*/
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        size_arr = 0,size_two = 0;
        for(int i  = 0; i < 1000; i++)
            amount[i] = 0;

        int N,i,j,k;
        scanf("%d",&N);
        for(i = 0; i < N; i++)
        {
            cin>>arr_char[i]>>arr_count[i];
        }
        int M;
        scanf("%d",&M);
        char arr[M][10001];
        for(j = 0; j < M; j++)
        {
            scanf(" %[^\n]",arr[j]);
        }
        for(i = 0; i < M; i++)
        {
            for(j = 0; j < strlen(arr[i]); j++)
            {
                for(k = 0; k < N; k++)
                {
                    if(arr_char[k] == arr[i][j])
                    {
                        int len = strlen(arr_count[k]);
                        for(int g = 0; g < 1000; g++)
                            temp[g] = 0;
                        for(int h = 0; h < len; h++)
                        {
                            temp[h] = arr_count[k][h] - '0';
                        }
                        add(len);
                    }
                }
            }
        }
        for(int i = size_arr-1; i > 1; i--)
        {
            printf("%d",amount[i]);
        }
        printf(".");
        for(int i = 1; i >=0; i--)
        {
            printf("%d",amount[i]);
        }
        printf("$\n");

    }
    return 0;
}
















