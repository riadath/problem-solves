#include <bits/stdc++.h>
using namespace std;
int n,d,x[20000],y[20000],rat[20000];
int killed[1025][1025];
double distance(int x1,int y1,int x2,int y2)
{
    double dist = sqrt(pow((x1-x2),2)+pow((y1-y2),2));
    return dist;
}
bool myfn(int i, int j)
{
    return i<j;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        cin>>d;
        cin>>n;
        for(int i = 0; i < n; i++)
        {
            cin>>x[i]>>y[i]>>rat[i];
        }
        int x_max,y_max,x_min,y_min;
        x_max = *max_element(x,x+n,myfn);
        y_max = *max_element(y,y+n,myfn);
        x_min = *min_element(x,x+n,myfn);
        y_min = *min_element(y,y+n,myfn);
      //  printf("%d %d %d %d\n",x_min,x_max,y_min,y_max);
        for(int i = x_min; i <= x_max; i++)
        {
            for(int j = y_min; j <= y_max; j++)
            {
                for(int k = 0; k < n; k++)
                {
                    if(distance(x[k],y[k],i,j) <= (d))
                    {
                        killed[i][j] += rat[k];
                    }
                }
            }
        }
        int max_rats = 0 ;
        int max_i = x_min,max_j = y_min;
        for(int i = x_min; i <= x_max; i++)
        {
            for(int j = y_min; j <= y_max; j++)
            {
                if(killed[i][j] >= max_rats)
                {
                    max_rats = killed[i][j];
                    max_i = i;
                    max_j = j;
                }
            }
        }
        cout<<max_i<<" "<<max_j<<" "<<max_rats<<endl;
        return 0;
    }
}

















































