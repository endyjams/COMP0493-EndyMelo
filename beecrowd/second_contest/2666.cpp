#include <bits/stdc++.h>
using namespace std;
long long distanciaTotal = 0;
int capacidade, n;
vector<int> impostos(10005);
vector<pair<int,int>> adj[10005];


int dfs(int vertice, int pai) {
    int custoTotal = impostos[vertice];
    
    for (pair<int,int> p : adj[vertice]) {
        int vizinho = p.first;
        int peso = p.second;
        
        if (vizinho == pai) continue;
        
        int custoVizinhos = dfs(vizinho, vertice);
        
        int viagens = ceil((double)custoVizinhos / capacidade);
        
        distanciaTotal += 2 * viagens * peso;
        
        custoTotal += custoVizinhos;
    }
    
    return custoTotal;
}

int main() {
    cin >> n >> capacidade;
    
    for (int i = 1; i <= n; i++) cin >> impostos[i];
    
    for (int i = 0; i < n - 1; i++) {
        int u, v, w; cin >> u >> v >> w;
        
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    dfs(1, -1);
    
    cout << distanciaTotal << endl;
    
    return 0;
}