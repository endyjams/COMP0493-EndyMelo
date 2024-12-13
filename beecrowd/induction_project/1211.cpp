#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int n;
    
    while (cin >> n) {
        vector <string> v(n);
        
        for (int i = 0; i < n; i++) cin >> v[i];
        
        sort(v.begin(), v.end());
        
        int ans = 0;
        
        for (int i = 1; i < n; i++) {
            int j = 0;
            
            while (j < v[i].size() && j < v[i-1].size() && v[i-1][j] == v[i][j]) j++;
            
            ans += j;
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}