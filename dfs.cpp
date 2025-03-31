#include <iostream>
#include <vector>
using namespace std;

// Function for DFS traversal
void dfs(int node, vector<int> adj[], vector<bool> &visited) {
    // Mark the current node as visited
    visited[node] = true;
    cout << node << " ";

    // Traverse all unvisited neighbors
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int main() {
    int vertices = 5; // Number of vertices
    vector<int> adj[vertices + 1]; // Adjusting for 1-based indexing

    // Example graph: Add edges (undirected)
    // Example graph: Add edges (undirected)
    adj[1].push_back(1);
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[1].push_back(6);
    adj[2].push_back(4);
    adj[2].push_back(5);
    adj[3].push_back(6);
    adj[3 ].push_back(7);

    // Visited array to keep track of visited nodes
    vector<bool> visited(vertices + 1, false); // Adjusting for 1-based indexing

    // Start DFS from node 1
    cout << "DFS Traversal: ";
    dfs(2, adj, visited);

    return 0;
}
