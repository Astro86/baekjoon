#include <bits/stdc++.h>
using namespace std;

int map_size, L;
int Map[101][101];
bool bridgeX[101][101];
bool bridgeY[101][101];
int total;

bool isXUpPossible(int y, int x, int cntLength) {
    if (bridgeX[y][x] == true)
        return false;

    for (int i = 0; i < L; i++) {
        if (Map[y][x + i] != cntLength) {
            return false;
        }
    }

    int cmplevel = Map[y][x + L] - cntLength;

    if (cmplevel != 1) {
        return false;
    }

    for (int i = 0; i < L; i++) {
        bridgeX[y][x + i] = true;
    }
    return true;
}

bool isXDownPossible(int y, int x, int cntLength) {
    if (bridgeY[y][x + 1] == true)
        return false;

    int nextLength = Map[y][x + 1];

    if ((cntLength - nextLength) != 1) {
        return false;
    }

    for (int i = 1; i <= L; i++) {
        if (Map[y][x + i] != nextLength)
            return false;
    }

    for (int i = 1; i <= L; i++) {
        bridgeX[y][x + i] = true;
    }

    return true;
}

bool isYUpPossible(int y, int x, int cntLength) {
    if (bridgeY[y][x] == true)
        return false;

    for (int i = 0; i < L; i++) {
        if (Map[y + i][x] != cntLength)
            return false;
    }

    if ((Map[y + L][x] - cntLength) != 1)
        return false;

    for (int i = 0; i < L; i++) {
        bridgeY[y + i][x] = true;
    }
    return true;
}

bool isYDownPossible(int y, int x, int cntLength) {
    if (bridgeY[y][x + 1] == true)
        return false;

    int nextLength = Map[y + 1][x];

    if ((cntLength - nextLength) != 1) {
        return false;
    }

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

            if (cntX + L < map_size) {
                // 위로가는 경사로를 만들 수 있는가?
                bool isUpPossible = isXUpPossible(y, cntX, cntLength);
                // 아래로가는 경사로를 만들 수 있는가?
                bool isDownPossible = isXDownPossible(y, cntX, cntLength);

                // 둘 중 하나가 가능하면 만들어주기
                if (isUpPossible || isDownPossible) {
                    cntLength = Map[y][cntX + L];
                    cntX += L;
                } else {
                    if (Map[y][cntX] == cntLength)  // 둘 다 불가능 할 경우 현재칸이 유효한지 확인
                        cntX++;
                    else
                        break;  // 현재 칸이 유효하지 못한 경우
                }
            } else {
                if (Map[y][cntX] == cntLength)
                    cntX++;
                else
                    break;
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

            if (cntY + L < map_size) {
                bool isUpPossible = isYUpPossible(cntY, x, cntLength);
                bool isDownPossible = isYDownPossible(cntY, x, cntLength);

                if (isUpPossible || isDownPossible) {
                    cntLength = Map[cntY + L][x];
                    cntY += L;
                } else {
                    if (Map[cntY][x] == cntLength)
                        cntY++;
                    else
                        break;
                }
            } else {
                if (Map[cntY][x] == cntLength)
                    cntY++;
                else
                    break;
            }
        }
    }

    cout << total << '\n';
}