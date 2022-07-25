#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<list>
using namespace std;
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
	cout << "\nAdj List: \n";
	for (auto i : adj) {
		cout << i.first << "->";
		for (auto j : i.second) {
			cout << j << ", ";
		}
		cout << endl;
	}

	//check if topological sort if possible, if yes, there is no cycle as it is only possible for DAG which is acyclic
	queue<int> q;
	vector<int> indegree(n + 1);
	int check = 0;

	for (auto i : adj) {
		for (auto j : i.second) {
			indegree[j]++;
		}
	}

	for (int i = 1; i < indegree.size(); i++) {
		if (!indegree[i]) q.push(i);
	}

	while (!q.empty()) {
		int fir = q.front();
		q.pop();
		check++;
		for (auto i : adj[fir]) {
			indegree[i]--;
			if (!indegree[i]) {
				q.push(i);
			}			
		}
	}

	//if check variable is equal to number of vertices -> topological sort exists -> no cycle
	if (check == n) {
		cout << "no cycle exists" << endl;
	}
	else {
		cout << "cycle exists" << endl;
	}
	
}