#include <bits/stdc++.h>
using namespace std;

int row, col, shark_num;
// 1 : 위, 2 : 아래, 3 : 오른쪽, 4 : 왼쪽
// int dir[4] = {1, 2, 3, 4};
int dy[5] = {0, -1, 1, 0, 0};
int dx[5] = {0, 0, 0, 1, -1};

struct Shark {
    int row;
    int col;
    int speed;
    int dir;
    int size;
};

Shark grid[110][110];
int total_shark_size = 0;

int main(void) {
    cin >> row >> col >> shark_num;

    for (int i = 0; i < shark_num; i++) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;

        grid[r][c] = {r, c, s, d, z};
    }

    // 낚시왕이 오른쪽으로 한 칸 이동한다.
    // 낚시왕이 있는 열에 있는 상어 중에서 땅과 제일 가까운 상어를 잡는다. 상어를 잡으면 격자판에서 잡은 상어가 사라진다.
    // 상어가 이동한다.

    int fishingKing = 0;
    while (++fishingKing <= col) {
        int cnt_row = 1;
        // 현재 낚시왕의 위치에서 가장 가까운 물고기를 찾는다.
        while (cnt_row <= row && grid[cnt_row][fishingKing].size == 0) {
            cnt_row++;
        }
        // 물고기를 낚는다. 물고기가 없을 수도 있는데, 사이즈는 0이므로 예외처리할 필요 없다.
        total_shark_size += grid[cnt_row][fishingKing].size;
        grid[cnt_row][fishingKing] = {0, 0, 0, 0, 0};

        // 상어들이 움직이게 한다.
        // 상어는 한번씩만 움직여야 하므로 큐를 이용하기로 한다.
        queue<Shark> q;
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                if (grid[i][j].size != 0) {
                    q.push(grid[i][j]);
                    grid[i][j] = {0, 0, 0, 0, 0};
                }
            }
        }

        while (!q.empty()) {
            int cntY = q.front().row;
            int cntX = q.front().col;
            int speed = q.front().speed;
            int dir = q.front().dir;
            int size = q.front().size;
            q.pop();

            // 현재 상어가 잡아먹힌 경우에 대해서 예외처리
            // if (grid[cntY][cntX].size != size) {
            //     continue;
            // }

            int ny = cntY;
            int nx = cntX;

            int remainder = 0;
            if (dir == 1 || dir == 2) {
                remainder = speed % (2 * (row - 1));
            } else {
                remainder = speed % (2 * (col - 1));
            }

            for (int i = 1; i <= remainder; i++) {
                ny += dy[dir];
                nx += dx[dir];

                if (1 > ny || ny > row || 1 > nx || nx > col) {
                    ny -= dy[dir] * 2;
                    nx -= dx[dir] * 2;

                    if (dir == 1) {
                        dir = 2;
                    } else if (dir == 2) {
                        dir = 1;
                    } else if (dir == 3) {
                        dir = 4;
                    } else {
                        dir = 3;
                    }
                }
            }

            // 움직인 장소에 다른 상어가 있을 경우
            if (grid[ny][nx].size != 0) {
                // 움직인 상어가 기존 상어보다 큰 경우, 아닌 경우는 갱신할 필요가 없다.
                if (size > grid[ny][nx].size) {
                    grid[ny][nx] = {ny, nx, speed, dir, size};
                }
            } else {
                grid[ny][nx] = {ny, nx, speed, dir, size};
            }
        }
    }

    cout << total_shark_size << '\n';
    return 0;
}

// 디버깅
// for (int i = 1; i <= row; i++) {
//     for (int j = 1; j <= col; j++) {
//         if (grid[i][j].size != 0) {
//             cout << 1 << " ";
//         } else {
//             cout << 0 << ' ';
//         }
//     }
//     cout << endl;
// }
// cout << endl;