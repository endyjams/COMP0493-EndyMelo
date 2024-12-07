#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int t; cin >> t;
    
    while (t--) {
       int n; cin >> n;
       string s; cin >> s;
       int k = (int)s.size();
       int ans = n;
       
       for (int i = 1; (n - (k * i)) > 1; i++) {
           ans *= (n - (k * i));
       }
       
       cout << ans << '\n';
    }
    
    return 0;
}