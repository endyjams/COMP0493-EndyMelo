#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int t; cin >> t;
    
    while (t--) {
        int n; cin >> n;
        
        vector<vector<int>> v(n+1);
        
        for (int i = 0; i < n; i++) {
            int t, p; cin >> t >> p;
            
            v[t].push_back(p);
        }
        
        int ans = 0;
        
        for (int i = 1; i <= n; i++) {
            int choseOne = -1;
            
            sort(v[i].begin(), v[i].end(), greater<int>());
            
            for (int j : v[i]) {
                if (j <= 100 && j >= 10) {
                    choseOne = j;
                    break;
                }
            }
            
            if (!v[i].empty()) {
                ans += (choseOne != -1 ? choseOne : v[i][0]);
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}