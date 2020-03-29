#include <bits/stdc++.h>
using namespace std;

int N, M;
char board[11][11];
struct Bead {
    int y;
    int x;

    bool operator==(Bead bead) {
        return (this->y == bead.y) && (this->x == bead.x);
    }
};
bool check[11][11][11][11];
// 순서는 동, 서, 남, 북
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void moveBead(Bead& bead, int dir) {
    while (true) {
        bead.y += dy[dir];
        bead.x += dx[dir];

        if (board[bead.y][bead.x] == '#') {
            bead.y -= dy[dir];
            bead.x -= dx[dir];
            break;
        }

        if (board[bead.y][bead.x] == 'O') {
            break;
        }
    }
}

int main(void) {
    cin >> N >> M;
    Bead red, blue;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];

            if (board[i][j] == 'R') {
                red.y = i;
                red.x = j;
            }

            if (board[i][j] == 'B') {
                blue.y = i;
                blue.x = j;
            }
        }
    }

    queue<pair<Bead, Bead>> q;
    q.push({red, blue});
    check[red.y][red.x][blue.y][blue.x] = true;

    int cnt = 0;
    while (!q.empty()) {
        int q_size = q.size();

        while (q_size--) {
            Bead cntRed = q.front().first;
            Bead cntBlue = q.front().second;
            q.pop();

            if (board[cntRed.y][cntRed.x] == 'O') {
                cout << cnt << '\n';
                return 0;
            }

            for (int i = 0; i < 4; i++) {
                Bead nextRed = cntRed;
                Bead nextBlue = cntBlue;

                moveBead(nextRed, i);
                moveBead(nextBlue, i);

                if (board[nextBlue.y][nextBlue.x] == 'O') {
                    continue;
                }

                if (nextRed == nextBlue) {
                    // 동
                    if (i == 0) {
                        if (cntRed.x < cntBlue.x) {
                            nextRed.x--;
                        } else {
                            nextBlue.x--;
                        }
                    }

                    // 서
                    if (i == 1) {
                        if (cntRed.x < cntBlue.x) {
                            nextBlue.x++;
                        } else {
                            nextRed.x++;
                        }
                    }

                    // 남
                    if (i == 2) {
                        if (cntRed.y < cntBlue.y) {
                            nextRed.y--;
                        } else {
                            nextBlue.y--;
                        }
                    }

                    // 북
                    if (i == 3) {
                        if (cntRed.y < cntBlue.y) {
                            nextBlue.y++;
                        } else {
                            nextRed.y++;
                        }
                    }
                }

                if (!check[nextRed.y][nextRed.x][nextBlue.y][nextBlue.x]) {
                    check[nextRed.y][nextRed.x][nextBlue.y][nextBlue.x] = true;
                    q.push({nextRed, nextBlue});
                }
            }
        }
        cnt++;
    }

    cout << -1 << '\n';
    return 0;
}