# 백준 18809 - Gaaaaaaaaaarden
![](18809.jpeg)

## 채점 현황
![](18809_score.png)

## 전체 소스 코드
```cpp
#include <bits/stdc++.h>
using namespace std;

int N, M, G, R;
int garden[55][55];
struct Point {
    int time = -1;
    bool green = false;
    bool red = false;

    bool isVisited() {
        if (green == true || red == true)
            return true;
        return false;
    }

    int getTime() {
        return time;
    }
};
Point visited[55][55];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<pair<int, int>> possibleArea;
vector<int> check;
vector<vector<int>> combinations;

int maxArea = 0;

void choiceRInNByRed(int index, int r) {
    if (r == R) {
        vector<int> v;
        for (int i = 0; i < check.size(); i++) {
            v.push_back(check[i]);
        }
        combinations.push_back(v);

        return;
    }

    for (int i = index; i < check.size(); i++) {
        if (check[i] == 0) {
            check[i] = 2;
            choiceRInNByRed(i + 1, r + 1);
            check[i] = 0;
        }
    }
}

void choiceRInNByGreen(int index, int r) {
    if (r == G) {
        choiceRInNByRed(0, 0);
        return;
    }

    for (int i = index; i < check.size(); i++) {
        if (check[i] == 0) {
            check[i] = 1;
            choiceRInNByGreen(i + 1, r + 1);
            check[i] = 0;
        }
    }
}

void initVisited() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j].time = -1;
            visited[i][j].green = false;
            visited[i][j].red = false;
        }
    }
}

int main(void) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N >> M >> G >> R;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> garden[i][j];

            if (garden[i][j] == 2) {
                possibleArea.push_back({i, j});
            }
        }
    }

    check = vector<int>(possibleArea.size());
    choiceRInNByGreen(0, 0);

    for (auto& v : combinations) {
        // for (int i = 0; i < v.size(); i++) {
        //     cout << v[i] << " ";
        // }
        // cout << endl;

        queue<pair<int, int>> q1;
        queue<pair<int, int>> q2;

        initVisited();

        for (int i = 0; i < v.size(); i++) {
            int y = possibleArea[i].first;
            int x = possibleArea[i].second;

            if (v[i] == 1) {
                q1.push({y, x});
                visited[y][x].time = 0;
                visited[y][x].green = true;
            }

            if (v[i] == 2) {
                q2.push({y, x});
                visited[y][x].time = 0;
                visited[y][x].red = true;
            }
        }

        int count = 0;
        int time = 0;
        while (!q1.empty() && !q2.empty()) {
            time++;
            int q1_size = q1.size();
            int q2_size = q2.size();

            while (q1_size--) {
                int cntY = q1.front().first;
                int cntX = q1.front().second;
                q1.pop();

                if (visited[cntY][cntX].green && visited[cntY][cntX].red) {
                    continue;
                }

                for (int i = 0; i < 4; i++) {
                    int ny = cntY + dy[i];
                    int nx = cntX + dx[i];

                    if (0 <= ny && ny < N && 0 <= nx && nx < M) {
                        if (garden[ny][nx] != 0 && !visited[ny][nx].isVisited()) {
                            visited[ny][nx].time = time;
                            visited[ny][nx].green = true;
                            q1.push({ny, nx});
                        }
                    }
                }
            }

            while (q2_size--) {
                int cntY = q2.front().first;
                int cntX = q2.front().second;
                q2.pop();

                if (visited[cntY][cntX].green && visited[cntY][cntX].red) {
                    continue;
                }

                for (int i = 0; i < 4; i++) {
                    int ny = cntY + dy[i];
                    int nx = cntX + dx[i];

                    if (0 <= ny && ny < N && 0 <= nx && nx < M) {
                        if (garden[ny][nx] != 0 && !visited[ny][nx].isVisited()) {
                            visited[ny][nx].time = time;
                            visited[ny][nx].red = true;
                            q2.push({ny, nx});
                        }

                        if (visited[ny][nx].getTime() == time && visited[ny][nx].red == false) {
                            visited[ny][nx].red = true;
                            count++;
                        }
                    }
                }
            }
        }

        maxArea = max(maxArea, count);
    }

    cout << maxArea << '\n';
    return 0;
}
```