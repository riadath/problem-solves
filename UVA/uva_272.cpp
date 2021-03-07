#include <bits/stdc++.h>
using namespace std;
char arr_two[1000];
int main()
{
    char arr[1000];
    bool x = true;
    char c1[5] = "`'";
    while(gets(arr) && arr[0] != EOF){
        for(int i = 0,j = 0;i < strlen(arr);i++){
            if(arr[i] == '"' && x){
                arr_two[j] = c1[0],arr_two[j+1] = c1[0];
                j += 2;
                x = !x;
            }else if(arr[i] == '"' && !x){
                arr_two[j] = c1[1],arr_two[j+1] = c1[1];
                j += 2;
                x = !x;
            }else{
                arr_two[j] = arr[i];
                j++;
            }
        }
        cout<<arr_two<<endl;
        for(int i = 0;i < 1000;i++){
            arr_two[i] = '\0';
        }
    }
    return 0;
}











































































































