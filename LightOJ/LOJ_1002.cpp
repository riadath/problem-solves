
#include <bits/stdc++.h>
using namespace std;
int N;
int arr[500][500];

int lrgst(int a,int b)
{
    if(a > b)
        return a;
    else
        return b;
}
int min_dist(int distance[],bool visited[])
{
    int minimum = INT_MAX,index;
    for(int i = 0; i < N; i++)
    {
        if(distance[i] <= minimum && visited[i] == false && distance[i] != -1)
        {
            minimum = distance[i];
            index = i;
        }
    }
    return index;
}
void dijkstra(int source)
{
    int distance[N];
    bool visited[N];
    bool mark[N];
    for(int i = 0; i < N; i++)
    {
        distance[i] = -1;
        visited[i] = false;
        mark[i] = false;
    }
    distance[source] = 0;
    for(int i = 0; i < N; i++)
    {
        int temp = min_dist(distance,visited);
        visited[temp] = true;
        for(int j = 0; j < N; j++)
        {
            if(!visited[j] && (arr[temp][j] != 0) && (distance[temp] != -1))
            {
                int tm = lrgst(distance[temp],arr[temp][j]);
                if(!mark[j])
                {
                    distance[j] = tm;
                    mark[j] = !mark[j];
                }
                else if(mark[j] && distance[j] > tm)
                {
                    distance[j] = tm;
                }
            }
        }
    }
    for(int i = 0; i < N; i++)
    {
        if(distance[i] == -1)
        {
            printf("Impossible\n");
        }
        else
            printf("%d\n",distance[i]);
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int k = 1; k <= T; k++)
    {
        int m;
        scanf("%d %d", &N, &m);
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                arr[i][j] = 0;
            }
        }
        for(int i = 0; i < m; i++)
        {
            int p,q,r = 0;
            scanf("%d %d %d",&p,&q,&r);
            if(arr[p][q] == 0)
            {
                arr[p][q] = r,arr[q][p] = r;
            }
            if(arr[p][q] != 0 && arr[p][q] > r)
            {
                arr[p][q] = r,arr[q][p] = r;
            }

        }
        int source;
        scanf("%d",&source);
        printf("Case %d:\n",k);
        dijkstra(source);
    }
    return 0;
}





