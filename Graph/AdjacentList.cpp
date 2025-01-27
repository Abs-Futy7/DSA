#include <iostream>
#include <vector>
using namespace std;

// Function to add an edge between two nodes in the adjacency list
void addEdge(vector<vector<int>> &adj, int i, int j) {
    adj[i].push_back(j); // Add node j to the adjacency list of node i
    adj[j].push_back(i); // Add node i to the adjacency list of node j (for an undirected graph)
}

// Function to print the adjacency list representation of the graph
void print(vector<vector<int>> &adj) {
    for (int i = 0; i < adj.size(); i++) { // Iterate through each node
        cout << i << "-> "; // Print the node number
        for (int j : adj[i]) { // Print all the adjacent nodes
            cout << j << " ";
        }
        cout << endl; // Move to the next line after printing the adjacency list of a node
    }
}

int main() {
    int n; // Number of nodes
    cout << "Enter number of nodes: ";
    cin >> n;

    int e; // Number of edges
    cout << "Enter number of edges: ";
    cin >> e;

    // Initialize an adjacency list of size 'n'
    vector<vector<int>> adj(n);

    cout << "Enter the edges (u, v):" << endl;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v; // Input the two nodes that form an edge
        addEdge(adj, u, v); // Add the edge to the graph
    }

    // Print the adjacency list to represent the graph
    cout << "Adjacency List:" << endl;
    print(adj);

    return 0;
}
