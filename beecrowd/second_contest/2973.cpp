#include <bits/stdc++.h>
using namespace std;
vector<int> v(100005);
int n, c, t;

bool isSolvable(int currTime) {
    int competidores = 1;
    int res = 0, sum = 0;
    
    for (int i = 0; i < n; i++) {
        sum += v[i];
        res = sum % t ? 1 : 0;
        
        if (sum / t + res > currTime) {
            competidores++;
            sum = v[i];
            res = sum % t ? 1 : 0;
        }
        
        if (competidores > c || res + sum / t > currTime) return false;
    }
    
    return true;
}

int main() {
    cin >> n >> c >> t;
    
    for (int i = 0; i < n; i++) cin >> v[i];
    
    int l = 0, r = 1e9, m;
    
    while (l < r) {
        m = (l + r) / 2;
        
        if (isSolvable(m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    
    cout << l << endl;
    
    return 0;
}