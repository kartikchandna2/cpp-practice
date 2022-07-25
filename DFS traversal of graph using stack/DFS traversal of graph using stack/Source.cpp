#include<iostream>
using namespace std;
int visited[7] = { 0, 0, 0, 0, 0, 0, 0 };
int adjacency_matrix[7][7] = {
	{0,1,1,1,0,0,0},
	{1,0,0,1,0,0,0},
	{1,0,0,1,1,0,0},
	{1,1,1,0,1,0,0},
	{0,0,1,1,0,1,1},
	{0,0,0,0,1,0,0},
	{0,0,0,0,1,0,0}
};
void DFS(int i) {
	cout << i << endl;
	visited[i] = 1;
	for (int j = 0; j < 7; j++) {
		if (adjacency_matrix[i][j] == 1 && visited[j] == 0) {
			DFS(j);
		}
	}
}
int main() {
	DFS(0);
}