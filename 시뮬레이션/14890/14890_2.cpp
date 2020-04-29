#include <bits/stdc++.h>
using namespace std;

int map_size, L;
int Map[101][101];
bool bridgeX[101][101];
bool bridgeY[101][101];
int total;

// 다리를 놓을 수 있는지 확인.
bool isXUpPossible(int y, int x, int cntLength) {
    // 먼저 다리를 지었거나, 다리를 짓기위한 위치 차이가 1이상 날 경우 false를 반환한다.
    if (bridgeX[y][x] == true || (Map[y][x + L] - cntLength) != 1)
        return false;

    // 중간에 지을 수 있는지 확인
    for (int i = 0; i < L; i++) {
        if (Map[y][x + i] != cntLength) {
            return false;
        }
    }

    // 가능한 경우에 다리를 지어준다.
    for (int i = 0; i < L; i++) {
        bridgeX[y][x + i] = true;
    }
    return true;
}

bool isXDownPossible(int y, int x, int cntLength) {
    int nextLength = Map[y][x + 1];

    // 바로 그 다음칸이 미리 지어졌는지 확인, 차이가 1나는지 확인한다.
    if (bridgeY[y][x + 1] == true || (cntLength - nextLength) != 1)
        return false;

    // 다리를 지을 수 있는지 확인
    for (int i = 1; i <= L; i++) {
        if (Map[y][x + i] != nextLength)
            return false;
    }

    // 만들 수 있는 경우 다리를 지어준다.
    for (int i = 1; i <= L; i++) {
        bridgeX[y][x + i] = true;
    }

    return true;
}

bool isYUpPossible(int y, int x, int cntLength) {
    // 먼저 다리를 지었거나, 다리를 짓기위한 위치 차이가 1이상 날 경우 false를 반환한다.
    if (bridgeY[y][x] == true || (Map[y + L][x] - cntLength) != 1)
        return false;

    // 중간에 지을 수 있는지 확인
    for (int i = 0; i < L; i++) {
        if (Map[y + i][x] != cntLength)
            return false;
    }

    // 가능한 경우에 다리를 지어준다.
    for (int i = 0; i < L; i++) {
        bridgeY[y + i][x] = true;
    }
    return true;
}

bool isYDownPossible(int y, int x, int cntLength) {
    int nextLength = Map[y + 1][x];

    if (bridgeY[y][x + 1] == true || (cntLength - nextLength) != 1)
        return false;

    for (int i = 1; i <= L; i++) {
        if (Map[y + i][x] != nextLength)
            return false;
    }

    for (int i = 1; i <= L; i++) {
        bridgeY[y + i][x] = true;
    }

    return true;
}

int main(void) {
    cin >> map_size >> L;

    for (int i = 0; i < map_size; i++) {
        for (int j = 0; j < map_size; j++) {
            cin >> Map[i][j];
        }
    }

    for (int y = 0; y < map_size; y++) {
        int cntX = 0;
        int cntLength = Map[y][cntX];
        while (cntX <= map_size) {
            if (cntX == map_size) {
                total++;
                break;
            }

            // 유효성 확인
            if (Map[y][cntX] != cntLength)
                break;

            if (cntX + L < map_size) {
                // 위로 향하는 다리를 지을 수 있는가
                bool isUpPossible = isXUpPossible(y, cntX, cntLength);
                // 아래로 향하는 다리를 지을 수 있는가
                bool isDownPossible = isXDownPossible(y, cntX, cntLength);

                // 둘 중 하나가 가능하면 만들어주기
                if (isUpPossible || isDownPossible) {
                    cntLength = Map[y][cntX + L];
                    cntX += L;
                } else {
                    cntX++;  // 다리 만들기가 안된다고 하면 단순하게 그 다음칸으로 이동한다.
                }
            } else {
                cntX++;  // 위치 + L이 범위를 벗어나므로 단순 이동 밖에 못한다.
            }
        }
    }

    for (int x = 0; x < map_size; x++) {
        int cntY = 0;
        int cntLength = Map[cntY][x];
        while (cntY <= map_size) {
            if (cntY == map_size) {
                total++;
                break;
            }
            if (Map[cntY][x] != cntLength)
                break;

            if (cntY + L < map_size) {
                bool isUpPossible = isYUpPossible(cntY, x, cntLength);
                bool isDownPossible = isYDownPossible(cntY, x, cntLength);

                if (isUpPossible || isDownPossible) {
                    cntLength = Map[cntY + L][x];
                    cntY += L;
                } else {
                    cntY++;
                }
            } else {
                cntY++;
            }
        }
    }

    cout << total << '\n';
}