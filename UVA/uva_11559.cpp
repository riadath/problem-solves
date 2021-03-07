
#include <bits/stdc++.h>
using namespace std;

int minimum(int arr[],int n,int a)
{
    int l = INT_MAX;
    for(int i = 0;i < n;i++){
        if(arr[i] >= a){
            return 1;
        }
    }
    return 0;
}

int main()
{
    freopen("input_file.txt","r",stdin);
    //freopen("output_file.txt","w",stdout);
    int n,b,h,w;
    while(scanf("%d %d %d %d",&n,&b,&h,&w) == 4)
    {
        int hotel_cost[h],available[h][w];
        for(int i = 0;i < h;i++){
            cin>>hotel_cost[i];
            for(int j = 0;j < w;j++){
                cin>>available[i][j];
            }
        }
        int cost = INT_MAX,l;
        for(int i = 0;i < h;i++){
            l = minimum(available[i],w,n);
            if(l && n*hotel_cost[i]<=b)
                cost = min(cost,n*hotel_cost[i]);
            //cout<<"l:"<<l<<"cost:"<<cost<<endl;
        }
        if(cost != INT_MAX){
            cout<<cost<<endl;
        }else{
            cout<<"stay home"<<endl;
        }

    }
    return 0;
}













































