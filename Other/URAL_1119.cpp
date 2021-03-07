#include <bits/stdc++.h>
using namespace std;

#define DG 141.4213562
float larg_value = 10000000000000.5;
int n,m;
float dp[1010][1010];
bool flag[1010][1010];
bool dg[1010][1010];


float f(int p,int q)
{
    if(p == n && q == m)
    {
        flag[p][q] = true;
        dp[p][q] = 0;
        return 0;
    }

    if(flag[p][q])
        return dp[p][q];

    float a = larg_value,b = larg_value,c = larg_value,temp = larg_value;
    if(dg[p+1][q+1])
    {
        if(flag[p+1][q+1]){
            a = DG + dp[p+1][q+1];
        }
        else a = DG + f(p+1,q+1);
    }
    if(p+1<=n)
    {
        if(flag[p+1][q]){
            b = 100.0 + dp[p+1][q];
        }
        else b = 100.0 + f(p+1,q);
    }
    if(q+1<=m)
    {
        if(flag[p][q+1]){
            c = 100.0 + dp[p][q+1];
        }
        else c = 100.0 + f(p,q+1);
    }
    temp = min(b,c);
    temp = min(temp,a);
    dp[p][q] = temp;
    flag[p][q] = true;
    return dp[p][q];
}

int main()
{

    int k;
    scanf("%d %d %d",&n,&m,&k);
    for(int i = 0; i < k; i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        dg[a][b] = true;
    }
    float min_cost = f(0,0);
    printf("%0.0f",min_cost);
    return 0;
}

