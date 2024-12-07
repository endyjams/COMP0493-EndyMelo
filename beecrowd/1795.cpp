#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int ans = 1;
    
    int r; cin >> r;
    
    while (r--) {
     ans *= 3;    
    }
    
    cout << ans << '\n';
    
    return 0;
}