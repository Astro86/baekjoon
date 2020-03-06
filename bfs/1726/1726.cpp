#include <iostream>
#include <queue>
using namespace std;

int M, N;
int map[101][101];
bool check[101][101][4];
int dx[4] = { 0, 1, -1, 0 };
int dy[4] = { -1, 0, 0, 1 };
// char dir[4] = { 'N', 'E', 'W', 'S' };

struct point {
    int y;
    int x;
    int dir;
};

int main(void)
{
    cin >> M >> N;

    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
        }
    }

    point start, goal;

    int tempY, tempX, tempD;
    cin >> tempY >> tempX >> tempD;

    start.y = tempY;
    start.x = tempX;
    start.dir = tempD % 4;

    cin >> tempY >> tempX >> tempD;

    goal.y = tempY;
    goal.x = tempX;
    goal.dir = tempD % 4;

    queue<point> q;
    q.push(start);
    check[start.y][start.x][start.dir] = true;

    int num = 0;
    while (!q.empty()) {
        int q_size = q.size();

        while (q_size--) {
            int y = q.front().y;
            int x = q.front().x;
            int d = q.front().dir;
            q.pop();

            if (y == goal.y && x == goal.x && d == goal.dir) {
                cout << num << '\n';
                return 0;
            }

            int nextR, nextL;
            if (d == 0) {
                nextR = 1;
                nextL = 2;
            } else if (d == 1) {
                nextR = 3;
                nextL = 0;
            } else if (d == 2) {
                nextR = 0;
                nextL = 3;
            } else if (d == 3) {
                nextR = 2;
                nextL = 1;
            }
            if (check[y][x][nextR] == false) {
                check[y][x][nextR] = true;
                q.push({ y, x, nextR });
            }
            if (check[y][x][nextL] == false) {
                check[y][x][nextL] = true;
                q.push({ y, x, nextL });
            }

            for (int i = 1; i <= 3; i++) {
                int nx = x + dx[d] * i;
                int ny = y + dy[d] * i;

                if (1 <= ny && ny <= M && 1 <= nx && nx <= N) {
                    if (map[ny][nx] == 1) {
                        break;
                    }

                    if (check[ny][nx][d] == false) {
                        check[ny][nx][d] = true;
                        q.push({ ny, nx, d });
                    }
                }
            }
        }
        num++;

        // for (int i = 1; i <= M; i++) {
        //     for (int j = 1; j <= N; j++) {
        //         cout << check[i][j][3] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
    }
}