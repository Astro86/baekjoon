#include <iostream>
#include <queue>
using namespace std;

int N, M;
int limitTime;
int map[110][110];
bool check[110][110];
bool checkSword[110][110];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

struct hero {
    int y;
    int x;
    int num;
    bool glam;
};

queue<hero> q;

int main(void) {
    cin >> N >> M >> limitTime;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> map[i][j];
        }
    }

    if (map[1][1] == 2) {
        q.push({1, 1, 0, true});
    } else {
        q.push({1, 1, 0, false});
    }
    check[1][1] = true;

    bool isSuccess = false;
    bool sword = false;

    while (!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        int num = q.front().num;
        int glam = q.front().glam;
        q.pop();

        if (num > limitTime) {
            break;
        }

        if (y == N && x == M) {
            cout << num << "\n";
            isSuccess = true;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (1 <= ny && ny <= N && 1 <= nx && nx <= M) {
                if (glam == true) {
                    if (checkSword[ny][nx] == false) {
                        checkSword[ny][nx] = true;
                        q.push({ny, nx, num + 1, true});
                    }
                } else {
                    if (check[ny][nx] == false) {
                        if (map[ny][nx] == 0) {
                            check[ny][nx] = true;
                            q.push({ny, nx, num + 1, false});
                        } else if (map[ny][nx] == 2) {
                            check[ny][nx] = true;
                            checkSword[ny][nx] = true;
                            sword = true;
                            q.push({ny, nx, num + 1, true});
                        }
                    }
                }
            }
        }
    }
    if (isSuccess == false) {
        cout << "Fail" << '\n';
    }

    return 0;
}