#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;

    while (cin >> str)
    {
        stack <char> s;
        bool ok = true;

        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '(')
            {
                s.push(str[i]);
            }
            else if (str[i] == ')')
            {
                if (s.empty())
                {
                    ok = false;
                    break;
                }

                if (s.top() == '(')
                {
                    s.pop();
                } else {
                    ok = false;
                    break;
                }
            }
        }
        
        if (!s.empty())
        {
            ok = false;
        }

        ok ? cout << "correct" << endl : cout << "incorrect" << endl;
    }

    return 0;
}