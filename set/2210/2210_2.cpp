#include <bits/stdc++.h>
using namespace std;

char field[5][5];
char str[6];
set<string> s;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int y, int x, int depth) {
    if (depth == 6) {
        s.insert(str);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (0 > ny || ny >= 5 || 0 > nx || nx >= 5)
            continue;
        str[depth] = field[ny][nx];
        dfs(ny, nx, depth + 1);
    }
}

int main(void) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> field[i][j];
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            str[0] = field[i][j];
            dfs(i, j, 1);
        }
    }
    cout << s.size() << '\n';
    return 0;
}