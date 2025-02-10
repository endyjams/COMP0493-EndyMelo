#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    map<string, vector<string>> m;
    
    while (t--) {
        string s; cin >> s;
        string previous_string = s;
        
        sort(s.begin(), s.end());
        
        if (m.find(s) != m.end()) {
            m[s].push_back(previous_string);
        } else {
            vector<string> v;
            v.push_back(previous_string);
            m[s] = v;
        }
    }
    
    vector<vector<string>> ans;
    
    for (auto p : m) {
        sort(p.second.begin(), p.second.end());
        ans.push_back(p.second);
    }
    
    sort(ans.begin(), ans.end());
    
    for (vector<string> v : ans) {
        for (int i = 0; i < v.size(); i++) {
           i != v.size() - 1 ? cout << v[i] << " " : cout << v[i] << endl;
        }
    }

    return 0;
}
