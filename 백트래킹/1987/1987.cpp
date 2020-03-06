#include <iostream>
#include <algorithm>
using namespace std;

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

int r, c;
int ans = 0;
char board[20][20];
int alphabet[26];

void dfs(int y, int x, int cnt)
{
    ans = max(ans, cnt);

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= r || nx < 0 || nx >= c)
            continue;

        int k = (int)board[ny][nx] - 'A';
        if (alphabet[k])
            continue;

        alphabet[k]++;
        dfs(ny, nx, cnt + 1);
        alphabet[k]--;
    }
}

int main(void)
{
    cin >> r >> c;

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> board[i][j];

    alphabet[(int)board[0][0] - 'A'] = 1;
    dfs(0, 0, 1);

    cout << ans << '\n';
    return 0;
}