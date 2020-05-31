#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> graph;
int check[101];
int num1 = 0;
int num2 = 0;

void bfs(int n) {
    queue<int> q;
    q.push(n);
    check[n] = 1;
    num1++;

    while (!q.empty()) {
        int cnt = q.front();
        q.pop();

        for (int i = 0; i < graph[cnt].size(); i++) {
            int next = graph[cnt][i];

            if (check[next] == 0) {
                if (check[cnt] == 1) {
                    q.push(next);
                    num2++;
                    check[next] = 2;
                } else {
                    q.push(next);
                    num1++;
                    check[next] = 1;
                }
            }
        }
    }
}

int main(void) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n;
    graph = vector<vector<int>>(n + 1);

    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        for (int j = 0; j < num; j++) {
            int point;
            cin >> point;
            graph[i].push_back(point);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (check[i] == 0) {
            bfs(i);
        }
    }

    cout << num1 << '\n';
    for (int i = 1; i <= n; i++) {
        if (check[i] == 1) {
            cout << i << ' ';
        }
    }
    cout << '\n';

    cout << num2 << '\n';
    for (int i = 1; i <= n; i++) {
        if (check[i] == 2) {
            cout << i << ' ';
        }
    }
    cout << '\n';
    return 0;
}
