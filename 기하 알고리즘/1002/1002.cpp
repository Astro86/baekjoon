#include <cmath>
#include <iostream>
using namespace std;

int T;

int main(void) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        int x1, x2, y1, y2, r1, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        double dist = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        if (r1 < r2) {
            swap(r1, r2);
        }

        if (dist <= r1) {
            if (x1 == x2 && y1 == y2 && r1 == r2)
                cout << -1 << '\n';
            else if (r2 + dist == r1)
                cout << 1 << "\n";
            else if (r2 + dist > r1)
                cout << 2 << "\n";
            else if (r2 + dist < r1)
                cout << 0 << "\n";
        } else {
            if (r2 + r1 < dist)
                cout << 0 << "\n";
            else if (r2 + r1 > dist)
                cout << 2 << "\n";
            else if (r2 + r1 == dist)
                cout << 1 << "\n";
        }
    }

    return 0;
}