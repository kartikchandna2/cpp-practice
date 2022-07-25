#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<unordered_map>
using namespace std;

//kahn's algo uses bfs and an array to keep a check of indegree of a vertice
//jaise jaise indegree kam hoti jaye, queue mein add krte jao

vector<int> kahn(vector<int>& indeg, unordered_map<int, list<int>> adj) {
	vector<int> ans;
	queue<int> q;
	for (int i = 1; i < indeg.size(); i++) {
		if (!indeg[i]) {  //if indeg is 0, push in queue
			q.push(i);
		}
	}	
	
	while (!q.empty()) {
		int fir = q.front();
		q.pop();
		ans.push_back(fir);
		for (auto j : adj[fir]) { //update indegree of neighbors
			indeg[j]--;
			if (!indeg[j])  //if indeg is 0, push in queue
				q.push(j);
		}
	}
	return ans;
}


int main() {
	//create adj list
	unordered_map<int, list<int>> adj;
	int n, m;
	int u, v;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
	}

	//print adj list
	cout << "\nAdj list: \n";
	for (auto i : adj) {
		cout << i.first << "->";
		for (auto j : i.second) {
			cout << j << ",";
		}
		cout << endl;
	}

	//kahn's
	vector<int> ans;
	vector<int> indeg(n+1);

	//setting indegree
	for (auto i : adj) {
		for (auto j : i.second) {
			indeg[j]++;
		}
	}

	ans = kahn(indeg,adj);
	
	

	for (auto i : ans) {
		cout << i << " ";
	}
}