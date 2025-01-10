#include <iostream>
#include <vector>
using namespace std;

class DisjointUnionSets {
    vector<int> rank, parent;

public:
  
    // Constructor to initialize sets
    DisjointUnionSets(int n) {
        rank.resize(n, 0);
        parent.resize(n);

        // Initially, each element is in its own set
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // Find the representative of the set that x belongs to
    int find(int x) {
        if (parent[x] != x) {
          
            // Path compression
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // Union of sets containing x and y
    void unionSets(int x, int y) {
        int xRoot = find(x);
        int yRoot = find(y);

        // If they are in the same set, no need to union
        if (xRoot == yRoot) return;

        // Union by rank
        if (rank[xRoot] < rank[yRoot]) {
            parent[xRoot] = yRoot;
        } else if (rank[yRoot] < rank[xRoot]) {
            parent[yRoot] = xRoot;
        } else {
            parent[yRoot] = xRoot;
            rank[xRoot]++;
        }
    }
};

int main() {
    // Let there be 5 persons with ids 0, 1, 2, 3, and 4
    int n = 5;
    DisjointUnionSets dus(n);

    // 0 is a friend of 2
    dus.unionSets(0, 2);

    // 4 is a friend of 2
    dus.unionSets(4, 2);

    // 3 is a friend of 1
    dus.unionSets(3, 1);

    // Check if 4 is a friend of 0
    if (dus.find(4) == dus.find(0))
        cout << "Yes\n";
    else
        cout << "No\n";

    // Check if 1 is a friend of 0
    if (dus.find(1) == dus.find(0))
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}