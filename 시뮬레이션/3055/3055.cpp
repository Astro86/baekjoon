#include <iostream>
#include <queue>
using namespace std;

int R, C;
char map[51][51];
bool check[51][51];
queue<pair<int, int>> water;
queue<pair<int, int>> q;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void flood(int n) {
    int size = n;

    while (size--) {
        int y = water.front().first;
        int x = water.front().second;
        water.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (0 <= ny && ny < R && 0 <= nx && nx < C) {
                if (map[ny][nx] == '.') {
                    map[ny][nx] = '*';
                    water.push({ny, nx});
                }
            }
        }
    }
}

bool findD(int n) {
    int size = n;

    while (size--) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (0 <= ny && ny < R && 0 <= nx && nx < C) {
                if (map[ny][nx] == '.' && check[ny][nx] == false) {
                    bool isPass = true;
                    for (int j = 0; j < 4; j++) {
                        int nny = ny + dy[i];
                        int nnx = nx + dx[i];

                        if (map[nny][nnx] == '*') {
                            isPass = false;
                        }
                    }
                    if (isPass == true) {
                        check[ny][nx] = true;
                        q.push({ny, nx});
                    }
                } else if (map[ny][nx] == 'D') {
                    return true;
                }
            }
        }
    }

    return false;
}

int main(void) {
    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];

            if (map[i][j] == 'S') {
                check[i][j] = true;
                q.push({i, j});
            }

            if (map[i][j] == '*') {
                water.push({i, j});
            }
        }
    }

    int q_size = q.size();
    int water_size = water.size();
    int level = 0;
    bool isPass = false;
    while (q_size != 0) {
        flood(water_size);

        isPass = findD(q_size);
        level++;
        if (isPass == true) {
            break;
        }

        water_size = water.size();
        q_size = q.size();
    }

    if (isPass == true) {
        cout << level << '\n';
    } else {
        cout << "KAKTUS" << '\n';
    }

    return 0;
}