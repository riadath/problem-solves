#include <bits/stdc++.h>
using namespace std;
int n;
int bg[1001],en[1001];
bool is_p(string str)
{
    bool is_pos = true;
    for(int i = 0; i < n; i++)
    {

        int x = bg[i],y = en[i];
        for(int j = 0; j < n; j++)
        {
            if(j==i)
                continue;
            int p,q;
            p = bg[j],q = en[j];
            if(p<x&&q<=x || p>=y&&q>y)
            {
                continue;
            }
            else
            {
                if(str[i] == str[j])
                {
                    is_pos = false;
                }
                if(!is_pos)
                    break;
            }
        }
        if(!is_pos)
            break;
    }
    return is_pos;

}

int main()
{
    int T;
    cin>>T;
    for(int kase = 1; kase<=T; kase++)
    {
        cin>>n;
        for(int i = 0; i < n; i++)
        {
            cin>>bg[i]>>en[i];

        }
        string str;
        for(int i = 0; i < n; i++)
            str.push_back('C');
        for(int i = 0; i < n; i++)
        {
            char temp;
            if(str[i] == 'C')
                temp = 'J';
            else
                temp = 'C';
            int x = bg[i],y = en[i];
            for(int j = 0; j < n ; j++)
            {
                if(j==i)
                    continue;
                int p,q;
                p = bg[j],q = en[j];
                if(p<x&&q<=x || p>=y&&q>y)
                {
                    if(!is_p(str))
                        str[j] = temp;
                }
                else
                {

                    str[j] = temp;
                }
            }
        }
        if(is_p(str))
        {
            printf("Case #%d: ",kase,str);
            cout<<str;
        }
        else
        {
            printf("Case #%d: IMPOSSIBLE",kase);
        }
        if(kase != T)cout<<"\n";
    }
    return 0;
}






