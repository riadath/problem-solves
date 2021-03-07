#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        bool if_mo = false,if_po = false;
        bool is_poss = true;
        int a[n],b[n];
        for(int i = 0;i < n;i++)cin>>a[i];
        for(int i = 0;i < n;i++)cin>>b[i];
        if(a[0] != b[0])is_poss = false;
        else{
            if(a[0] == 1)if_po = true;
            else if(a[0] == -1)if_mo = true;
            for(int i = 1;i < n;i++){
                if(a[i] == b[i]){
                    if(a[i] == 1)if_po = true;
                    else if(a[i]== -1)if_mo = true;
                    continue;
                }
                else if(b[i] > a[i] && !if_po)is_poss = false;
                else if(b[i] < a[i] && !if_mo)is_poss = false;

                if(a[i] == 1)if_po = true;
                else if(a[i]== -1)if_mo = true;

                if(!is_poss)break;
            }
        }
        if(is_poss)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    return 0;
}


















