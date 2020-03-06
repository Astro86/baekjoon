# 백준 1987 - 알파벳

[1987 - 알파벳](https://www.acmicpc.net/problem/1987)

![](1987m.png)

<br>

```cpp
void dfs(int y, int x, int cnt)
{
    ans = max(ans, cnt);

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        // 범위내에 있는지 확인
        if (ny < 0 || ny >= r || nx < 0 || nx >= c)
            continue;

        int k = (int)board[ny][nx] - 'A';
        // 한번 선택한 적이 있는지 확인
        if (alphabet[k])
            continue;

        // 선택한다.
        alphabet[k]++;
        // 다음으로 넘어간다.
        dfs(ny, nx, cnt + 1);
        // 선택한 것을 해지한다.
        alphabet[k]--;
    }
}
```

`DFS`를 이용하여 문제를 해결 하였다. 하나 하나씩 check하면서 문제를 풀어나가야 하기 때문에 한 번에 여러 사항을 고려 하는 `BFS`와는 맞지 않은 문제이다.
`alphabet[i]`은 해당 알파벳이 선택됭적이 있는지 확인하기 위한 배열로 사용된다.

<br>

## 전체 소스 코드

```cpp
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
```
