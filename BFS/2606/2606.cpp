#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
int num;

vector<vector<int>> g;
int check[101];

queue<int> q;

void bfs() {
    check[1] = true;

    while (!q.empty()) {
        int cnt = q.front();
        q.pop();

        int edge_num = g[cnt].size();
        for (int i = 0; i < edge_num; i++) {
            int node = g[cnt][i];
            if (check[node] == false) {
                check[node] = true;
                q.push(node);
                num++;
            }
        }
    }
}

int main(void) {
    cin >> n >> m;
    g = vector<vector<int>>(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    q.push(1);
    bfs();
    cout << num << "\n";

    return 0;
}