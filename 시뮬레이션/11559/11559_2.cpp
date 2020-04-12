#include <iostream>
#include <queue>
using namespace std;

char map[12][6];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int totalCount = 0;
bool isRemoved = false;

void moveDown() {
    for (int i = 10; i >= 0; i--) {
        for (int j = 0; j < 6; j++) {
            int cntLine = i;
            if (map[cntLine][j] != '.') {
                while (map[cntLine + 1][j] == '.' && cntLine <= 10) {
                    map[cntLine + 1][j] = map[cntLine][j];
                    map[cntLine][j] = '.';
                    cntLine++;
                }
            }
        }
    }
}

void explore(int i, int j, char color) {
    bool check[12][6];
    int num = 1;

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            check[i][j] = false;
        }
    }
    check[i][j] = true;

    queue<pair<int, int>> q;
    queue<pair<int, int>> rm;
    q.push({i, j});
    rm.push({i, j});

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (0 <= ny && ny < 12 && 0 <= nx && nx < 6) {
                if (map[ny][nx] == color && check[ny][nx] == false) {
                    num++;
                    check[ny][nx] = true;
                    q.push({ny, nx});
                    rm.push({ny, nx});
                }
            }
        }
    }

    if (num >= 4) {
        isRemoved = true;

        while (!rm.empty()) {
            int y = rm.front().first;
            int x = rm.front().second;
            rm.pop();

            map[y][x] = '.';
        }
    }
}

int main(void) {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> map[i][j];
        }
    }

    while (true) {
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 6; j++) {
                if (map[i][j] != '.') {
                    explore(i, j, map[i][j]);
                }
            }
        }

        if (isRemoved == false) {
            break;
        } else {
            totalCount++;
            moveDown();
        }

        isRemoved = false;
    }

    cout << totalCount << '\n';
    return 0;
}