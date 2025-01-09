#include <bits/stdc++.h>
using namespace std;

class cmp
{
    public: bool operator() (string a, string b)
    {
        return a.size() > b.size();
    }
};

int main()
{
    int t; cin >> t;
    
    string line;
    getline(cin, line);

    while (t--)
    {
        getline(cin, line);
        istringstream iss(line);
        string word;
        
        vector <string> v;
        
        while (iss >> word) {
            v.push_back(word);
        }
        
        stable_sort(v.begin(), v.end(), cmp());
        
        for (int i = 0; i < v.size(); i++) {
            i != v.size() - 1 ? cout << v[i] << " " : cout << v[i];
        }
        
        cout << endl;
    }

    return 0;
}