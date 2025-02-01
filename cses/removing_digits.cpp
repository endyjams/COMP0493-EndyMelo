#include <vector>
#include <iostream>
#include <string>
using namespace std;
const int INF = 1e9;

int main() {
    int n; cin >> n;
    
    vector<int> dp(n+1);
    
    for (int i = 1; i <= n; i++) dp[i] = INF;
    
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        string s = to_string(i);
        
        for (int j = 0; j < (int)s.size(); j++) {
            int numParaSubtrair = s[j] - '0';
            
            dp[i] = min(dp[i], 1 + dp[i - numParaSubtrair]);
        }
    }
    
    cout << dp[n];
}