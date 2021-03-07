#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,x;
        cin>>n>>x;
        vector <int> arr;
        for(int i = 0; i < n; i++)
        {
            int temp;
            cin>>temp;
            arr.push_back(temp);
        }
        sort(arr.begin(),arr.end());
        vector <int> missing;




        int mx = *max_element(arr.begin(),arr.end());
        for(int i = 1; i <= mx; i++)
        {
            if(!binary_search(arr.begin(),arr.end(),i))
            {
                missing.push_back(i);
            }
        }
        if(x>missing.size())
        {
            cout<<mx+(x-missing.size())<<endl;
        }
        else
        {
            if(binary_search(arr.begin(),arr.end(),missing[x-1]+1)){
            int i ;
            for(i = missing[x-1]+1;; i++)
            {
                if(!binary_search(arr.begin(),arr.end(),i))
                {
                    cout<<i-1<<endl;
                    break;
                }
            }
            }
            else{
                cout<<missing[x-1]<<endl;
            }

        }
    }
    return 0;
}







