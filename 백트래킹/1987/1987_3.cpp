#include <iostream>
#include <queue>
using namespace std;

int R, C;
char board[22][22];
bool alphabet[26];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int maxLevel = 0;

void dfs(int y, int x, int level)
{
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (0 <= ny && ny < R && 0 <= nx && nx < C) {
            char c = board[ny][nx];
            if (alphabet[c - 'A'] == true) {
                if (level > maxLevel)
                    maxLevel = level;
            } else {
                alphabet[c - 'A'] = true;
                dfs(ny, nx, level + 1);
                alphabet[c - 'A'] = false;
            }
        }
    }
}

int main(void)
{
    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> board[i][j];
        }
    }

    alphabet[board[0][0] - 'A'] = true;
    dfs(0, 0, 1);

    cout << maxLevel << '\n';

    return 0;
}