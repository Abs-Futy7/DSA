#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Function to perform BFS traversal from a given source `s`
void bfs(vector<vector<int>>& adj, int s) 
{
    // Create a queue to facilitate BFS
    queue<int> q;  
    
    // Vector to keep track of visited nodes
    vector<bool> visited(adj.size(), false);

    // Mark the source node as visited and enqueue it
    visited[s] = true;
    q.push(s);

    // Continue until the queue is empty
    while (!q.empty()) {
      
        // Dequeue a vertex from the queue and print it
        int curr = q.front();
        q.pop();
        cout << curr << " ";

        // Iterate over all adjacent vertices of the current node
        for (int x : adj[curr]) {
            // If the adjacent vertex has not been visited
            if (!visited[x]) {
                // Mark it as visited and enqueue it
                visited[x] = true;
                q.push(x);
            }
        }
    }
}

// Function to add an edge to the graph
void addEdge(vector<vector<int>>& adj, int u, int v) 
{
    adj[u].push_back(v); // Add v to the adjacency list of u
    adj[v].push_back(u); // Add u to the adjacency list of v (undirected graph)
}

int main() 
{
    // Prompt the user to input the number of nodes (vertices)
    cout << "Enter the number of nodes in the graph: ";
    int V;
    cin >> V;

    // Adjacency list representation of the graph
    vector<vector<int>> adj(V);

    // Prompt the user to input the number of edges
    cout << "Enter the number of edges in the graph: ";
    int E;
    cin >> E;

    // Input edges from the user
    cout << "Enter the edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(adj, u, v);
    }

    // Perform BFS traversal starting from a user-defined source
    cout << "Enter the starting vertex for BFS: ";
    int start;
    cin >> start;

    cout << "BFS starting from vertex " << start << ":\n";
    bfs(adj, start);

    return 0;
}
