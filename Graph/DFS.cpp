#include <iostream>
#include <vector>
using namespace std;

void DFSrec(vector<vector<int>> &adj, vector<bool> &visited, int s) {
    visited[s] = true; // Mark the current node as visited
    cout << s << " ";  // Print the current node

    // Traverse all adjacent nodes
    for (int i : adj[s]) {
        if (!visited[i]) { // Check if the adjacent node is unvisited
            DFSrec(adj, visited, i); // Recursively visit the adjacent node
        }
    }
}

void DFS(vector<vector<int>> &adj, int s) {
    vector<bool> visited(adj.size(), false); 
    DFSrec(adj, visited, s);
}


void addEdge(vector<vector<int>> &adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() {

    cout << "Enter number of nodes (vertices): ";
    int V;
    cin >> V;

    cout << "Enter number of edges: ";
    int E;
    cin >> E;


    vector<vector<int>> adj(V);


    cout << "Enter edges (format: u v):\n";
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(adj, u, v);
    }


    cout << "Enter the starting vertex for DFS: ";
    int start;
    cin >> start;
    DFS(adj, start);

    return 0;
}
