#include <bits/stdc++.h>
using namespace std;
int counter[10001];
int size_arr = 1000;
int num_of_div(int n)
{
    int counter = 0;
    for(int i = 2; i <= n/2; i++)
    {
        if(n%i == 0)
            counter++;
    }
    if(n == 1) return 1;
    else return counter+2;
}

int main()
{

    for(int i = 1; i <= size_arr; i++)
    {
        counter[i] = num_of_div(i);
    }
    int sort_arr[10001];
    for(int i = 1; i <= size_arr; i++)
    {
        sort_arr[i] = i;
    }
    int isSorted,temp;
    for(int i = 1; i <= size_arr; i++)
    {
        isSorted = 1;
        for(int j = 1; j <= size_arr; j++)
        {
            if(counter[j] > counter[j+1])
            {
                temp = sort_arr[j+1];
                sort_arr[j+1] = sort_arr[j];
                sort_arr[j] = temp;
                temp = counter[j+1];
                counter[j+1] = counter[j];
                counter[j] = temp;
                isSorted = 0;
            }
            else if(counter[j] == counter[j+1]){
                if(sort_arr[j] < sort_arr[j+1]){
                    temp = sort_arr[j+1];
                    sort_arr[j+1] = sort_arr[j];
                    sort_arr[j] = temp;
                    temp = counter[j+1];
                    counter[j+1] = counter[j];
                    counter[j] = temp;
                    isSorted = 0;
                }
            }
        }
        if(isSorted)
            break;
    }
    int T;
    scanf("%d",&T);
    int cs = 1;
    while(T--){

        int n;
        scanf("%d",&n);
        printf("Case %d: %d\n",cs,sort_arr[n+1]);
        cs++;
    }
    return 0;
}





























