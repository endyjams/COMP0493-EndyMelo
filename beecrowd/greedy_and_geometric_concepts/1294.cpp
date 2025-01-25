#include <bits/stdc++.h>
using namespace std;

int main() {
    double l, w;
    
    while (cin >> l >> w) {
        double max_x = (l + w - sqrt(l * l - l * w + w * w)) / 6;

        cout << fixed << setprecision(3) << max_x << " " << 0.000 << " " << min(l / 2.0, w / 2.0) << endl;
    }
    
    return 0;
}