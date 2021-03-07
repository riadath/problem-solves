#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
int dist[8][8];
bool visited[8][8];
int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};
int des_x, des_y, row, col;
void bfs_pair(int sr_x, int sr_y)
{
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            dist[i][j] = INT_MAX;
        }
    }
    queue<pii> graph;
    graph.push(pii(sr_x, sr_y));
    dist[sr_x][sr_y] = 0;
    visited[sr_x][sr_y] = true;
    while (!graph.empty())
    {
        pii top = graph.front();
        graph.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = top.first + fx[i];
            int y = top.second + fy[i];
            if (x >= 0 && x < row && y >= 0 && y < col && !visited[x][y] && dist[x][y] == INT_MAX)
            {
                dist[x][y] = dist[top.first][top.second] + 1;
                if (x == des_x && y == des_y)
                    return;
                visited[x][y] = true;
                graph.push(pii(x, y));
            }
        }
    }
}
int main()
{
    des_x = 2, des_y = 3, row = 4, col = 4;
    bfs_pair(0, 0);
    cout << dist[des_x][des_y] << endl;
    return 0;
}
