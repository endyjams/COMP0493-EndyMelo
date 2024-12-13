#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int main()
{
    int n, cse = 1;

    while (cin >> n && n)
    {
        vector <pii> v(n);
        int sum = 0, pessoas = 0;
        unordered_map <int,int> m;

        for (int i = 0; i < n; i++)
        {
            cin >> v[i].second >> v[i].first;
            sum += v[i].first;
            pessoas += v[i].second;
            v[i].first /= v[i].second;
            m[v[i].first] += v[i].second;
        }
        
        sort(v.begin(), v.end());

        printf("Cidade# %d:\n", cse++);
        
        bool flag = false;

        for (int i = 0; i < n; i++)
        {
            if (m.find(v[i].first) != m.end() && !flag)
            {
                printf("%d-%d", m[v[i].first], v[i].first);
                flag = true;
            }
            else if (m.find(v[i].first) != m.end() && flag)
            {
                printf(" %d-%d", m[v[i].first], v[i].first);
            }
            m.erase(v[i].first);
        }
        
        cout << endl;
        
        double x = ((double)sum / pessoas) * 100;
        int h = x;
        x = h / 100.0;
        
        printf("Consumo medio: %.2lf m3.\n\n", x);
    }

    return 0;
}