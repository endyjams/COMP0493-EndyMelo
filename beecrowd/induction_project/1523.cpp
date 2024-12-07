#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    
    while (cin >> n >> k && (n || k))
    {
        vector <pair<int,int>> v(n);
        priority_queue<pair<int,int>> q;
        
        
        for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
        
        // ordenar pela hora de entrada.
        sort(v.begin(), v.end());
        
        bool canPark = true;
        
        for(int i = 0; i < n; i++) {
            if (q.empty()) {
                q.push({0, v[i].second});
            } else {
                // enquanto a hora de entrada do atual
                // for maior que a hora de saída dos que
                // estão estacionados, pode retirar eles.
                while (v[i].first >= q.top().second && !q.empty()) q.pop();
                
                if (q.empty()) {
                    q.push({0, v[i].second});
                } else if (q.top().second < v[i].second || q.size() > k) {
                    canPark = false;
                    break;
                } else {
                    q.push({q.top().first+1, v[i].second});
                }
            }
        }
        
        canPark ? cout << "Sim" << endl : cout << "Nao" << endl;
    }
    
    return 0;
}