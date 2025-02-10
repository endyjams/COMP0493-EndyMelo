#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, h;

    while (cin >> n >> h) {
        vector<pair<int, int>> tasks;

        for (int i = 0; i < n; i++) {
            int v, t;
            cin >> v >> t;
            tasks.push_back({v, t});
        }

        sort(tasks.rbegin(), tasks.rend());

        vector<bool> used(h + 1, false);
        int lost_value = 0;

        for (auto [v, t] : tasks) {
            for (int j = min(h, t); j >= 1; j--) {
                if (!used[j]) {
                    used[j] = true;
                    v = 0;
                    break;
                }
            }
            
            lost_value += v;
        }

        cout << lost_value << endl;
    }

    return 0;
}
