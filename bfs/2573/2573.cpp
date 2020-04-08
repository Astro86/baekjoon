#include <iostream>
using namespace std;

int n, m;
int ice;
int island;
int year;
int arr[303][303];
bool check[303][303];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int y, int x, int iceNum) {
    if (iceNum == 0) {
        return;
    }

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (check[ny][nx] == false && arr[ny][nx] != 0) {
            check[ny][nx] = true;
            dfs(ny, nx, iceNum - 1);
        }
    }
}

int main(void) {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            ice++;
        }
    }

    while (1) {
        island = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (check[i][j] == false && arr[i][j] != 0) {
                    island++;
                    check[i][j] = true;
                    dfs(i, j, ice);
                }
            }
        }

        if (island > 1) {
            cout << year << '\n';
            return 0;
        }

        int newArr[303][303];
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (arr[j][k] != 0) {
                    int zeroNum = 0;
                    for (int d = 0; d < 4; d++) {
                        int ny = j + dy[d];
                        int nx = k + dx[d];

                        if (arr[ny][nx] == 0)
                            zeroNum++;
                    }
                    newArr[j][k] = arr[j][k] - zeroNum;
                }
            }
        }

        ice = 0;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (newArr[j][k] > 0) {
                    ice++;
                    arr[j][k] = newArr[j][k];
                } else
                    arr[j][k] = 0;
            }
        }
        if (ice == 0) {
            cout << 0 << '\n';
            return 0;
        }

        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                check[j][k] = false;
            }
        }

        year++;
    }
    cout << 0 << '\n';
    return 0;
}