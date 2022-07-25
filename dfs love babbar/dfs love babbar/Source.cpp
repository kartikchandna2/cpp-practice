#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;
void dfs(vector<int>& component, vector<int>& visited, unordered_map<int, list<int>> adj, int i) {
	component.push_back(i);
	visited[i] = 1;

	for (auto k : adj[i]) {
		if(!visited[k]) dfs(component, visited, adj, k);
	}

}
int main() {
	//create adj list
	unordered_map<int, list<int>> adj;
	int n;
	cout << "Enter the number of nodes: ";
	cin >> n;
	int m;
	cout << "Enter the number of edges: ";
	cin >> m;
	for (int i = 0; i < m; i++) {
		int u;
		cin >> u;
		int v;
		cin >> v;
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

	//dfs
	vector<int> visited(n, 0);
	
	vector<vector<int>> ans;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			vector<int> component;
			dfs(component, visited, adj, i);
			ans.push_back(component);
		}
	}

	for (auto i : ans) {
		for (auto j : i) {
			cout << j << ", ";
		}
	}
}