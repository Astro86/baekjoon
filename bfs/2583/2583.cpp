#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int map[110][110];
int M, N, K;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int areaNum;
int area[1000000];
queue<pair<int, int>> q;

int main(void)
{
    cin >> M >> N >> K;

    for (int i = 0; i < K; i++) {
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;

        for (int j = ly; j < ry; j++) {
            for (int k = lx; k < rx; k++) {
                map[j][k] = 1;
            }
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {

            if (map[i][j] == 0) {
                int blocks = 1;
                q.push({ i, j });
                map[i][j] = 2;

                while (!q.empty()) {
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        int ny = y + dy[k];
                        int nx = x + dx[k];

                        if (0 <= ny && ny < M && 0 <= nx && nx < N) {
                            if (map[ny][nx] == 0) {
                                q.push({ ny, nx });
                                map[ny][nx] = 2;
                                blocks++;
                            }
                        }
                    }
                }
                area[areaNum++] = blocks;
            }
        }
    }

    sort(area, area + areaNum);

    cout << areaNum << '\n';
    for (int i = 0; i < areaNum; i++) {
        cout << area[i] << " ";
    }

    return 0;
}