#include <bits/stdc++.h>
using namespace std;
int head = 0;
int graph[100][100][2];

int min_vertex(int distance[],bool visited[])
{
    int min_value = INT_MAX,min_index;
    for(int i = 0; i < 100; i++)
    {
        if(min_value > distance[i])
        {
            min_value = distance[i];
            min_index = i;
        }
    }
    return min_index;
}
void dijkstra(int destination)
{
    int distance[100];
    bool visited[100];
    for(int i = 0; i < 100; i++)
    {
        distance[i] = INT_MAX;
        visited[i] = false;
    }
    distance[0] = 0;
    visited[0] = true;
    for(int i = 0; i < 99; i++)
    {
        int temp = min_vertex(distance,visited);
        visited[temp] = true;
        int prev = graph[0][temp][1];
        for(int j = 0; j < 100; j++)
        {
            int current = graph[temp][j][1];
            if(graph[temp][j][0] != INT_MAX && distance[temp] != INT_MAX && !visited[j])
            {
                int x = graph[temp][j][0];
                if(current != prev){
                    x += 60;
                    distance[j] = distance[temp] + x;
                    prev = current;
                }
                else if(distance[temp] + x < distance[j])
                {
                    distance[j] = distance[temp] + x;
                }

            }
        }
    }
    for(int i = 0; i < 100; i++)
    {
        cout<<i<<"  "<<distance[i]<<endl;
    }

}

int main()
{
    int n,k;
    while(true)
    {
        for(int i = 0; i < 100; i++)
        {
            for(int j = 0; j < 100; j++)
            {
                graph[i][j][0] = INT_MAX;
                graph[i][j][1] = -1;
            }
        }
        scanf("%d %d",&n,&k);
        int lift_time[n];
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&lift_time[i]);
        }
        getchar();
        for(int i = 0; i < n; i++)
        {
            string temp;
            getline(cin,temp);
            vector <int> time;
            stringstream ss;
            ss<<temp;
            string temp1;
            int x;
            while(!ss.eof())
            {
                ss>>temp1;
                if(stringstream(temp1)>>x)
                {
                    time.push_back(x);
                }
                temp1 = "";
            }
            for(int j = 0; j < time.size(); j++)
            {
                for(int k = j+1; k < time.size(); k++)
                {
                    int p = time[j],q = time[k];
                    int t = lift_time[i] * (time[k] - time[j]);
                    if((graph[p][q][0] == INT_MAX)||(graph[p][q][0] != INT_MAX && (t+60) < graph[p][q][0])){
                        graph[p][q][1] = i;
                        graph[q][p][1] = i;
                        graph[p][q][0] = t;
                        graph[q][p][0] = t;
                    }

                }
            }
        }
        for(int i = 0;i < 100;i++){
            for(int j = 0;j < 100;j++){
                if(graph[i][j][0] == INT_MAX)cout<<"- ";
                else cout<<graph[i][j][0]<<" ";
            }
            cout<<endl;
        }
       // dijkstra(k);

    }
    return 0;
}

