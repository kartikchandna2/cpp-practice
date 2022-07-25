#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<queue>
using namespace std;

//for shortest path in undirected graph, use bfs to create a list to save parent of each vertex 
//use that list to find the shortest path starting from the destination back tracking to the source

void bfs(queue<int>& q, vector<int>& parent, vector<int>& vis, unordered_map<int, list<int>> adj, int source) {
	q.push(source);
	vis[source] = 1;
	parent[source] = -1;
	while (!q.empty()) {
		int fir = q.front();
		q.pop();
		for (auto j : adj[fir]) {
			if (!vis[j]) {
				q.push(j);
				vis[j] = 1;
				parent[j] = fir;
			}

		}
	}
}


int main() {
	//create adj list
	unordered_map<int, list<int>> adj;
	int n, m, u, v;
	int from, to;
	cout << "Enter the number of nodes and edges: "<<endl;
	cin >> n >> m;
	cout << "Enter starting and ending nodes of edges: "<<endl;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	//print adj list
	cout << "\nAdj list: \n";
	for (auto i : adj) {
		cout << i.first << "->";
		for (auto j : i.second) {
			cout << j << ", ";
		}
		cout << endl;
	}

	//bfs to get parent list
	vector<int> parent(n+1);
	queue<int> q;
	vector<int> vis(n+2, 0);
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			bfs(q, parent, vis, adj, i);
		}
	}

	//print parent array
	cout << endl;
	for (int i = 0; i < parent.size(); i++) {
		cout << i << "-> " << parent[i]<<endl;
	}

	//finding the path
	cout << "Enter the node from which you need the path: " << endl;
	cin >> from;
	cout << "Enter the node to which you need the path: " << endl;
	cin >> to;
	vector<int> path;
	int curr = to;
	path.push_back(curr);
	while (curr != from) {
		curr = parent[curr];
		path.push_back(curr);
	}
	for (auto i : path) {
		cout << i << " ";
	}

}