#include <bits/stdc++.h>
// #include "UndirectedGraph.h"

using namespace std;

class Graph {
private:
	int n,e;
public:
	Graph() {
		cout << "Number of nodes should be: ";
		cin >> n;
		cout << "Number of edges should be: ";
		cin >> e;
	}

	void directedGraph() {
		vector<vector<int>> adjMatrix(n, vector<int>(n, 0));
		for(int i = 0; i < e; i++) {
			int node1, node2;
			cout << "Enter the node1 directed to node2, connected with edge: ";
			cin >> node1 >> node2;
			adjMatrix[node1 - 1][node2 - 1] = 1;
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				cout << adjMatrix[i][j] << " ";
			}
			cout << endl;
		}
	}
};
int main()
{
    cout << "Hello world!" << endl;
    Graph g;
    g.directedGraph();
    return 0;
}
