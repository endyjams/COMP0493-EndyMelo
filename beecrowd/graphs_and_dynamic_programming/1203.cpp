#include <bits/stdc++.h>
using namespace std;
int grau[101];
int dp[101][10010];
int r, k;
bool ok;

int solve(int reg, int rest)
{
    if (ok) return 1;
    if (reg > r || rest < 0) return 0;
    if (rest == 0)
    {
        ok = true;
        
        return dp[reg][rest] = 1;
    }
    if(dp[reg][rest] != -1) return dp[reg][rest];
    
    return dp[reg][rest] = solve(reg+1, rest) || solve(reg+1, rest-grau[reg]);
}

int main()
{
    while (cin >> r >> k)
    {
        ok = false;
        memset(grau, 0, sizeof(grau));
        
        for (int i = 1; i <= r; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                dp[i][j] = -1;
            }
        }
        
        for (int i = 0; i < k; i++)
        {
            int u, v; cin >> u >> v;
            grau[u]++;
            grau[v]++;
        }
        
        solve(1, k) ? cout << "S" << endl : cout << "N" << endl;
    }
    
    return 0;
}