#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Edge {
    int start, end, cost;
    bool operator<(const Edge& other) {
        return cost < other.cost;
    }
};
int p[11];
int map[11][11];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
bool check[11][11];
int n, m;
vector<Edge> Graph;

int find(int x) {
    if (p[x] == x)
        return x;
    return p[x] = find(p[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
        ;
    p[x] = y;
}

bool inner(int x, int y) {
    return (0 <= x && x < n && 0 <= y && y < m);
}

void dfs(int x, int y, int num) {
    map[x][y] = num;
    check[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (inner(nx, ny) && !check[nx][ny] && map[nx][ny])
            dfs(nx, ny, num);
    }
}

int main() {
    scanf(" %d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %d", &map[i][j]);
        }
    }

    int c = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!check[i][j] && map[i][j])
                dfs(i, j, c++);
        }
    }
    for (int i = 1; i <= c; i++) p[i] = i;
    Graph.resize(c + 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!map[i][j])
                continue;
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                int dist = 0;
                while (inner(nx, ny) && !map[nx][ny]) nx += dx[k], ny += dy[k], dist++;
                if (inner(nx, ny) && (map[nx][ny] != map[i][j]) && map[nx][ny])
                    Graph.push_back({map[i][j], map[nx][ny], dist});
            }
        }
    }

    int ans = 0;
    int k = 0;
    sort(Graph.begin(), Graph.end());
    for (int i = 0; i < Graph.size(); i++) {
        Edge e = Graph[i];
        if (e.cost < 2)
            continue;
        if (find(e.start) != find(e.end)) {
            merge(e.start, e.end);
            ans += e.cost;
            k += 1;
        }
    }
    printf("%d\n", (k + 2 != c) ? -1 : ans);
}
