#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Function declaration for BFS from a given source
void bfs(vector<vector<int>>& adj, int s, vector<bool>& visited);

// Perform BFS for the entire graph (handles disconnected graphs)
void bfsDisconnected(vector<vector<int>>& adj) {
    vector<bool> visited(adj.size(), false); // Visited vector to track visited nodes

    cout << "BFS Traversal of the entire graph:\n";
    for (int i = 0; i < adj.size(); ++i) {
        if (!visited[i]) {
            bfs(adj, i, visited); // Call BFS for each unvisited node
        }
    }
    cout << endl;
}

// BFS from a given source `s`
void bfs(vector<vector<int>>& adj, int s, vector<bool>& visited) 
{
    queue<int> q; // Queue for BFS

    // Mark the source node as visited and enqueue it
    visited[s] = true;
    q.push(s);

    // Traverse the graph using BFS
    while (!q.empty()) {
        int curr = q.front(); // Dequeue a vertex
        q.pop();
        cout << curr << " "; // Print the current node

        // Get all adjacent vertices of the dequeued vertex
        for (int neighbor : adj[curr]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true; // Mark as visited
                q.push(neighbor);         // Enqueue it
            }
        }
    }
}

// Function to add an edge to the graph
void addEdge(vector<vector<int>>& adj, int u, int v) 
{
    adj[u].push_back(v); // Add edge u -> v
    adj[v].push_back(u); // Add edge v -> u (undirected graph)
}

int main() 
{
    // Take user input for the number of vertices and edges
    cout << "Enter number of nodes (vertices): ";
    int V;
    cin >> V;

    cout << "Enter number of edges: ";
    int E;
    cin >> E;

    // Initialize the adjacency list
    vector<vector<int>> adj(V);

    // Input edges
    cout << "Enter edges (format: u v):\n";
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(adj, u, v); // Add each edge
    }

    // Perform BFS for the entire graph
    bfsDisconnected(adj);

    return 0;
}
