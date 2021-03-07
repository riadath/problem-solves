#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("input_file.txt","r",stdin);
    //freopen("output_file.txt","w",stdout);
    int T;
    cin>>T;
    for(int kase = 1; kase<=T; kase++)
    {
        int n;
        cin>>n;
        int p[n],c[n];
        bool is = true;
        for(int i = 0; i < n; i++)
        {
            cin>>p[i]>>c[i];
        }
        for(int i = 0; i < n-1; i++)
        {
            if(p[i+1] < p[i] || c[i+1] < c[i])
            {
                is = false;
                break;
            }
        }
        if(p[0] < c[0])
            is = false;
        if(is)
        {
            for(int i = 1; i < n; i++)
            {
                int d1,d2;

                d1 = p[i] - p[i-1];
                d2 = c[i] - c[i-1];
                if(d2 > d1)
                {
                    is = false;
                    break;
                }
            }
        }
        if(is)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}






