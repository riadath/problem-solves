#include <bits/stdc++.h>
using namespace std;

#ifdef IHAVETOPEE
#include "debug.h"
#else
#define debug(args)
#endif
#define FIO ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);

vector<pair<pair<int, int>, int>>edges;
int n, m, cost[1000][1000], next1[1000][1000], parent[1000];
vector<int>dist(100009, 1e7);
bool bellman_ford(int src) {
	dist[src] = 0;
	for (int k = 0;k < n - 1;k++) {
		for (size_t i = 0; i < edges.size(); i++) {
			// debug(edges[i]);
			int u = edges[i].first.first, v = edges[i].first.second;
			int w = edges[i].second;
			if (dist[v] > dist[u] + w)dist[v] = dist[u] + w, parent[v] = u;
		}
		// cout<<"STEP : "<<k+1 <<" \n";
		// for (int i = 1;i <= n;i++) {
		// 	cout << "Distance 1->" << i << " : " << dist[i] << "\n";
		// }
	}
	for (size_t i = 0; i < edges.size(); i++) {
		int u = edges[i].first.first, v = edges[i].first.second;
		int w = edges[i].second;
		if (dist[v] > dist[u] + w)return false;
	}
	return true;
}

void flyod_warshal() {

	for (size_t k = 1; k <= n; k++) {
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n;j++) {
				if (cost[i][j] > (cost[i][k] + cost[k][j])) {
					next1[i][j] = next1[i][k];
					cost[i][j] = cost[i][k] + cost[k][j];
				}

			}
		}
	}
}

vector<int> print_path(int i,int j) {
	vector<int>path;
	path.push_back(i);
	while(i != j){
		i = next1[i][j];
		path.push_back(i);
	}
	return path;
}

int main()
{
	FIO;
#ifdef IHAVETOPEE 
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++)cost[i][j] = (i == j) ? (0) : 1e7, next1[i][j] = j;
	}
	for (size_t i = 0; i < m; i++) {
		int u, v, w;cin >> u >> v >> w;
		edges.push_back({ {u,v},w });
		cost[u][v] = w;
	}

	bool flag = bellman_ford(1);
	if (!flag) {
		cout << "Negative Cycle Detected\n";
		return 0;
	}
	for (int i = 1;i <= n;i++) {
		cout << "Distance 1->" << i << " : " << dist[i] << "\n";
	}
	for (int i = 1;i <= n;i++) {
		if (dist[i] == 1e7)continue;
		cout << "1->" << i << " -> ";
		vector<int>path;
		int cur = i;
		while (parent[cur] != cur) {
			path.push_back(cur);
			cur = parent[cur];
		}
		// path.push_back(1);
		reverse(path.begin(), path.end());
		for (size_t j = 0; j < path.size(); j++) {
			cout << path[j] << " ";
		}cout << "\n";

	}

	flyod_warshal();
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			cout << "Distance " << i << "->" << j << " : ";
			cout << cost[i][j] << "\n";
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(cost[i][j] == 1e7 || (i == j))continue;
			vector<int>path = print_path(i,j);
			cout<<"Paht : "<<i<<"->"<<j<<" : ";
			for (int i = 0; i < path.size(); i++)
			{
				cout<<path[i]<<" ";
			}cout<<"\n";
			
		}
	}

	return 0;
}
