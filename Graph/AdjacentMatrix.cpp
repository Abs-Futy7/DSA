#include <iostream>
#include <vector>
using namespace std;

// Function to add an edge between two nodes in the graph
// mat: the adjacency matrix
// i, j: nodes between which the edge is added
void addEdge(vector<vector<int>> &mat, int i, int j)
{
    mat[i][j] = 1;         // Set the edge from node i to node j
    mat[j][i] = 1;         // Since the graph is undirected, also set edge from node j to node i
}

// Function to print the adjacency matrix
// mat: the adjacency matrix to be printed
void print(const vector<vector<int>> &mat)
{
    int V = mat.size();    // Number of nodes in the graph
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int n; // Number of nodes in the graph
    cout << "Enter number of nodes: ";
    cin >> n;

    int e; // Number of edges in the graph
    cout << "Enter number of edges: ";
    cin >> e;

    // Initialize an adjacency matrix of size n x n with all values set to 0
    vector<vector<int>> mat(n, vector<int>(n, 0));

    cout << "Enter the edges (u, v):" << endl;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v; // Input the two nodes that form an edge
        addEdge(mat, u, v); // Add the edge to the graph
    }

    cout << "Adjacency Matrix:" << endl;
    print(mat);

    return 0;
}
