#include <bits/stdc++.h>
using namespace std;

int main() {
    int j, r; cin >> j >> r;
    
    vector<pair<int,int>> v(j);
    
    for (int i = 0; i < j; i++) v[i] = {0, i + 1};
    
    for (int i = 0; i < r; i++) {
        for (int k = 0; k < j; k++) {
            int x; cin >> x;
            v[k].first += x;
        }
    }
    
    sort(v.begin(), v.end(), greater<pair<int,int>>());
    
    cout << v[0].second << endl;
    
    return 0;
}