#include <bits/stdc++.h>
using namespace std;

int Map[110][110];
bool check[110][110];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%1d", &Map[i][j]);
        }
    }

    int num = 0;
    queue<pair<int, int>> q;
    q.push({1, 1});
    check[1][1] = true;

    while (!q.empty()) {
        num++;
        int q_size = q.size();
        while (q_size--) {
            int cntY = q.front().first;
            int cntX = q.front().second;
            q.pop();

            if (cntY == n && cntX == m) {
                cout << num << '\n';
                return 0;
            }

            for (int i = 0; i < 4; i++) {
                int ny = cntY + dy[i];
                int nx = cntX + dx[i];

                if (Map[ny][nx] == 1 && check[ny][nx] == false) {
                    check[ny][nx] = true;
                    q.push({ny, nx});
                }
            }
        }
    }
    return 0;
}