#include <bits/stdc++.h>
using namespace std;
#define MAX 10001
bool arr[MAX];
void sieve()
{
    int i,j;

    for(i = 1;i < MAX;i++){
        arr[i] = true;
    }
    for(i = 4;i < MAX;i += 2){
        arr[i] = false;
    }
    for(i = 3;i*i <= MAX;i++){
        for(j = i*i;j < MAX;j += 2*i){
            arr[j] = false;
        }
    }
}

int main()
{
    int n,c;
    sieve();
    while(scanf("%d %d",&n,&c) == 2){
        printf("%d %d:",n,c);
        int i,size_arr = 1;
        int arr_store[200];
        for(i = 0;i <= n;i++){
            if(arr[i]){
                arr_store[size_arr++] = i;
            }
        }
        int start = 0,finish = 0;
        size_arr--;
        int rem;
        if(size_arr%2 == 0 && 2*c > size_arr){
            start = 1;
            finish = size_arr;
        }
        else if(size_arr%2 != 0 && 2*c-1 > size_arr){
            start = 1;
            finish = size_arr;
        }
        else if(size_arr%2 == 0){
            rem = size_arr - (2*c);
            start = (rem/2) + 1;
            finish = size_arr - (rem/2);
        }
        else{
            rem = size_arr - (2*c - 1);
            start = (rem/2) + 1;
            finish = size_arr - (rem/2);
        }
        for(i = start;i <= finish;i++){
            printf(" %d",arr_store[i]);
        }
        printf("\n\n");
    }
    return 0;
}





























