#include <bits/stdc++.h>
using namespace std;

int bs(int arr[],int n,int item)
{
    int start = 0,finish = n-1;
    int mid;
    int index = -1;
    while(start <= finish)
    {
        mid = (start+finish)/2;
        if( item == arr[mid] && mid > 0 && item == arr[mid-1] ){
            while( arr[mid] == item ){
                mid--;
            }
            return mid+1;
        }
        else if(item < arr[mid])
            finish = mid-1;
        else if(item > arr[mid])
            start = mid+1;
        else return mid;
    }
    return -1;
}

int main()
{
    int a,b;
    int kase = 1;
    while(cin>>a>>b && a && b)
    {
        int arr[a];
        for(int i = 0; i < a; i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+a);
       // cout<<"------------------------"<<bs(arr,a,5)+1<<endl;
        int item[b];
        for(int i = 0;i < b;i++){
            scanf("%d",&item[i]);
        }
        cout<<"CASE# "<<kase<<":\n";
        kase++;
        for(int i = 0; i < b; i++)
        {
            int pos = bs(arr,a,item[i]);
            if(pos == -1)
                cout<<item[i]<<" not found"<<endl;
            else
                cout<<item[i]<<" found at "<<pos+1<<endl;
        }
    }
    return 0;
}

























