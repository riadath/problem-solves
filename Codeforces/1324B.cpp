#include <bits/stdc++.h>
using namespace std;

int main()
{

    int T;
    cin>>T;
    while(T--)
    {
       int n;
       cin>>n;
       int arr[n];
       for(int i = 0;i < n;i++)cin>>arr[i];
       bool is = false;
       for(int i = 0;i < n;i++){
        for(int j = i+2;j < n;j++){
            if(arr[j] == arr[i]){
                is = true;
                break;
            }
        }
        if(is)break;
       }
       if(is)cout<<"YES"<<endl;
       else cout<<"NO"<<endl;
    }
    return 0;
}











