#include <vector>
using namespace std;

void dfs(vector<int> adj[], vector<bool> &visited, int currentVertex) {
    visited[currentVertex] = true;

    for (int vizinho : adj[currentVertex]) {
        if (!visited[vizinho]) dfs(adj, visited, vizinho);
    }
}