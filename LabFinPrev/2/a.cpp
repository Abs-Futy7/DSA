#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
public:
    vector<int> parent, rank, size;
    
    // Constructor: Initialize sets
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        for (int i = 1; i <= n; i++) parent[i] = i;
    }

    // Find without path compression
    int findWithoutCompression(int x) {
        if (parent[x] == x) return x;
        return findWithoutCompression(parent[x]); // No path compression
    }

    // Find with path compression
    int findWithCompression(int x) {
        if (parent[x] != x) parent[x] = findWithCompression(parent[x]);
        return parent[x];
    }

    // Union by rank (Without Path Compression)
    void unionByRank(int u, int v) {
        int rootU = findWithoutCompression(u);
        int rootV = findWithoutCompression(v);

        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }

    // Union by size (Without Path Compression)
    void unionBySize(int u, int v) {
        int rootU = findWithoutCompression(u);
        int rootV = findWithoutCompression(v);

        if (rootU != rootV) {
            if (size[rootU] > size[rootV]) {
                parent[rootV] = rootU;
                size[rootU] += size[rootV];
            } else {
                parent[rootU] = rootV;
                size[rootV] += size[rootU];
            }
        }
    }

    // Union with path compression
    void unionWithCompression(int u, int v) {
        int rootU = findWithCompression(u);
        int rootV = findWithCompression(v);

        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }

    // Display parent array
    void displayParent() {
        cout << "Parent Array: ";
        for (int i = 1; i < parent.size(); i++)
            cout << parent[i] << " ";
        cout << endl;
    }
};

int main() {
    int n = 10;
    
    // 1. Without Path Compression
    DisjointSet ds1(n);
    ds1.unionByRank(1, 9);
    ds1.unionByRank(2, 4);
    ds1.unionByRank(4, 5);
    ds1.unionByRank(6, 3);
    ds1.unionByRank(6, 7);
    ds1.unionByRank(6, 8);
    ds1.unionByRank(9, 6);
    cout << "Without Path Compression: ";
    ds1.displayParent();

    // 2. With Path Compression
    DisjointSet ds2(n);
    ds2.unionWithCompression(1, 9);
    ds2.unionWithCompression(2, 4);
    ds2.unionWithCompression(4, 5);
    ds2.unionWithCompression(6, 3);
    ds2.unionWithCompression(6, 7);
    ds2.unionWithCompression(6, 8);
    ds2.unionWithCompression(9, 6);
    cout << "With Path Compression: ";
    ds2.displayParent();

    // 3. Example of Union by Size vs. Union by Rank
    DisjointSet ds3(n);
    ds3.unionBySize(1, 2);
    ds3.unionBySize(3, 4);
    ds3.unionBySize(1, 3);
    cout << "Union by Size: ";
    ds3.displayParent();

    DisjointSet ds4(n);
    ds4.unionByRank(1, 2);
    ds4.unionByRank(3, 4);
    ds4.unionByRank(1, 3);
    cout << "Union by Rank: ";
    ds4.displayParent();

    return 0;
}
