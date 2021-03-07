//codejam 2 solved
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    for(int kase = 1; kase<=T; kase++)
    {
        string arr;
        cin>>arr;
        int n = arr.size();
        string str;
        int rem = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < (arr[i]-'0')-rem; j++)
                str.push_back('(');

            str.push_back(arr[i]);
            rem = arr[i]-'0';

            while(i+1 < n && arr[i+1] == arr[i])
            {
                str.push_back(arr[i+1]);
                i++;
            }


            if(i+1 < n && arr[i+1] < arr[i])
            {
                int temp = arr[i]-'0';
                i++;
                while((arr[i]-'0') < temp && arr[i]>='0' && arr[i]<='9')
                {
                    for(int l = 0; l < (rem-(arr[i]-'0')); l++)
                        str.push_back(')');
                    str.push_back(arr[i]);
                    rem = arr[i] - '0';
                    temp = arr[i] - '0';
                    i++;
                }
                i--;
            }
        }
        if(rem>0)
            for(int l = 0; l < rem; l++)
                str.push_back(')');
        cout<<"Case #"<<kase<<": "<<str<<endl;
    }
    return 0;
}







