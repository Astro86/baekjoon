#include <iostream>
#include <queue>
using namespace std;

int N, M;
char map[11][11];
char check[11][11];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

struct Beads {
    int redX;
    int redY;
    int blueX;
    int blueY;
    int count;
};
bool visited[11][11][11][11];

queue<Beads> q;

void moveBead(int& y, int& x, int d)
{
    while (1) {
        x += dx[d];
        y += dy[d];

        if (map[y][x] == '#') {
            x -= dx[d];
            y -= dy[d];
            break;
        } else if (map[y][x] == 'O') {
            break;
        }
    }
}

int main(void)
{
    cin >> N >> M;

    Beads beads;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];

            if (map[i][j] == 'R') {
                beads.redY = i;
                beads.redX = j;
                map[i][j] = '.';
            }

            if (map[i][j] == 'B') {
                beads.blueY = i;
                beads.blueX = j;
                map[i][j] = '.';
            }
        }
    }
    beads.count = 0;
    q.push(beads);
    visited[beads.redX][beads.redY][beads.blueX][beads.blueY] = true;

    while (!q.empty()) {
        int redY = q.front().redY;
        int redX = q.front().redX;
        int blueY = q.front().blueY;
        int blueX = q.front().blueX;
        int count = q.front().count;
        q.pop();

        if (count > 10) {
            cout << -1 << endl;
            return 0;
        }

        if (map[redY][redX] == 'O') {
            cout << count << '\n';
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int rny = redY;
            int rnx = redX;
            int bny = blueY;
            int bnx = blueX;
            int cnt = count + 1;

            moveBead(rny, rnx, i);
            moveBead(bny, bnx, i);

            if (map[bny][bnx] == 'O')
                continue;

            if (rny == bny && rnx == bnx) {
                if (i == 0) {
                    if (blueX < redX) {
                        bnx--;
                    } else {
                        rnx--;
                    }
                } else if (i == 1) {
                    if (blueY < redY) {
                        bny--;
                    } else {
                        rny--;
                    }

                } else if (i == 2) {
                    if (blueX < redX) {
                        rnx++;
                    } else {
                        bnx++;
                    }
                } else {
                    if (blueY < redY) {
                        rny++;
                    } else {
                        bny++;
                    }
                }
            }

            if (!visited[rnx][rny][bnx][bny]) {
                Beads temp = { rnx, rny, bnx, bny, count + 1 };
                q.push(temp);
                visited[rnx][rny][bnx][bny] = true;
            }
        }
    }
    cout << -1 << '\n';
    return 0;
}