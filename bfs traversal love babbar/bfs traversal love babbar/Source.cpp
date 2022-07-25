#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;
int main() {
	//let's make an adjency list of the graph
	int n;
	cout << "Enter the number of nodes: ";
	cin >> n;
	int m;
	cout << "Enter the number of edges: ";
	cin >> m;
	unordered_map<int, list<int>> adj;
	for (int i = 0; i < m; i++) {
		int u;
		cin >> u;
		int v;
		cin >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	//print the adj list
	cout << "Adjacency List: " << endl;
	for (auto i: adj) {
		cout << i.first << "->";
		for (auto j : i.second) {
			cout << j << ", ";
		}
		cout << endl;
	}

	//bfs
	vector<int> visited(n, 0);
	vector<int> ans;
	queue<int> q;
	int s = 0;
	q.push(s);
	visited[s] = 1;
	
	while (!q.empty()) {
		int first = q.front();
		ans.push_back(first);
		q.pop();
		
		for (auto i : adj[first]) {
			if (!visited[i]) {
				q.push(i);
				visited[i] = 1;

			}
		}
			
	}
	for (auto i : ans) {
		cout << i << " ";
	}
}