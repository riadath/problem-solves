#include <bits/stdc++.h>
using namespace std;

#ifdef IHAVETOPEE
#include "debug.h"
#else
#define debug(args)
#endif
#define FIO ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);

int main()
{
    FIO;
    #ifdef IHAVETOPEE 
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    int t;cin>>t;
    while(t--){
        int n; 
        cin>>n;
        vector<int>arr(n);
        deque<int>brr;
        for(int i = 0;i < n;i++){
            cin>>arr[i];
        }
        brr.push_back(arr[0]);
        int last = arr[0];
        for(int i = 1;i < n;i++){
            if(arr[i] > last){
                brr.push_back(arr[i]);
            }else {
                brr.push_front(arr[i]);
                last = arr[i];
            }
        }
        for(auto i : brr){
            cout<<i<<" ";
        }cout<<"\n";
    }
    return 0;
}
