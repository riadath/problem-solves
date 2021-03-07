#include <bits/stdc++.h>
using namespace std;
int countDistinct(int arr[], int n)
{
    unordered_set<int> s;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        //cout<<*s.end()<<endl;
        if (s.find(arr[i]) == s.end())
        {
            s.insert(arr[i]);
            res++;
        }
    }

    return res;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int c = countDistinct(arr,n);
        cout<<c<<endl;
    }
    return 0;
}

