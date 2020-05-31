#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define INF 987654321

int N;
int area[11];
int map[11][11];
bool check[11];
int minDist = INF;

bool bfs(vector<int>& group) {
    vector<int> check(N + 1, true);
    for (int i = 0; i < group.size(); i++) {
        int index = group[i];
        check[index] = false;
    }

    queue<int> q;
    q.push(group[0]);
    check[group[0]] = true;

    while (!q.empty()) {
        int cnt = q.front();
        q.pop();

        for (int i = 1; i <= N; i++) {
            if (map[cnt][i] == 1 && check[i] == false) {
                check[i] = true;
                q.push(i);
            }
        }
    }

    bool allTrue = true;
    for (int i = 1; i <= N; i++) {
        if (check[i] == false) {
            allTrue = false;
        }
    }
    return allTrue;
}

void nCr(int r, int num) {
    if (r == num) {
        vector<int> group1;
        vector<int> group2;
        for (int i = 1; i <= N; i++) {
            if (check[i] == true) {
                group1.push_back(i);
            } else {
                group2.push_back(i);
            }
        }

        bool isConnected1, isConnected2;
        isConnected1 = bfs(group1);
        isConnected2 = bfs(group2);

        if (!isConnected1 || !isConnected2) {
            return;
        }

        int group1Sum = 0, group2Sum = 0;
        for (int i = 0; i < group1.size(); i++) {
            int index = group1[i];
            group1Sum += area[index];
        }

        for (int i = 0; i < group2.size(); i++) {
            int index = group2[i];
            group2Sum += area[index];
        }

        if (minDist > abs(group1Sum - group2Sum)) {
            minDist = abs(group1Sum - group2Sum);
        }

        return;
    }

    for (int i = 1; i <= N; i++) {
        if (check[i] == false) {
            check[i] = true;
            nCr(r, num + 1);
            check[i] = false;
        }
    }
}

int main(void) {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> area[i];
    }

    for (int i = 1; i <= N; i++) {
        int m;
        cin >> m;

        for (int j = 0; j < m; j++) {
            int b;
            cin >> b;

            map[i][b] = 1;
        }
    }

    for (int i = 1; i <= N / 2; i++) {
        nCr(i, 0);
    }

    if (minDist == INF) {
        cout << -1 << endl;
    } else
        cout << minDist << endl;
    return 0;
}