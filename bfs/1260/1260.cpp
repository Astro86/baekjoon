#include <bits/stdc++.h>
using namespace std;

int N, M, V;
int map[1001][1001];
bool dfs_check[1001];
bool bfs_check[1001];

void dfs(int node) {
    cout << node << ' ';
    dfs_check[node] = true;
    for (int i = 1; i <= N; i++) {
        if (::map[node][i] == 1 && dfs_check[i] == false) {
            dfs(i);
        }
    }
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    bfs_check[start] = true;

    cout << start << ' ';

    while (!q.empty()) {
        int cnt = q.front();
        q.pop();

        for (int i = 1; i <= N; i++) {
            if (::map[cnt][i] == 1 && bfs_check[i] == false) {
                bfs_check[i] = true;
                q.push(i);
                cout << i << ' ';
            }
        }
    }
}

int main(void) {
    cin >> N >> M >> V;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        ::map[a][b] = 1;
        ::map[b][a] = 1;
    }

    dfs(V);
    cout << '\n';
    bfs(V);
    cout << '\n';

    return 0;
}