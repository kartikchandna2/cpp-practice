#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;
bool checkCycleUsingBFS(int source, vector<int>& vis, unordered_map<int, list<int>> adj) {
	queue<int> q;
	q.push(source);
	int par = -1;
	while (!q.empty()) {
		int first = q.front();
		q.pop();
		for (auto i : adj[first]) {
			if (vis[i] && i != par) {
				return true;
			}
			else if (!vis[i]) {
				q.push(i);
				vis[i] = 1;
				par = first;
			}
		}
	}
	return false;
}

bool checkCycleUsingDFS(int source, vector<int>& vis, unordered_map<int, list<int>> adj, int parent) {
	vis[source] = 1;
	for (auto i : adj[source]) {
		if (!vis[i]) {
			bool cycle = checkCycleUsingDFS(i, vis, adj, source);
			if (cycle) {
				return true;
			}
		}
		else if (i != parent) return true;
	}
	return false;
}


int main() {
	//create adj list
	int n;
	cout << "Enter the number of nodes: ";
	cin >> n;
	int m;
	cout << "Enter the number of edges: ";
	cin >> m;
	unordered_map<int, list<int>> adj;
	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	//print the adj list
	for (auto i : adj) {
		cout << i.first << "->";
		for (auto j : i.second) {
			cout << j << ", ";
		}
		cout << endl;
	}

	//checking cycle using bfs
	vector<int> vis(n, 0);
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			bool ans = checkCycleUsingBFS(i, vis, adj);
			if (ans) cout << "Yes";
			else cout << "No";
		}
	}

	//checking cycle using dfs
	vector<int> vis2(n, 0);
	for (int i = 0; i < n; i++) {
		if (!vis2[i]) {
			bool ans2 = checkCycleUsingDFS(i, vis2, adj, -1);
			if (ans2) cout << "\nYes";
			else cout << "\nNo";
		}
	}

}