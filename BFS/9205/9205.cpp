#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int t;
int n;
int houseX, houseY;
int convenX[101];
int convenY[101];
int festiX, festiY;
int dx[4] = {50, -50, 0, 0};
int dy[4] = {0, 0, 50, -50};
int minX, minY, maxX, maxY;

struct point {
    int x;
    int y;
    int beer;
};

int dis(int tempX, int tempY) {
    return abs(houseX - tempX) + abs(houseY - tempY);
}

int main(void) {
    cin >> t;

    while (t--) {
        cin >> n;

        cin >> houseX >> houseY;
        for (int i = 0; i < n; i++) {
            cin >> convenX[i] >> convenY[i];
        }
        cin >> festiX >> festiY;

        if (houseX < festiX) {
            minX = houseX;
            maxX = festiX;
        } else {
            minX = festiX;
            maxX = houseX;
        }

        if (houseY < festiY) {
            minY = houseY;
            maxY = festiY;
        } else {
            minY = festiY;
            maxX = houseY;
        }

        vector<bool> check(140000, false);

        queue<point> q;
        q.push({houseX, houseY, 20});
        check[dis(houseX, houseY)] = true;

        bool isFail = true;
        while (!q.empty()) {
            int x = q.front().x;
            int y = q.front().y;
            int beer = q.front().beer;
            q.pop();

            for (int i = 0; i < n; i++) {
                if (x == convenX[i] && y == convenY[i]) {
                    // cout << x << " " << y << endl;
                    beer = 20;
                }
            }

            if (x == festiX && y == festiY) {
                isFail = false;
                break;
            }

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (minX <= nx && nx <= maxX && minY <= ny && ny <= maxY) {
                    if (check[nx - minX][ny - minY] == false && beer > 0) {
                        check[nx - minX][ny - minY] = true;
                        q.push({nx, ny, beer - 1});
                    }
                }
            }
        }

        if (isFail) {
            cout << "sad" << '\n';
        } else {
            cout << "happy" << '\n';
        }
    }

    return 0;
}