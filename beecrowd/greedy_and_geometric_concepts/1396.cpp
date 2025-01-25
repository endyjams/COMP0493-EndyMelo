#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    int inst = 1;
    
    while (cin >> n >> k) {
        if ((k || n) == false) break;
        
        vector <string> initial_vector(n);
        
        map<string, int> current_position;
        
        for (int i = 0; i < n; i++) {
            cin >> initial_vector[i];
            current_position[initial_vector[i]] = i;
        }
        
        int current_index = 0;
        
        while (!current_position.empty() && k > 0) {
            for (auto p : current_position) {
                int travel_cost = p.second - current_index;
                
                if (travel_cost <= k) {
                    k -= travel_cost;
                    
                    for (int i = p.second; i > current_index; i--) {
                        current_position[initial_vector[i - 1]]++;
                        
                        swap(initial_vector[i], initial_vector[i - 1]);
                    }
                    
                    initial_vector[current_index] = p.first;
                    current_index++;
                    current_position.erase(p.first);
                    break;
                }
            }
        }
        
        printf("Instancia %d", inst++);
        
        cout << endl;
        
        for (string s : initial_vector) cout << s << " ";
        
        cout << endl << endl;
    }
}