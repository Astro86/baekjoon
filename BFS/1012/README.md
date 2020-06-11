# 백준 1012 - 유기농 배추

## 링크

https://www.acmicpc.net/problem/1012

## 채점 현황

![](1012_score.png)

## 문제 풀이
1. field를 탐색하면서 배추가 심어져 있는 위치를 찾는다.
2. 배추가 심어져 있는 곳을 찾았다면 이전에 탐색을 했는지 확인한다.
   1. 탐색한 적이 없다면 다음으로 넘어간다.
   2. 탐색한 적이 있다면 1로 돌아간다.
3. 배추가 심어져 있는 주변에 다른 배추들이 있는지 탐색한다.

> 탐색횟수가 배추 흰 지렁이의 갯수가 된다.

## BFS를 이용한 코드

```cpp
#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int field[55][55];
bool check[55][55];

int width, height;
int test_case;
int num_of_cabbage;
int num_of_warm;

void init() {
    for (int i = 0; i < 55; i++) {
        for (int j = 0; j < 55; j++) {
            field[i][j] = 0;
            check[i][j] = false;
        }
    }
    num_of_warm = 0;
}

void bfs(int y, int x) {
    num_of_warm++;
    check[y][x] = true;
    queue<pair<int, int>> q;
    q.push({y, x});

    while (!q.empty()) {
        int cnt_y = q.front().first;
        int cnt_x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cnt_y + dy[i];
            int nx = cnt_x + dx[i];

            if (0 > ny || ny >= height || 0 > nx || nx >= width) {
                continue;
            }

            if (check[ny][nx] == true) {
                continue;
            }

            if (field[ny][nx] == 0) {
                continue;
            }

            check[ny][nx] = true;
            q.push({ny, nx});
        }
    }
}

int main(void) {
    cin >> test_case;

    while (test_case--) {
        cin >> width >> height >> num_of_cabbage;
        init();

        for (int i = 0; i < num_of_cabbage; i++) {
            int x, y;
            cin >> x >> y;

            field[y][x] = 1;
        }

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (field[i][j] == 1 && check[i][j] == false) {
                    bfs(i, j);
                }
            }
        }

        cout << num_of_warm << '\n';
    }
    return 0;
}
```

## DFS를 이용한 코드

```cpp
#include <bits/stdc++.h>
using namespace std;

int field[55][55];
bool check[55][55];
int test_case, width, height;
int num_of_cabbage;
int num_of_warm;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void init() {
    for (int i = 0; i < 55; i++) {
        for (int j = 0; j < 55; j++) {
            field[i][j] = 0;
            check[i][j] = false;
        }
    }
    num_of_warm = 0;
}

void dfs(int y, int x) {
    check[y][x] = true;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (0 > ny || ny >= height || 0 > nx || nx >= width) {
            continue;
        }

        if (check[ny][nx] == true) {
            continue;
        }

        if (field[ny][nx] == 0) {
            continue;
        }

        dfs(ny, nx);
    }
}

int main(void) {
    cin >> test_case;

    while (test_case--) {
        cin >> width >> height >> num_of_cabbage;
        init();

        for (int i = 0; i < num_of_cabbage; i++) {
            int x, y;
            cin >> x >> y;

            field[y][x] = true;
        }

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (field[i][j] == 1 && check[i][j] == false) {
                    num_of_warm++;
                    dfs(i, j);
                }
            }
        }
        cout << num_of_warm << '\n';
    }
    return 0;
}
```