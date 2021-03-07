#include <bits/stdc++.h>
using namespace std;
int mx_cost,num_items,num_people;
int dp[1010][1010];
int price[1010];
int weight[1010];
int mx_wt[101];
int f(int i,int cost)
{
    if(i >= num_items)
    {
        return 0;
    }

    if(dp[i][cost] != -1)
        return dp[i][cost];

    int a = 0,b = 0;
    if(cost+weight[i]<=mx_cost)
        a = price[i] + f(i+1,cost+weight[i]);
    b = f(i+1,cost);

    dp[i][cost] = max(a,b);
    return dp[i][cost];
}
int main()
{

    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&num_items);
        for(int i = 0; i < num_items; i++)
        {
           scanf("%d %d",&price[i],&weight[i]);
        }

        cin>>num_people;
        int ans = 0;

        for(int i = 0; i < num_people; i++)
        {
            memset(dp,-1,sizeof(dp));
            scanf("%d",&mx_cost);
            ans += f(0,0);
        }

        printf("%d\n",ans);
    }
    return 0;
}




















