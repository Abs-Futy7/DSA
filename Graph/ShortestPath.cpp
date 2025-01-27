#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t) {
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;

    // Perform BFS
    queue<int> q;
    q.push(s);
    parent[s] = -1; 
    visited[s] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int neighbor : adj[curr]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true; // Mark as visited
                parent[neighbor] = curr; // Set parent for path reconstruction
                q.push(neighbor);
            }
        }
    }

    // Reconstruct the shortest path
    vector<int> ans;
    int curr = t;
    ans.push_back(t); // Start with the target node
    while (curr != s) {
        curr = parent[curr]; // Move to the parent node
        ans.push_back(curr);
    }

    // Reverse the path to get it from source to target
    reverse(ans.begin(), ans.end());

    return ans;
}

int main() {

    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;
    vector<pair<int, int>> edges;
    cout << "Enter the edges (u v):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }
    int s, t;
    cout << "Enter the source and target nodes: ";
    cin >> s >> t;

    vector<int> result = shortestPath(edges, n, m, s, t);

    cout << "Shortest path from " << s << " to " << t << ":\n";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}