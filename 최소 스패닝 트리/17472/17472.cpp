#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

#define INF 987654321

int N, M;
int map[11][11];
int colorMap[11][11];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int bridge[7][7];
int parent[7];

struct point {
    int y;
    int x;
    int num;
};

struct edge {
    int from;
    int to;
    int weight;
};

bool cmp(edge a, edge b) {
    return a.weight < b.weight;
}

vector<edge> edges;

queue<point> search_bfs(int y, int x, int area) {
    bool check[11][11];
    memset(check, false, sizeof(check));

    queue<pair<int, int>> q;
    queue<point> local;

    q.push({y, x});
    local.push({y, x, 0});
    check[y][x] = true;

    while (!q.empty()) {
        int cntY = q.front().first;
        int cntX = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cntY + dy[i];
            int nx = cntX + dx[i];

            if (0 <= ny && ny < N && 0 <= nx && nx < M) {
                if (check[ny][nx] == false && map[ny][nx] == 1 && colorMap[ny][nx] == area) {
                    check[ny][nx] = true;
                    q.push({ny, nx});
                    local.push({ny, nx, 0});
                }
            }
        }
    }

    return local;
}

// 세로로 다리 놓기
void cero_bfs(int y, int x, int area) {
    bool check[11][11];
    memset(check, false, sizeof(check));

    queue<point> q = search_bfs(y, x, area);
    check[q.front().y][q.front().x] = true;

    while (!q.empty()) {
        int cntY = q.front().y;
        int cntX = q.front().x;
        int cntNum = q.front().num;
        q.pop();

        if (map[cntY][cntX] == 1 && colorMap[cntY][cntX] != area) {
            int bridge_length = cntNum - 1;

            if (bridge_length > 1) {
                int from = area;
                int to = colorMap[cntY][cntX];

                if (bridge[from][to] > bridge_length) {
                    bridge[from][to] = bridge_length;
                    bridge[to][from] = bridge_length;
                }
            }
            continue;
        }
        for (int i = 2; i < 4; i++) {
            int ny = cntY + dy[i];
            int nx = cntX + dx[i];

            if (0 <= ny && ny < N && 0 <= nx && nx < M) {
                if (check[ny][nx] == false && colorMap[ny][nx] != area) {
                    check[ny][nx] = true;
                    q.push({ny, nx, cntNum + 1});
                }
            }
        }
    }
}

// 가로로 다리 놓기
void garo_bfs(int y, int x, int area) {
    bool check[11][11];
    memset(check, false, sizeof(check));

    queue<point> q = search_bfs(y, x, area);
    check[q.front().y][q.front().x] = true;

    while (!q.empty()) {
        int cntY = q.front().y;
        int cntX = q.front().x;
        int cntNum = q.front().num;
        q.pop();

        if (map[cntY][cntX] == 1 && colorMap[cntY][cntX] != area) {
            int bridge_length = cntNum - 1;
            if (cntNum - 1 > 1) {
                int from = area;
                int to = colorMap[cntY][cntX];

                if (bridge[from][to] > bridge_length) {
                    bridge[from][to] = bridge_length;
                    bridge[to][from] = bridge_length;
                }
            }
            continue;
        }

        for (int i = 0; i < 2; i++) {
            int ny = cntY + dy[i];
            int nx = cntX + dx[i];

            if (0 <= ny && ny < N && 0 <= nx && nx < M) {
                if (check[ny][nx] == false && colorMap[ny][nx] != area) {
                    check[ny][nx] = true;
                    q.push({ny, nx, cntNum + 1});
                }
            }
        }
    }
}

void color_bfs(int y, int x, int color) {
    bool check[11][11];
    memset(check, false, sizeof(check));

    queue<pair<int, int>> q;
    q.push({y, x});
    check[y][x] = true;
    colorMap[y][x] = color;

    while (!q.empty()) {
        int cntY = q.front().first;
        int cntX = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cntY + dy[i];
            int nx = cntX + dx[i];

            if (0 <= ny && ny < N && 0 <= nx && nx < M) {
                if (check[ny][nx] == false && map[ny][nx] == 1) {
                    colorMap[ny][nx] = color;
                    check[ny][nx] = true;
                    q.push({ny, nx});
                }
            }
        }
    }
}

int find(int x) {
    if (x == parent[x]) {
        return x;
    } else {
        return parent[x] = find(parent[x]);
    }
}
void merge(int a, int b) {
    int set_a = parent[a];
    int set_b = parent[b];

    parent[set_a] = set_b;
}

int main(void) {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            bridge[i][j] = INF;
        }
    }

    int color = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 1 && colorMap[i][j] == 0) {
                color++;
                color_bfs(i, j, color);
            }
        }
    }

    vector<bool> area_check(color, false);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int cntColor = colorMap[i][j];
            if (map[i][j] == 1 && !area_check[cntColor]) {
                area_check[cntColor] = true;
                cero_bfs(i, j, cntColor);
                garo_bfs(i, j, cntColor);
            }
        }
    }

    for (int i = 1; i <= color; i++) {
        for (int j = i; j <= color; j++) {
            if (bridge[i][j] != INF) {
                edges.push_back({i, j, bridge[i][j]});
            }
        }
    }

    sort(edges.begin(), edges.end(), cmp);

    for (int i = 0; i < 7; i++) {
        parent[i] = i;
    }

    int i = 0;
    int cnt = 0;
    int sum = 0;
    while (cnt != color - 1 && i < edges.size()) {
        int a = edges[i].from;
        int b = edges[i].to;

        if (find(a) != find(b)) {
            merge(a, b);
            cnt++;
            sum += edges[i].weight;
        }
        i++;
    }

    if (cnt == color - 1) {
        cout << sum << '\n';
    } else {
        cout << -1 << '\n';
    }
    return 0;
}