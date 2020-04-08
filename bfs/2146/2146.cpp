#include <iostream>
#include <queue>
using namespace std;

int N;
int arr[110][110];
int map[110][110];
int check[110][110];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int area;
int minBridge = 1000000000;

struct Point {
    int y;
    int x;
    int level;
};

void makeMap(int a, int b) {
    queue<pair<int, int>> q;
    q.push({a, b});

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (0 <= ny && ny < N && 0 <= nx && nx < N) {
                if (arr[ny][nx] == 1 && map[ny][nx] == 0) {
                    map[ny][nx] = area;
                    q.push({ny, nx});
                }
            }
        }
    }
}

void makeBridge(int start) {
    queue<Point> q;

    int tempMap[110][110];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            tempMap[i][j] = map[i][j];

            if (tempMap[i][j] == start) {
                q.push({i, j, 0});
            }
        }
    }

    while (!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        int level = q.front().level;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (0 <= ny && ny < N && 0 <= nx && nx < N) {
                if (tempMap[ny][nx] == 0) {
                    tempMap[ny][nx] = start;
                    q.push({ny, nx, level + 1});
                } else if (tempMap[ny][nx] != start) {
                    if (minBridge > level) {
                        minBridge = level;
                        return;
                    }
                }
            }
        }
    }
}

int main(void) {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == 1 && map[i][j] == 0) {
                area++;
                map[i][j] = area;
                makeMap(i, j);
            }
        }
    }

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cout << map[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for (int i = 1; i < area; i++) {
        makeBridge(i);
    }

    cout << minBridge << endl;
    return 0;
}