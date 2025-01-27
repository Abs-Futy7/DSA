#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5; 
vector<int> g[N]; 
bool visited[N];  

bool dfs(int vertex, int parent) {
    visited[vertex] = true;  // Mark the current node as visited
    bool isCycle = false;    // Initialize cycle detection flag

    for (int child : g[vertex]) {
        // Skip the edge to the parent node
        if (visited[child] && child == parent) continue;

        // If the child is already visited and it's not the parent, a cycle is found
        if (visited[child]) return true;

        // Recursively call DFS for the child node
        isCycle |= dfs(child, vertex);
    }
    return isCycle; // Return true if a cycle is detected
}

int main() {
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++) {
        int v1, v2;
        cin >> v1 >> v2; 
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    bool isCycle = false;
    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue; // Skip already visited nodes

        // If DFS detects a cycle in any component, set the flag and break
        if (dfs(i, 0)) {
            isCycle = true;
            break;
        }
    }

    cout << isCycle << endl;
    return 0;
}

/*
Example Input:
5 5
1 2
1 3
2 3
3 4
4 5

Explanation:
- Number of nodes = 5
- Number of edges = 5
- Edges: (1-2), (1-3), (2-3), (3-4), (4-5)

Example Output:
1 (There is a cycle)
*/

