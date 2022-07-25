#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
#include<stack>
using namespace std;

void dfsTopoSort(vector<int>& vis, int source, unordered_map<int, list<pair<int, int>>>& adj, stack<int>& st) {
	vis[source] = 1;
	for (auto i : adj[source]) {
		if(!vis[i.first])
			dfsTopoSort(vis, i.first, adj, st);
	}
	st.push(source);
}


int main() {
	//create adj list of directed weighted graph
	int n, m, u, v;
	int weight;
	unordered_map<int, list<pair<int, int>>> adj;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> weight;
		adj[u].push_back({v, weight});
	}

	//print adj list
	for (auto i : adj) {
		cout << i.first << "-> ";
		for (auto j : i.second) {
			cout << "{"<<j.first << ", " << j.second<<"}"<<", ";
		}
		cout << endl;
	}

	//create a topological sort stack using dfs
	cout << endl;
	vector<int> vis(n+1);
	stack<int> st;
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			dfsTopoSort(vis, i, adj, st);
		}
	}


	//create shortest path array from source to destination using this stack st
	vector<int> path(n);
	for (int i = 0; i < n; i++) {
		path[i] = INT_MAX;
	}
	int source, dest;
	cout << "enter source and destination: " << endl;
	cin >> source >> dest;
	
	path[source] = 0;
	while (!st.empty()) {
		int top = st.top();
		st.pop();
		if (path[top] != INT_MAX) {
			for (auto i : adj[top]) {
				if (path[top] + i.second < path[i.first]) {
					path[i.first] = path[top] + i.second;
				}
			}
		}
	}

	//print min path array
	for (auto i : path) {
		cout << i << " ";
	}
}