#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<stack>
using namespace std;

//can only works for DAG i.e. directional acyclic graph

//sort the vertices in such a way that u always comes before v in a edge

void topSorting(stack<int>& st, int source, vector<int>& vis, unordered_map<int, list<int>> adj) {
	vis[source] = 1;
	for (auto i : adj[source]) {
		if (!vis[i]) {
			
			topSorting(st, i, vis, adj);
			
		}
	}
	st.push(source);
}

int main() {
	//create adj list
	int n, m;
	cin >> n >> m;
	int u, v;
	unordered_map<int, list<int>> adj;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
	}

	//print adj list
	cout << "\nAdj list:\n";
	for (auto i : adj) {
		cout << i.first << "->";
		for (auto j : i.second) {
			cout << j << ", ";
		}
		cout << endl;
	}

	//find the sorted vertices using dfs and a stack
	stack<int> topSort;
	vector<int> vis(n+5, 0);
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			topSorting(topSort, i, vis, adj);
		}
	}
	
	//printing sorted array from stack
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << topSort.top() << endl;
		topSort.pop();
	}
}