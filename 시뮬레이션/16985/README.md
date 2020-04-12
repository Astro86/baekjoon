# 백준 16985 - Maaaaaaaaaze

![](16985.jpeg)

## 채점 현황
![](16985_score.png)

## 전체 소스 코드
```cpp
#include <iostream>
#include <queue>
using namespace std;

#define endl '\n'
#define INF 987654321

int maze[5][5][5];
int copyMaze[5][5][5];
int dz[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dx[6] = {0, 0, 0, 0, 1, -1};
int minValue = 987654321;

struct point {
    int z;
    int y;
    int x;
    int num;
};

void rotationMaze(int z) {
    int temp[2][5];

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 5; j++) {
            temp[i][j] = copyMaze[z][i][j];
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 5; j++) {
            copyMaze[z][i][4 - j] = copyMaze[z][j][i];
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 2; j++) {
            copyMaze[z][i][1 - j] = copyMaze[z][3 + j][i];
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 2; j++) {
            copyMaze[z][3 + j][i] = copyMaze[z][4 - i][3 + j];
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 2; j++) {
            copyMaze[z][i][4 - j] = temp[j][i];
        }
    }
}

void escape() {
    queue<point> q;
    bool check[5][5][5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                check[i][j][k] = false;
            }
        }
    }
    q.push({4, 0, 0, 0});
    check[4][0][0] = true;

    while (!q.empty()) {
        int cntZ = q.front().z;
        int cntY = q.front().y;
        int cntX = q.front().x;
        int cntNum = q.front().num;
        q.pop();

        if (cntZ == 0 && cntY == 4 && cntX == 4) {
            if (minValue > cntNum) {
                minValue = cntNum;
            }
        }

        for (int i = 0; i < 6; i++) {
            int nz = cntZ + dz[i];
            int ny = cntY + dy[i];
            int nx = cntX + dx[i];

            if (0 <= nz && nz < 5 && 0 <= ny && ny < 5 && 0 <= nx && nx < 5) {
                if (copyMaze[nz][ny][nx] == 1 && check[nz][ny][nx] == false) {
                    check[nz][ny][nx] = true;
                    q.push({nz, ny, nx, cntNum + 1});
                }
            }
        }
    }
}

bool check[5];
int arr[5];
int arrNum = 0;
vector<vector<int>> v(120);
void makeFactorial(int index, int num) {
    if (num == 5) {
        for (int i = 0; i < 5; i++) {
            v[arrNum].push_back(arr[i]);
        }
        arrNum++;
        return;
    }

    for (int i = 0; i < 5; i++) {
        if (check[i] == false) {
            arr[index] = i;
            check[i] = true;
            makeFactorial(index + 1, num + 1);
            check[i] = false;
        }
    }
}

int main(void) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                cin >> maze[i][j][k];
            }
        }
    }

    makeFactorial(0, 0);

    for (int i = 0; i < 120; i++) {
        for (int mz = 0; mz < 5; mz++) {
            int cntH = v[i][mz];

            for (int my = 0; my < 5; my++) {
                for (int mx = 0; mx < 5; mx++) {
                    copyMaze[mz][my][mx] = maze[cntH][my][mx];
                }
            }
        }

        for (int a = 0; a < 4; a++) {
            rotationMaze(4);
            if (copyMaze[4][0][0] == 0) {
                continue;
            }
            for (int b = 0; b < 4; b++) {
                rotationMaze(3);
                for (int c = 0; c < 4; c++) {
                    rotationMaze(2);
                    for (int d = 0; d < 4; d++) {
                        rotationMaze(1);
                        for (int e = 0; e < 4; e++) {
                            rotationMaze(0);

                            if (copyMaze[0][4][4] == 0) {
                                continue;
                            }

                            escape();
                        }
                    }
                }
            }
        }
    }

    if (minValue == INF) {
        cout << -1 << endl;
    } else {
        cout << minValue << endl;
    }
    return 0;
}
```