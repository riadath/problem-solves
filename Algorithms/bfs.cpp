#include <bits/stdc++.h>
using namespace std;
vector<int> graph[500];
int level[500];
int destination;
int bfs(int n, int source)
{
    for (int i = 0; i < n; i++)
    {
        level[i] = INT_MAX;
    }
    bool visited[n];
    memset(visited, false, sizeof(visited));
    level[source] = 0;
    queue<int> nodes;
    nodes.push(source);
    visited[source] = true;
    int i, j;
    while (!nodes.empty())
    {
        int i = nodes.front();
        nodes.pop();
        for (j = 0; j < graph[i].size(); j++)
        {
            if (level[i] != INT_MAX && level[graph[i][j]] == INT_MAX && !visited[graph[i][j]])
            {
                level[graph[i][j]] = level[i] + 1;
                if (graph[i][j] == destination)
                {
                    return level[graph[i][j]];
                }
                visited[graph[i][j]] = true;
                nodes.push(graph[i][j]);
            }
        }
    }
    return -1;
}

int main()
{
    int n, edge;
    cin >> n >> edge >> destination;
    for (int i = 0; i < edge; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int lev = bfs(n, 0);
    if (lev != -1)
    {
        printf("%d\n", lev);
    }
    else
    {
        cout << INT_MAX << endl;
    }

    return 0;
}
