#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef pair<ld,ld> pld;
ld INF = 1e6;

class cmp{
    public: bool operator() (pld p1, pld p2)
    {
        if (abs(p1.second-p2.second) > abs(p1.first-p2.first)) return p1.second < p2.second;
        return p1.first < p2.first;
    }
};

ld eu_dist(ld x1, ld x2, ld y1, ld y2)
{
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main()
{
    int n;
    
    while (cin >> n && n)
    {
        vector <pld> v(n);
        
        for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
        
        sort(v.begin(), v.end(), cmp());
        
        ld ans = INF;
        
        for (int i = 0; i < n-1; i++)
        {
            ld k = eu_dist(v[i].first, v[i+1].first, v[i].second, v[i+1].second);
            
            for (int j = i+2; j < n; j++)
            {
                ld x = eu_dist(v[i].first, v[j].first, v[i].second, v[j].second);
                
                if (k > x) k = x;
                else break;
            }
            
            if (ans > k) ans = k;
        }
        
        ans < 10000.00 ? cout << fixed << setprecision(4) << ans << endl : cout << "INFINITY" << endl;
    }
    
    return 0;
}