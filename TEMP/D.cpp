#include <bits/stdc++.h>
using namespace std;

int n, m; // n: number of nodes(numbered from 1 to n),m: number of edges
vector<vector<int>>graph(1000); // Graph : adjacency list
map<pair<int, int>, int> cost; //Cost of edge (u,v)=>w
map<int, bool>visited;
//1 : Prims Algo O(m long(n)) approach using priority queue
int prims1()
{
	visited.clear();
	int vis_cnt = 1, min_cost = 0; //any node from 1-n will work
	visited[1] = true;
	priority_queue<pair<int, pair<int, int>>> node;
	for (int i = 0; i < graph[1].size(); i++) {
		int v = graph[1][i];
		int x = cost[{1, v}];
		node.push({ -1 * x, {1, v} });
	}
	while (vis_cnt < n)
	{
		pair<int, pair<int, int>> u = node.top();
		node.pop(); 	        // Priority queue provides 
		int x = u.second.second;//the min/max edge in O(log(n)) time
		if (!visited[x]) {
            min_cost += -1 * u.first;
			visited[x] = true;
			vis_cnt++;
			for (int i = 0; i < graph[x].size(); i++) {
				int v = graph[x][i];
				if (!visited[v]) {
					int c = cost[{x, v}];
					node.push({ -1 * c, {x,v} });
				}
			}
		}
	}
	return min_cost;
}
//1 : Prims Algo O(n^2) approach 
int prims2() {
	visited.clear();
	int vis_cnt = 1, min_cost = 0; //any node from 1-n will work
	visited[1] = true;
	vector<pair<int, pair<int, int>>> node;
	for (int i = 0; i < graph[1].size(); i++) {
		int v = graph[1][i];
		int x = cost[{1, v}];
		node.push_back({ x, {1, v} });
	}
	while (vis_cnt < n) {
		pair<int, pair<int, int>> u;
		int min_weight = 1e7;
		//finding the min/max node in O(n) time
		for (int i = 0;i < node.size();i++) {
			if (node[i].first < min_weight && !visited[node[i].second.second]) {
				u = node[i];
				min_weight = node[i].first;
			}
		}
		int x = u.second.second;
		if (!visited[x]) {
            min_cost += u.first;
			visited[x] = true;
			vis_cnt++;
			for (int i = 0; i < graph[x].size(); i++) {
				int v = graph[x][i];
				if (!visited[v]) {
					int c = cost[{x, v}];
					node.push_back({ c, {x,v} });
				}
			}
		}
	}
	return min_cost;
}


int parent[1000];

int dsu1(int u) { // DSU WITH PATH COMPRESSION
	return parent[u] = (parent[u] == u) ? u : dsu1(parent[u]);
}

int dsu2(int u) {//DSU WITHOUT PATH COMPRESSION
	return (parent[u] == u) ? u : dsu2(parent[u]);
}

//Path Compression : false, Sorting : false
// Complexity : O(m^2 + n * m)
int kruskal1(vector<pair<int, pair<int, int>>>edges) {
	visited.clear();
	int min_cost = 0;
	for (int i = 1;i <= n;i++)parent[i] = i;
	for (int i = 0;i < edges.size();i++) {
		int mn = 1e7, idx = -1;
		pair<int, pair<int, int>> temp;
		for (int ii = 0;ii < edges.size();ii++) {
			if ((edges[ii].first < mn) && (!visited[ii])) {
				temp = edges[ii];
				idx = ii;
				mn = edges[ii].first;
			}
		}
		visited[idx] = true;
		int u = temp.second.first;
		int v = temp.second.second;
		u = dsu2(u);
		v = dsu2(v);
		if (u != v) {
			parent[u] = v;
			min_cost += temp.first;
		}
	}
	return min_cost;
}

//Path Compression : false, Sorting : true
// Complexity : O(m + n * m + mlog(n))
int kruskal2(vector<pair<int, pair<int, int>>>edges) {
	sort(edges.begin(), edges.end());
	int min_cost = 0;
	for (int i = 1;i <= n;i++)parent[i] = i;
	for (int i = 0;i < edges.size();i++) {
		pair<int, pair<int, int>> temp = edges[i];
		int u = temp.second.first;
		int v = temp.second.second;
		u = dsu2(u);
		v = dsu2(v);
		if (u != v) {
			parent[u] = v;
			min_cost += temp.first;
		}
	}
	return min_cost;
}

//Path Compression : true, Sorting : false
// Complexity : O(m^2 + m log(n))
int kruskal3(vector<pair<int, pair<int, int>>>edges) {
	visited.clear();
	int min_cost = 0;
	for (int i = 1;i <= n;i++)parent[i] = i;
	for (int i = 0;i < edges.size();i++) {
		int mn = 1e7, idx = -1;
		pair<int, pair<int, int>> temp;
		for (int ii = 0;ii < edges.size();ii++) {
			if (edges[ii].first < mn && !visited[ii]) {
				temp = edges[ii];
				idx = ii;
				mn = edges[ii].first;
			}
		}
		visited[idx] = (idx != -1) ? 1 : 0;
		int u = temp.second.first;
		int v = temp.second.second;
		u = dsu1(u);
		v = dsu1(v);
		if (u != v) {
			parent[u] = v;
			min_cost += temp.first;
		}
	}
	return min_cost;
}

//Path Compression : true, Sorting : true
// Complexity : O(mlog(n))
int kruskal4(vector<pair<int, pair<int, int>>>edges) {
	sort(edges.begin(), edges.end());
	int min_cost = 0;
	for (int i = 1;i <= n;i++)parent[i] = i;
	for (int i = 0;i < edges.size();i++) {
		pair<int, pair<int, int>> temp = edges[i];
		int u = temp.second.first;
		int v = temp.second.second;
		u = dsu1(u);
		v = dsu1(v);
		if (u != v) {
			parent[u] = v;
			min_cost += temp.first;
		}
	}
	return min_cost;
}

int main()
{
	vector<pair<int, pair<int, int>>>edges;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v, w;cin >> u >> v >> w;
		graph[u].push_back(v);
		graph[v].push_back(u);
		edges.push_back({ w,{u,v} });
		cost[{u, v}] = cost[{v, u}] = w;
	}

	cout<<"Minimum Cost with Prim's Algorithm\n";
	cout<<"___________________________________\n";
	cout<<"\nO(m log(n)) : ";
	cout << prims1() << '\n';
	cout<<"\nO(n^2) : ";
	cout << prims2() << '\n';

	cout<<"\n\nMinimum Cost with Kruskals Algorithm\n";
	cout<<"___________________________________\n";
	cout<<"\nO(m^2 + n * m) : ";
	cout << kruskal1(edges) << '\n';
	cout<<"\nO(m + n * m + mlog(n)) : ";
	cout << kruskal2(edges) << '\n';
	cout<<"\nO(m^2 + m log(n)) : ";
	cout << kruskal3(edges) << '\n';
	cout<<"\nO(mlog(n)) : ";
	cout << kruskal4(edges) << '\n';


	return 0;
}
