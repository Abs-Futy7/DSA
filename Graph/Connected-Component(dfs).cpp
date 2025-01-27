#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5; 
vector<int> g[N]; 
bool visited[N]; 

void dfs(int vertex) {
    
    visited[vertex] = true;  

    for (int child : g[vertex]) {
        
        if (visited[child]) continue;  
        dfs(child); 
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

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if(visited[i]) continue;
        dfs(i);
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}
