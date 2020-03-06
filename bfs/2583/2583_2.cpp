#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M, K;
int map[110][110];
bool check[110][110];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
vector<int> v;

void bfs(int y, int x)
{
    int num = 1;
    queue<pair<int, int>> q;
    q.push({ y, x });

    while (!q.empty()) {
        int cntY = q.front().first;
        int cntX = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cntY + dy[i];
            int nx = cntX + dx[i];

            if (0 <= ny && ny < N && 0 <= nx && nx < M) {
                if (map[ny][nx] == 0 && check[ny][nx] == false) {
                    check[ny][nx] = true;
                    q.push({ ny, nx });
                    num++;
                }
            }
        }
    }
    v.push_back(num);
}

int main(void)
{
    cin >> N >> M >> K;

    while (K--) {
        int startX, startY, endX, endY;
        cin >> startX >> startY >> endX >> endY;

        for (int i = startY; i < endY; i++) {
            for (int j = startX; j < endX; j++) {
                map[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0 && check[i][j] == false) {
                check[i][j] = true;
                bfs(i, j);
            }
        }
    }

    sort(v.begin(), v.end());

    cout << v.size() << '\n';
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    return 0;
}