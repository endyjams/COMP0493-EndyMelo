#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    
    while(cin >> m >> n && (m || n)) {
        vector<int> lista(m);
        
        for (int i = 0; i < m; i++) cin >> lista[i];
        
        vector<pair<int, double>> produtos(n);
        for (int i = 0; i < n; i++){
            int id;
            double preco;
            cin >> id >> preco;
            produtos[i] = {id, preco};
        }
        
        const double INF = 1e18;

        vector<double> dp(m + 1, INF);
        dp[0] = 0.0;
        

        for (int i = 0; i < n; i++){
            int id = produtos[i].first;
            double preco = produtos[i].second;
            
            for (int j = m - 1; j >= 0; j--) {
                if(dp[j] != INF && lista[j] == id){
                    dp[j + 1] = min(dp[j + 1], dp[j] + preco);
                }
            }
        }
        
        dp[m] == INF ? cout << "Impossible" << endl : cout << fixed << setprecision(2) << dp[m] << endl;
    }
    
    return 0;
}
