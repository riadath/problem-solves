#include <bits/stdc++.h>
using namespace std;

int check(int power[],bool switch_arr[],int n)
{
    int total = 0;
    for(int i = 1; i <= n; i++)
    {
        if(switch_arr[i])
        {
            total += power[i];
        }
    }
    return total;
}

int main()
{
    int n,m,c,seq = 1;
    while(cin>>n>>m>>c && n && m && c)
    {
        int device_power[n+1];
        for(int i = 1; i <= n; i++)
        {
            cin>>device_power[i];
        }
        int operations[m];
        for(int i = 0; i < m; i++)
        {
            cin>>operations[i];
        }
        bool switch_arr[n+1];
        for(int i = 1; i <= n; i++)
        {
            switch_arr[i] = false;
        }
        int max_current = 0;
        bool is_blown = true;
        printf("Sequence %d\n",seq);
        seq++;
        for(int i = 0; i < m; i++)
        {
            switch_arr[operations[i]] = !switch_arr[operations[i]];
            int total_current = check(device_power,switch_arr,n);
            if(total_current > c)
            {
                printf("Fuse was blown.\n");
                is_blown = false;
                break;
            }
            else if(total_current >= max_current)
                max_current = total_current;
        }
        if(is_blown)
        {
            printf("Fuse was not blown.\n");
            printf("Maximal power consumption was %d amperes.\n",max_current);
        }
        printf("\n");
    }
    return 0;
}













