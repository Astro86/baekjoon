# 미네랄

```cpp
#include <iostream>
#include <queue>
using namespace std;

int r, c;
char map[110][110];
vector<vector<int>> mapNumber;
int n;
int remove_hiehgt[101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int area0 = 0;
int totalArea = 0;

void removeLeft(int height) {
    int left = 0;
    while (map[height][left] == '.' && left < c) {
        left++;
    }
    map[height][left] = '.';
}

void removeRight(int height) {
    int right = c - 1;
    while (map[height][right] == '.' && right >= 0) {
        right--;
    }

    map[height][right] = '.';
}

void bfs(int y, int x, int number) {
    queue<pair<int, int>> q;

    q.push({y, x});
    mapNumber[y][x] = number;

    while (!q.empty()) {
        int cntY = q.front().first;
        int cntX = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cntY + dy[i];
            int nx = cntX + dx[i];

            if (0 <= ny && ny < r && 0 <= nx && nx < c) {
                if (map[ny][nx] == 'x' && mapNumber[ny][nx] == 0) {
                    mapNumber[ny][nx] = number;
                    q.push({ny, nx});
                }
            }
        }
    }
}

void moveDown() {
    int cntNum = totalArea;
    queue<pair<int, int>> q;

    for (int j = r - 1; j >= 0; j--) {
        for (int k = 0; k < c; k++) {
            if (mapNumber[j][k] == cntNum) {
                q.push({j, k});
            }
        }
    }

    bool isPossible = true;
    bool isDown = false;

    while (!q.empty()) {
        int q_size = q.size();
        while (q_size--) {
            int cntY = q.front().first;
            int cntX = q.front().second;
            q.pop();

            int downY = cntY + 1;

            if (downY == r) {
                isDown = true;
                break;
            }

            if (0 <= downY && downY < r) {
                if (mapNumber[downY][cntX] != 0 && mapNumber[downY][cntX] != cntNum) {
                    isPossible = false;
                    break;
                }

                q.push({cntY, cntX});
            }
        }

        if (isDown) {
            break;
        }

        if (!isPossible) {
            break;
        }

        int point_size = q.size();
        while (point_size--) {
            int cntY = q.front().first;
            int cntX = q.front().second;
            q.pop();

            int downY = cntY + 1;
            if (downY == r - 1) {
                isDown = true;
            }

            swap(map[cntY][cntX], map[downY][cntX]);
            q.push({downY, cntX});
        }
    }
}

void numberArea() {
    mapNumber = vector<vector<int>>(r + 1, vector<int>(c + 1, 0));

    int number = 0;
    for (int i = 0; i < c; i++) {
        if (mapNumber[r - 1][i] == 0 && map[r - 1][i] == 'x') {
            number++;
            bfs(r - 1, i, number);
        }
    }
    area0 = number;

    for (int i = r - 1; i >= 0; i--) {
        for (int j = c - 1; j >= 0; j--) {
            if (mapNumber[i][j] == 0 && map[i][j] == 'x') {
                number++;
                bfs(i, j, number);
            }
        }
    }
    totalArea = number;

    if (totalArea != area0) {
        moveDown();
    }
}

int main(void) {
    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> map[i][j];
        }
    }

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> remove_hiehgt[i];
    }

    for (int i = 0; i < n; i++) {
        int height = r - remove_hiehgt[i];

        if (i % 2 == 0) {
            removeLeft(height);
        } else {
            removeRight(height);
        }
        numberArea();
    }

    for (int j = 0; j < r; j++) {
        for (int k = 0; k < c; k++) {
            cout << map[j][k] << "";
        }
        cout << endl;
    }
    cout << endl;
}
```