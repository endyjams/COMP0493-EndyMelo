#include <bits/stdc++.h>
using namespace std;
int n, m;

class cmp
{
    public: bool operator() (int a, int b)
    {
        if (a % m == b % m && ((a % 2 != 0 && b % 2 == 0) || (a % 2 == 0 && b % 2 != 0))) return abs(a % 2) > abs(b % 2);

        if (a % m == b % m && a % 2 != 0 && b % 2 != 0) return a > b;

        if (a % m == b % m && a % 2 == 0 && b % 2 == 0) return a < b;

        return (a%m) < (b%m);
    }
};

int main()
{
    while (cin >> n >> m)
    {
        cout << n << " " << m << endl;
        
        if (n == 0 && m == 0) break;
        
        vector <int> v(n);

        for (int i = 0; i < n; i++) cin >> v[i];

        sort(v.begin(), v.end(), cmp());

        for (int i = 0; i < n; i++)
        {
            cout << v[i] << endl;    
        }
    }

    return 0;
}