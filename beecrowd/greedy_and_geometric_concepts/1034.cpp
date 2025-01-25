#include <bits/stdc++.h>
using namespace std;
const int INF = 1e6;
int dp[1000010];
int n, m;

int main()
{
    int t; cin >> t;
    
    while (t--)
    {
        cin >> n >> m;
        vector <int> v(n);
        
        for (int i = 0; i < n; i++) cin >> v[i];
        
        memset(dp, INF, sizeof(dp));
        
        dp[0] = 0;
        
        for (int i = 0; i < n; i++)
        {
            for (int j = v[i]; j <= m; j++)
            {
                dp[j] = min(dp[j], 1+dp[j-v[i]]);
            }
        }
        
        cout << dp[m] << endl;
    }

    return 0;
}