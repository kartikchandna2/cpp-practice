#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
using namespace std;

bool checkCycle(int source, vector<int>& vis, vector<int>& dfsvis, unordered_map<int, list<int>> adj) {
	vis[source] = 1;
	dfsvis[source] = 1;
	for (auto i : adj[source]) {
		if (!vis[i]) {
			bool cycle = checkCycle(i, vis, dfsvis, adj);
			if (cycle) return true;
		}
		else if (dfsvis[i]) {
			return true;
		}
	}
	dfsvis[source] = 0;
	return false;
}


int main() {
	//create adj list for directed graph
	unordered_map<int, list<int>> adj;
	int n, m;
	cin >> n >> m;
	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
	}

	//print adj list
	for (auto i : adj) {
		cout << i.first << "->";
		for (auto j : i.second) {
			cout << j << ",";
		}
		cout << endl;
	}

	//check for cycle 
	//concept: if node is visited and is also in the recursion stack meaning cycle exists
	vector<int> vis(n, 0);
	vector<int> dfsvis(n, 0);  //for recursion stack of dfs
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			bool ans = checkCycle(i, vis, dfsvis, adj);
			if (ans) cout << "Yes";
			else cout << "No";
		}
	}

}