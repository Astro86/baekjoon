#include <iostream>
#include <queue>
using namespace std;

int N, M;
char map[11][11];
struct marble {
    int ry;
    int rx;
    int by;
    int bx;
    int num;
};
queue<marble> q;

bool check[11][11][11][11];
bool escape_red = false;
bool escape_blue = false;

marble moveLeft(int ry, int rx, int by, int bx, int num) {
    int redY = ry;
    int redX = rx;
    int blueY = by;
    int blueX = bx;

    if (redX < blueX) {
        while (map[redY][redX - 1] != '#') {
            redX--;
            if (map[redY][redX] == 'O') {
                escape_red = true;
                break;
            }
        }

        while (map[blueY][blueX - 1] != '#') {
            blueX--;
            if (map[blueY][blueX] == 'O') {
                escape_blue = true;
                break;
            }
            if (redY == blueY && redX == blueX) {
                blueX++;
                break;
            }
        }

    } else {
        while (map[blueY][blueX - 1] != '#') {
            blueX--;
            if (map[blueY][blueX] == 'O') {
                escape_blue = true;
                break;
            }
        }

        while (map[redY][redX - 1] != '#') {
            redX--;
            if (map[redY][redX] == 'O') {
                escape_red = true;
                break;
            }
            if (redY == blueY && redX == blueX) {
                redX++;
                break;
            }
        }
    }

    return {redY, redX, blueY, blueX, num + 1};
}

marble moveRight(int ry, int rx, int by, int bx, int num) {
    int redY = ry;
    int redX = rx;
    int blueY = by;
    int blueX = bx;

    if (redX < blueX) {
        while (map[blueY][blueX + 1] != '#') {
            blueX++;
            if (map[blueY][blueX] == 'O') {
                escape_blue = true;
                break;
            }
        }

        while (map[redY][redX + 1] != '#') {
            redX++;
            if (map[redY][redX] == 'O') {
                escape_red = true;
                break;
            }

            if (redY == blueY && redX == blueX) {
                redX--;
                break;
            }
        }

    } else {
        while (map[redY][redX + 1] != '#') {
            redX++;
            if (map[redY][redX] == 'O') {
                escape_red = true;
                break;
            }
        }

        while (map[blueY][blueX + 1] != '#') {
            blueX++;
            if (map[blueY][blueX] == 'O') {
                escape_blue = true;
                break;
            }

            if (redY == blueY && redX == blueX) {
                blueX--;
                break;
            }
        }
    }
    return {redY, redX, blueY, blueX, num + 1};
}

marble moveUp(int ry, int rx, int by, int bx, int num) {
    int redY = ry;
    int redX = rx;
    int blueY = by;
    int blueX = bx;

    if (redY < blueY) {
        while (map[redY - 1][redX] != '#') {
            redY--;
            if (map[redY][redX] == 'O') {
                escape_red = true;
                break;
            }
        }

        while (map[blueY - 1][blueX] != '#') {
            blueY--;
            if (map[blueY][blueX] == 'O') {
                escape_blue = true;
                break;
            }
            if (redY == blueY && redX == blueX) {
                blueY++;
                break;
            }
        }

    } else {
        while (map[blueY - 1][blueX] != '#') {
            blueY--;
            if (map[blueY][blueX] == 'O') {
                escape_blue = true;
                break;
            }
        }

        while (map[redY - 1][redX] != '#') {
            redY--;
            if (map[redY][redX] == 'O') {
                escape_red = true;
                break;
            }
            if (redY == blueY && redX == blueX) {
                redY++;
                break;
            }
        }
    }

    return {redY, redX, blueY, blueX, num + 1};
}

marble moveDown(int ry, int rx, int by, int bx, int num) {
    int redY = ry;
    int redX = rx;
    int blueY = by;
    int blueX = bx;

    if (redY < blueY) {
        while (map[blueY + 1][blueX] != '#') {
            blueY++;
            if (map[blueY][blueX] == 'O') {
                escape_blue = true;
                break;
            }
        }

        while (map[redY + 1][redX] != '#') {
            redY++;
            if (map[redY][redX] == 'O') {
                escape_red = true;
                break;
            }
            if (redY == blueY && redX == blueX) {
                redY--;
                break;
            }
        }

    } else {
        while (map[redY + 1][redX] != '#') {
            redY++;
            if (map[redY][redX] == 'O') {
                escape_red = true;
                break;
            }
        }

        while (map[blueY + 1][blueX] != '#') {
            blueY++;

            if (map[blueY][blueX] == 'O') {
                escape_blue = true;
                break;
            }

            if (redY == blueY && redX == blueX) {
                blueY--;
                break;
            }
        }
    }
    return {redY, redX, blueY, blueX, num + 1};
}

int main(void) {
    cin >> N >> M;
    int redY, redX, blueY, blueX;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];

            if (map[i][j] == 'R') {
                redY = i;
                redX = j;
                map[i][j] = '.';
            }

            if (map[i][j] == 'B') {
                blueY = i;
                blueX = j;
                map[i][j] = '.';
            }
        }
    }

    q.push({redY, redX, blueY, blueX, 0});
    check[redY][redX][blueY][blueX] = true;

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++) {
    //         cout << map[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << redY << " " << redX << " " << blueY << " " << blueX << endl;
    // cout << endl;

    // marble m = moveRight(redY, redX, blueY, blueX, 0);
    // cout << m.ry << " " << m.rx << " " << m.by << " " << m.bx << " " << m.num << endl;

    while (!q.empty()) {
        int cntRedY = q.front().ry;
        int cntRedX = q.front().rx;
        int cntBlueY = q.front().by;
        int cntBlueX = q.front().bx;
        int cntNum = q.front().num;
        q.pop();

        escape_blue = false, escape_red = false;
        marble ml = moveLeft(cntRedY, cntRedX, cntBlueY, cntBlueX, cntNum);
        if (escape_blue == false) {
            if (escape_red == true) {
                cout << ml.num << '\n';
                return 0;
            } else {
                if (check[ml.ry][ml.rx][ml.by][ml.bx] == false) {
                    check[ml.ry][ml.rx][ml.by][ml.bx] = true;
                    q.push(ml);
                }
            }
        }
        escape_blue = false, escape_red = false;

        marble mr = moveRight(cntRedY, cntRedX, cntBlueY, cntBlueX, cntNum);
        if (escape_blue == false) {
            if (escape_red == true) {
                cout << mr.num << '\n';
                return 0;
            } else {
                if (check[mr.ry][mr.rx][mr.by][mr.bx] == false) {
                    check[mr.ry][mr.rx][mr.by][mr.bx] = true;
                    q.push(mr);
                }
            }
        }
        escape_blue = false, escape_red = false;
        marble mu = moveUp(cntRedY, cntRedX, cntBlueY, cntBlueX, cntNum);
        if (escape_blue == false) {
            if (escape_red == true) {
                cout << mu.num << '\n';
                return 0;
            } else {
                if (check[mu.ry][mu.rx][mu.by][mu.bx] == false) {
                    check[mu.ry][mu.rx][mu.by][mu.bx] = true;
                    q.push(mu);
                }
            }
        }
        escape_blue = false, escape_red = false;
        marble md = moveDown(cntRedY, cntRedX, cntBlueY, cntBlueX, cntNum);
        if (escape_blue == false) {
            if (escape_red == true) {
                cout << md.num << '\n';
                return 0;
            } else {
                if (check[md.ry][md.rx][md.by][md.bx] == false) {
                    check[md.ry][md.rx][md.by][md.bx] = true;
                    q.push(md);
                }
            }
        }
    }

    cout << -1 << '\n';
    return 0;
}