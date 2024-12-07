#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int n, m;
    
    while (cin >> n >> m && (n && m)) {
        char mat[n][m];
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        
        int newN, newM; cin >> newN >> newM;
        
        char ans[newN][newM];
        
        int facN = newN/n;
        int facM = newM/m;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = i * facN; k < (i + 1) * facN; k++) {
                    for (int l = j * facM; l < (j + 1) * facM; l++) {
                        ans[k][l] = mat[i][j];
                    }
                } 
            }
        }
        
        for (int i = 0; i < newN; i++) {
            for (int j = 0; j < newM; j++) {
                cout << ans[i][j];
            }
            cout << '\n';
        }
        
        cout << '\n';
    }
    
    return 0;
}