#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, b;

    while (true)
    {
        cin >> n >> b;
        
        if (n == 0 && b == 0)
        {
            break;
        }
        
        stack <char> s;

        int apagados = 0;

        for (long long i = n - 1; i >= 0 ; i--)
        {
            char arr;
            cin >> arr;

            while (!s.empty() && arr > s.top() && apagados < b)
            {
                s.pop();
                apagados++;
            }

            if (s.size() < n-b)
            {
                s.push(arr);
            }
        }

        int size = s.size();
        vector <char> ans(size);

        for (int i = size-1; i >= 0; i--)
        {
            ans[i] = s.top();
            s.pop();
        }

        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i];
        }

        cout << endl;
    }

    return 0;
}