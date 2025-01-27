#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5; // Maximum number of vertices in the graph
vector<int> g[N]; // Adjacency list to store the graph
bool visited[N];  // Array to keep track of visited vertices

void dfs(int vertex) {
    
    visited[vertex] = true;  // Mark the current vertex as visited

    for (int child : g[vertex]) {
        
        if (visited[child]) continue;  // If the child vertex is already visited, skip it
        dfs(child);  // Recursively call DFS for the child vertex
    }
}

int main() {
    int n, e, start;
    cin >> n >> e;
    for (int i = 0; i < e; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    // Initialize visited array to false for all vertices
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }
    cout << "enter starting point : ";
    cin >> start;
    dfs(start);

    for (int i = 1; i <= n; i++) {
        if (visited[i]) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}
