// header1.h
#ifndef HEADER4_H
#define HEADER4_H
// Declarations and definitions

#include <bits/stdc++.h>

using namespace std;
// Other declarations and definitions

class Graph {
private:
    int n,e; // n -> number of nodes, e -> number of edges

public:
    // DAG ( Directed Acyclic Graph ): Which graph don't have any cycle, that is called,
    // Cyclic Graph: Which graph has cycle.
    Graph() {
        cout << "Number of nodes should be: ";
        cin >> n;
        cout << "Number of edges should be: ";
        cin >> e;
    }
    uint32_t reverseBits(uint32_t n) {
        uint32_t reversed = 0;
        cout << "Reversed: " << reversed << " Main 32 bits: " << n << endl;
        for (int i = 0; i < 32; i++) {
            reversed <<= 1;
            cout << "Reversed: " << reversed << ", ";
            reversed |= (n & 1);
            cout << "Reversed: " << reversed << ", ";
            n >>= 1;
            cout << "Main 32 bits: " << n << endl;
        }
        return reversed;
    }
    void undirectedGraph() {
        vector<vector<int>> adjMatrix(n, vector<int>(n,0)); // 2-D vector
        vector<pair<int, int>> edgeVector;

        for(int i=0; i<e; i++) {
            int node1, node2;
            cout << "Enter the node1 and node2, connected with edge: ";
            cin >> node1;
            cin >> node2;
            edgeVector.push_back({node1, node2});
            adjMatrix[node1-1][node2-1] = 1;
            adjMatrix[node2-1][node1-1] = 1;
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }

        cout << "BFS Traversal is: ";
        vector<int> bfsTraversal = bfsOfGraph(adjMatrix);
        for (int i : bfsTraversal) {
            cout << i + 1 << " "; // +1 to convert 0-indexed back to 1-indexed nodes
        }
        cout << endl;

        cout << "DFS Traversal is: ";
        vector<int> dfsTraversal = dfsOfGraph(adjMatrix);
        for(int i:dfsTraversal) {
            cout << i + 1 << " ";
        }
        cout << endl;

        cout << "Number of Connected Components: " << findCircleNum(adjMatrix) << endl;

        bool checkCycle = detectCycle(adjMatrix);
        if(checkCycle == true) {
            cout << "There are cycles in the graph" << endl;
        } else {
            cout << "There are not cycles in the graph" << endl;
        }
        
        colorGraph(adjMatrix);
        
        if(isBipartite(adjMatrix)) {
        	cout << "The graph is bipartite" << endl;
        } else {
        	cout << "The graph is not bipartite" << endl;
        }
    }

private:
    vector<int> bfsOfGraph(vector<vector<int>> &adjMatrix) {
        vector<int> vis(n, 0); // visited array
        queue<int> q;
        vector<int> bfs;
        for(int i = 0; i < vis.size(); i++) {
            if(vis[i] == 0) {
                vis[i] = 1; // Start from the first node (index 0)
                q.push(i);
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    bfs.push_back(node);
                    // Traverse neighbors in the adjacency matrix
                    for(int neighbour = 0; neighbour < n; neighbour++) {
                        if(adjMatrix[node][neighbour] == 1 && !vis[neighbour]) {
                            vis[neighbour] = 1;
                            q.push(neighbour);
                        }
                    }
                }
            }
        }
        return bfs;
    }

    vector<int> dfsOfGraph(vector<vector<int>> &adjMatrix) {
        vector<int> vis(n ,0);
        stack<int> s;
        vector<int> dfs;
        for(int i = 0; i < vis.size(); i++) {
            if(vis[i] == 0) {
                vis[i] = 1;
                s.push(i);
                dfsOfGraph(vis, s, dfs, adjMatrix);
            }
        }
        return dfs;
    }

    void dfsOfGraph(vector<int> &vis, stack<int> &s,
                    vector<int> &dfs, vector<vector<int>> &adjMatrix) {
        while(!s.empty()) {
            int node = s.top();
            s.pop();
            dfs.push_back(node);

            // Traverse neighbors in the adjacency matrix
            for(int neighbour = 0; neighbour < n; neighbour++) {
                if(adjMatrix[node][neighbour] == 1 && !vis[neighbour]) {
                    vis[neighbour] = 1;
                    s.push(neighbour);
                    dfsOfGraph(vis, s, dfs, adjMatrix);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int provinces = 0;
        vector<int> visited(n, 0);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                connectedOfGraph(visited, i, isConnected);
                provinces++;
            }
        }
        return provinces;
    }

    void connectedOfGraph(vector<int> &visited, int node,
                          vector<vector<int>> &isConnected) {
        stack<int> s;
        s.push(node);
        visited[node] = 1;

        while (!s.empty()) {
            int curr = s.top();
            s.pop();

            // Traverse neighbors in the adjacency matrix
            for (int neighbour = 0; neighbour < isConnected.size(); neighbour++) {
                if (isConnected[curr][neighbour] == 1 && !visited[neighbour]) {
                    visited[neighbour] = 1;
                    s.push(neighbour);
                }
            }
        }
    }

    bool detectCycle(vector<vector<int>> &adjMatrix) {
        vector<int> visit(n, 0);
        for(int node = 0; node < n; node++) {
            if(visit[node] == 0) {
                if(detectCycle(adjMatrix, visit, node)) {
                   return true;
                }
            }
        }
        return false;
    }

    bool detectCycle(vector<vector<int>> &adjMatrix, vector<int> &visit,
                     int node) {
        queue<pair<int, int>> q;
        q.push({node, -1});
        visit[node] = 1;
        int parent = node;

        while(!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(int neighbour = 0; neighbour < n; neighbour++) {
                if(visit[neighbour] == 0 && adjMatrix[node][neighbour] == 1) {
                    q.push({neighbour, node});
                    visit[neighbour] = 1;
                } else if(neighbour != parent && adjMatrix[node][neighbour] == 1) {
                    return true;
                }
            }
        }
        return false;
    }
    
    void colorGraph(vector<vector<int>> &adjMatrix) {
        vector<int> color(n, -1);  // Color array initialized to -1 (uncolored)
        vector<int> colorDFS(n, -1);

        // Iterate through each node and apply coloring
        for (int node = 0; node < n; node++) {
            if (color[node] == -1) {
                colorGraph(adjMatrix, color, node);  // Color the unvisited node
                colorGraphDFS(adjMatrix, colorDFS, node);
            }
        }

        // Display the color assigned to each node
        cout << "Graph coloring using BFS algorithm:" << endl;
        for (int i = 0; i < n; i++) {
            cout << "Node " << i+1 << ": Color " << color[i] << endl;
        }
        cout << "Graph coloring using DFS algorithm:" << endl;
        for (int i = 0; i < n; i++) {
            cout << "Node " << i+1 << ": Color " << colorDFS[i] << endl;
        }
    }

    void colorGraph(vector<vector<int>> &adjMatrix, vector<int> &color, int node) {
        queue<int> q;
        q.push(node);
        color[node] = 0;  // Assign the first color (0) to the starting node

        // BFS traversal
        while (!q.empty()) {
            int currentNode = q.front();  // Get the current node
            q.pop();

            // Traverse all neighbors of the current node
            for (int neighbour = 0; neighbour < n; neighbour++) {
                // If the neighbor is uncolored and there's an edge between them
                if (color[neighbour] == -1 && adjMatrix[currentNode][neighbour] == 1) {
                    // Create a boolean array to mark the colors used by adjacent nodes
                    vector<bool> colorSet(n, false);  // To keep track of colors used

                    // Mark all colors used by the neighbors
                    for (int i = 0; i < n; i++) {
                        if (adjMatrix[neighbour][i] == 1 && color[i] != -1) {
                            colorSet[color[i]] = true;  // Mark this color as used
                        }
                    }

                    // Find the first available color
                    int chosenColor = 0;
                    while (colorSet[chosenColor] == true) {
                        chosenColor++;  // Move to the next color if current is used
                    }

                    // Assign the chosen color to the neighbor
                    color[neighbour] = chosenColor;

                    // Add the neighbor to the queue for further processing
                    q.push(neighbour);
                }
            }
        }
    }

    void colorGraphDFS(vector<vector<int>> &adjMatrix, vector<int> &color, int node) {
        if(color[node] == -1) {
            vector<bool> colorSet(n, false);
            for(int inner = 0; inner < n; inner++) {
                if(adjMatrix[node][inner] == 1 && color[inner] != -1) {
                    colorSet[color[inner]] = true;  // Mark the color as used
                }
            }
            int chosenColor = 0;
            while(colorSet[chosenColor] == true) {
                chosenColor++;  // Find the first available color
            }
            color[node] = chosenColor;  // Assign the chosen color to the node
        }
        for(int i = 0; i < n; i++) {
            if(adjMatrix[node][i] == 1 && color[i] == -1) {  // Use == for comparison
                colorGraphDFS(adjMatrix, color, i);  // Recursively color neighbors
            }
        }
    }
    
    bool isBipartite(vector<vector<int>> adjMatrix) {
    	vector<int> color(n , -1);
    	for(int i = 0; i < n; i++) {
    		if(color[i] == -1) {
    			if(isBipartite(i, 0, color, adjMatrix) == false) {
    				return false;
    			}
    		}
    	}
    	return true;
    }
    
    bool isBipartite(int node, int col, vector<int>& color, vector<vector<int>> adjMatrix) {
    	color[node] = col;
    	for(int i = 0; i < n; i++) {
    		if(adjMatrix[node][i] == 1) {
    			if(color[i] == -1) {
    				if(isBipartite(i, 1 - col, color, adjMatrix) == false) return false;
    			}
    			else if(color[i] == col) return false;
    		}
    	}
    	return true;
    }

};

#endif // HEADER2_H
#pragma once