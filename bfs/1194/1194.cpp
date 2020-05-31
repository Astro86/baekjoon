#include <bits/stdc++.h>
using namespace std;

int N, M;
char Map[55][55];
bool check[1 << 6][55][55];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

queue<pair<int, int>> q;

int startY, startX;

struct point {
    int y;
    int x;
    int key;
    int count;
};

int bfs() {
    queue<point> q;
    q.push({startY, startX, 0, 0});
    check[0][startY][startX] = true;

    while (!q.empty()) {
        int cntY = q.front().y;
        int cntX = q.front().x;
        int cntKey = q.front().key;
        int cntCount = q.front().count;
        q.pop();

        if (Map[cntY][cntX] == '1') {
            return cntCount;
        }

        for (int i = 0; i < 4; i++) {
            int ny = cntY + dy[i];
            int nx = cntX + dx[i];

            if (0 >= ny || ny > N || 0 >= nx || nx > M) {
                continue;
            }
            if (check[cntKey][ny][nx] == true) {
                continue;
            }

            if (Map[ny][nx] == '.') {
                check[cntKey][ny][nx] = true;
                q.push({ny, nx, cntKey, cntCount + 1});
            } else {
                // 열쇠에 마주쳤을 경우
                if ('a' <= Map[ny][nx] && Map[ny][nx] <= 'f') {
                    int key = (1 << (Map[ny][nx] - 'a'));
                    check[cntKey | key][ny][nx] = true;
                    q.push({ny, nx, cntKey | key, cntCount + 1});
                }

                // 문을 만났을 경우
                if ('A' <= Map[ny][nx] && Map[ny][nx] <= 'F') {
                    int door = (1 << (Map[ny][nx] - 'A'));

                    if (door & cntKey) {
                        check[cntKey][ny][nx] = true;
                        q.push({ny, nx, cntKey, cntCount + 1});
                    }
                }

                // 출구를 만났을 경우
                if (Map[ny][nx] == '1') {
                    q.push({ny, nx, cntKey, cntCount + 1});
                }
            }
        }
    }

    return -1;
}

void init() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> Map[i][j];

            if (Map[i][j] == '0') {
                startY = i;
                startX = j;
                Map[i][j] = '.';
            }
        }
    }
}

int main(void) {
    cin >> N >> M;
    init();
    cout << bfs() << '\n';
    return 0;
}