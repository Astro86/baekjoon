#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n;
long long totalNum;
int map[33][33];

struct pipe {
    int headY;
    int headX;

    // 0 : 가로, 1 : 세로, 2 : 대각선
    int state;
};

void moveHorizon(int y, int x, queue<pipe>& q) {
    int nextY = y;
    int nextX = x + 1;
    if (nextY == n - 1 && nextX == n - 1) {
        totalNum++;
        return;
    }

    if (0 <= nextY && nextY < n && 0 <= nextX && nextX < n) {
        if (map[nextY][nextX] == 0) {
            q.push({nextY, nextX, 0});
        }
    }
}

void moveVertical(int y, int x, queue<pipe>& q) {
    int nextY = y + 1;
    int nextX = x;

    if (nextY == n - 1 && nextX == n - 1) {
        totalNum++;
        return;
    }

    if (0 <= nextY && nextY < n && 0 <= nextX && nextX < n) {
        if (map[nextY][nextX] == 0) {
            q.push({nextY, nextX, 1});
        }
    }
}

void moveDiagonal(int y, int x, queue<pipe>& q) {
    int nextY = y + 1;
    int nextX = x + 1;

    if (nextY == n - 1 && nextX == n - 1) {
        totalNum++;
        return;
    }

    if (0 <= nextY && nextY < n && 0 <= nextX && nextX < n) {
        if (map[nextY][nextX] == 0 && map[nextY][x] == 0 && map[y][nextX] == 0) {
            q.push({nextY, nextX, 2});
        }
    }
}

int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    queue<pipe> q;
    q.push({0, 1, 0});

    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            int cntY = q.front().headY;
            int cntX = q.front().headX;
            int cntState = q.front().state;
            q.pop();

            // cout << cntY << " " << cntX << endl;

            if (cntState == 0) {
                moveHorizon(cntY, cntX, q);
                moveDiagonal(cntY, cntX, q);
            }

            if (cntState == 1) {
                moveVertical(cntY, cntX, q);
                moveDiagonal(cntY, cntX, q);
            }

            if (cntState == 2) {
                moveHorizon(cntY, cntX, q);
                moveVertical(cntY, cntX, q);
                moveDiagonal(cntY, cntX, q);
            }
        }
        // cout << endl;
    }

    cout << totalNum << '\n';
    return 0;
}