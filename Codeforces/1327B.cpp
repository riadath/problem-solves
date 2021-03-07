#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        vector <int> d_list[n];
        bool is_married[n+1];
        bool d_married[n];

        memset(d_married,false,sizeof(d_married));
        memset(is_married,false,sizeof(is_married));

        for(int i = 0; i < n; i++)
        {
            int temp;
            cin>>temp;
            for(int j = 0; j< temp; j++)
            {
                int t;
                cin>>t;
                d_list[i].push_back(t);
            }
        }
        bool is_opt = true;
        int daughter,prince;
        for(int i = 0; i < n; i++)
        {
            int start,finish;
            if(d_list[i].size() != 0)
            {
                start = d_list[i][0];
                finish = d_list[i][d_list[i].size()-1];
                for(int j =start; j <= finish; j++)
                {
                    if(binary_search(d_list[i].begin(),d_list[i].end(),j) && !is_married[j])
                    {
                        is_married[j] = true;
                        d_married[i] = true;
                        break;
                    }
                }
            }
        }

        for(int i = 0; i < n; i++)
        {
            if(!d_married[i])
            {
                for(int j = 1; j <= n; j++)
                {
                    if(!is_married[j])
                    {
                        daughter = i;
                        prince = j;
                        is_opt = false;
                        break;
                    }
                }
            }
            if(!is_opt)
                break;
        }

        if(is_opt)
            cout<<"OPTIMAL"<<endl;
        else
        {
            cout<<"IMPROVE"<<endl;
            cout<<daughter+1<<" "<<prince<<endl;
        }

    }
    return 0;
}




















