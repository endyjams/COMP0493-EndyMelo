#include <bits/stdc++.h>
using namespace std;
bool ok;
int visited[30100];
vector <int> adj[30100];

void init()
{
    ok = false;
    for (int i = 0; i <= 30000; i++) adj[i].clear();
    memset(visited, 0, sizeof(visited));
}

void dfs(int v)
{
    visited[v] = 1;
    
    if (ok) return;
    
    for (int i = 0; i < adj[v].size(); i++)
    {
        int u = adj[v][i];
        
        if (visited[u] == 1)
        {
            ok = true;
            return;
        }
        else if (visited[u] == 0)
        {
            dfs(u);
        }
    }
    
    visited[v] = 2;
}

int main()
{
    int t; cin >> t;
    
    while (t--)
    {
        int n, m; cin >> n >> m;
        
        init();
        
        for (int i = 0; i < m; i++)
        {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
        }
        
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i]) dfs(i);
            if (ok) break;
        }
        
        ok ? cout << "SIM" << endl : cout << "NAO" << endl;
    }
    
    return 0;
}