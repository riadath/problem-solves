#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int a,b,c,d,x,y,x1,x2,y1,y2;
        int v,h;
        bool is = true;
        cin>>a>>b>>c>>d>>x>>y>>x1>>y1>>x2>>y2;
        if((a>0 || b>0) && (x1-x2)==0)is = false;
        else if((c>0 || d>0) && (y1-y2)==0)is = false;
        else
        {
            if(a>b)
            {
                v = a-b;
                v = x-v;
            }
            else
            {
                v = b-a;
                v = x+v;
            }
            if(v < x1 || v > x2)
                is = false;
            if(c > d)
            {
                h = c-d;
                h = y-h;
            }
            else
            {
                h = d-c;
                h = y+h;
            }
            if(h < y1 || h > y2)
                is=false;
        }
        if(is)
        {
            cout<<"Yes"<<endl;

        }
        else
        {
            cout<<"No"<<endl;
        }
    }
    return 0;
}
