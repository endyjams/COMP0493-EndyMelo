#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    
    while (cin >> n >> m) {
        vector <pair<int, int>> v;
        
        for (int i = 0; i < n; i++) {
            int a, b; cin >> a >> b;
            v.push_back({a, b});
        }
        
        vector<int> dp(m + 1, -1e9);
        dp[0] = 0;
        
        for (int i = 0; i < n; i++) {
            int latas = v[i].first;
            int valor = v[i].second;
            
            for (int j = latas; j <= m; j++) {
                if (dp[j - v[i].first] == -1e9) continue;
                
                dp[j] = max(dp[j - v[i].first] + valor, dp[j]);
            }
        }
        
        cout << dp[m] << endl;
    }
    
    return 0;
}