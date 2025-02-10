#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, c;
    cin >> n >> c;
    int v[200001];
    for (int i = 0; i < n; i++) cin >> v[i];
    
    ll dp[200002][2];
    dp[n][0] = dp[n][1] = 0;
    
    for (int idx = n - 1; idx >= 0; idx--) {
        dp[idx][1] = max(v[idx] + dp[idx+1][0], dp[idx+1][1]);
        dp[idx][0] = max(dp[idx+1][0], dp[idx+1][1] - (v[idx] + c));
    }
    
    cout << dp[0][0] << "\n";
    return 0;
}