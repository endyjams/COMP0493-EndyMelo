#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    
    int curr_case = 1;
    
    while (t--) {
        double x1, y1, x2, y2, x3, y3, x4, y4; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

        double mx1 = (x1 + x3) / 2.0;
        double my1 = (y1 + y3) / 2.0;
        double mx2 = (x2 + x4) / 2.0;
        double my2 = (y2 + y4) / 2.0;

        double m1 = (x3 == x1) ? INFINITY : (y3 - y1) / (x3 - x1);
        double m2 = (x4 == x2) ? INFINITY : (y4 - y2) / (x4 - x2);

        double p1, p2;
        if (m1 == INFINITY) p1 = 0;
        else if (m1 == 0) p1 = INFINITY;
        else p1 = -1.0 / m1;

        if (m2 == INFINITY) p2 = 0;
        else if (m2 == 0) p2 = INFINITY;
        else p2 = -1.0 / m2;

        double bx, by;

        if (p1 == INFINITY) {
            bx = mx1;
            by = p2 * (bx - mx2) + my2;
        } else if (p2 == INFINITY) {
            bx = mx2;
            by = p1 * (bx - mx1) + my1;
        } else {
            bx = (p1 * mx1 - p2 * mx2 + my2 - my1) / (p1 - p2);
            by = p1 * (bx - mx1) + my1;
        }
        
        cout << fixed << setprecision(2) << "Caso #" << curr_case++ << ": " << bx << " " << by << endl;
    }

    return 0;
}
