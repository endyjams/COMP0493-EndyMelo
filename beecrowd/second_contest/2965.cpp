#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 1;
int n, k;
bool visited[maxN];
vector<int> depth(maxN, 0);
vector<int> topDownGraph[maxN];
vector<int> bottomUpGraph[maxN];
vector<int> leafs;

bool cmp(int u, int v) {
    return depth[u] > depth[v];
}

void depthCount(int v) {
    visited[v] = true;
    
    if (topDownGraph[v].size() == 0) leafs.push_back(v);
    
    for (int vizinho : topDownGraph[v]) {
        if (!visited[vizinho]) {
            depth[vizinho] = depth[v] + 1;
            depthCount(vizinho);
        }
    }
}

int leafsHeightCount(int v) {
    visited[v] = true;
    
    int ans = 1;
    
    if (v == 1) return ans;
    
    if (!visited[bottomUpGraph[v][0]]) {
        ans += leafsHeightCount(bottomUpGraph[v][0]);
    }

    return ans;
}

int main() {
    cin >> n >> k;
    
    for (int i = 2; i <= n; i++) {
        int u; cin >> u;
        
        topDownGraph[u].push_back(i);
        bottomUpGraph[i].push_back(u);
    }
    
    depth[1] = 0;
    
    depthCount(1);
    
    sort(leafs.begin(), leafs.end(), cmp);
    
    vector<int> leafsHeight;
    
    memset(visited, false, sizeof(visited));
    
    for (int leaf : leafs) if (!visited[leaf]) leafsHeight.push_back(leafsHeightCount(leaf));
    
    int ans = 0;
    
    sort(leafsHeight.begin(), leafsHeight.end(), greater<int>());
    
    for (int i = 0; i < min(k, (int)leafsHeight.size()); i++) ans += leafsHeight[i];
    
    cout << ans << endl;
    
    return 0;
}