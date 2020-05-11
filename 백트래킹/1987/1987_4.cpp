#include <iostream>
using namespace std;

int R, C;
char map[22][22];
bool check[26];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int maxNum;

void dfs(int y, int x, int num) {
    if (maxNum < num) {
        maxNum = num;
    }

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (0 <= ny && ny < R && 0 <= nx && nx < C) {
            char nextColor = map[ny][nx];

            if (check[nextColor - 'A'] == false) {
                check[nextColor - 'A'] = true;
                dfs(ny, nx, num + 1);
                check[nextColor - 'A'] = false;
            }
        }
    }
}

int main(void) {
    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];
        }
    }

    check[map[0][0] - 'A'] = true;
    dfs(0, 0, 1);

    cout << maxNum << endl;
    return 0;
}