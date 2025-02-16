#include <vector>
#include <queue>
using namespace std;

void bfs(vector<int> adj[], vector<bool> &visited, int startingVertex) {
    queue<int> q;

    q.push(startingVertex);

    while (!q.empty()) {
        int currentVertex = q.front();
        q.pop();

        visited[currentVertex] = true;

        for (int vizinho : adj[currentVertex]) if (!visited[vizinho]) q.push(vizinho);
    }
}