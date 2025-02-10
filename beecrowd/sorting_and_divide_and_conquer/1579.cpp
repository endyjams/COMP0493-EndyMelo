#include <bits/stdc++.h>
using namespace std;
int n, c, f;
int v[101];

bool solve(int lim)
{
    int p = 1, sum = 0;
    
    for (int i = 0; i < n; i++)
    {
        if (sum+v[i] <= lim)
        {
            sum += v[i];
        } else {
            sum = v[i];
            p++;
        }
    }
    
    return p <= c ? true : false;
}

int main()
{
    int t; cin >> t;
    
    while (t--)
    {
        cin >> n >> c >> f;
        int l = 0, r = 0, m;
        
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            r += v[i];
            l = max(l, v[i]);
        }
        
        while (l < r)
        {
            m = (l+r)/2;
            
            if (solve(m))
            {
                r = m;
            } else {
                l = m+1;
            }
        }
        
        printf("%d $%d\n", l, l*c*f);
    }
    
    return 0;
}