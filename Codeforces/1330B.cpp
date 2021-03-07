///UNSOLVED


#include <bits/stdc++.h>
using namespace std;

int arr[200000];

bool is_per(int i,int j)
{
    int temp_arr[j-i+2];
    int k,l = 0;
    for(k = i,l = 0; k <= j; k++,l++)
    {
        temp_arr[l] = arr[k];
    }

    sort(temp_arr,temp_arr+l);
    int num_element = j-i+1;
    int mx = temp_arr[num_element-1];

    if(num_element != mx)
        return false;
    return true;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        for(int i=0; i < n; i++)
        {
            cin>>arr[i];
        }
        int possible_way = 0;
        int pos[n][2];
        for(int i = 0; i < n-1; i++)
        {
            if(is_per(0,i) && is_per(i+1,n-1))
            {
                pos[possible_way][0] = i+1;
                pos[possible_way][1] = n-i-1;
                possible_way++;
            }
        }
        cout<<possible_way<<endl;
        for(int i = 0; i < possible_way; i++)
        {
            cout<<pos[i][0]<<" "<<pos[i][1]<<endl;
        }

    }
    return 0;
}






