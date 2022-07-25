#include<iostream>
#include<list>
#include<vector>
#include<unordered_map>
using namespace std;



//adjacency list using unordered map
class graph {
public:
	unordered_map<int, list<int>> g;
	void addEdge(int u, int v, bool directional) {
		g[u].push_back(v);
		if (!directional) g[v].push_back(u);
	}
	void printGraph() {
		for (auto i : g) {
			cout << i.first << "->";
			for (auto j : i.second) {
				cout << j << "," ;
			}
			cout << endl;
		}
	}
};
int main() {
	int n;
	//no of nodes
	cin >> n;
	int m;
	//no of edges
	cin >> m;
	graph g;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g.addEdge(u, v, 0);
	}
	g.printGraph();
}