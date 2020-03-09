#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

#define INF 987654321

int N;
int section[11];
int map[11][11];
bool point[11];
int minDist = INF;

void choose(int node, int num, int cnt) {
    if (num == cnt) {
        vector<bool> check(N + 1, false);
        queue<int> q;
        int start;
        for (int i = 1; i <= N; i++) {
            if (point[i] == true) {
                check[i] = true;
            } else {
                start = i;
            }
        }
        q.push(start);
        check[start] = true;

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

        bool isPass = true;
        for (int i = 1; i <= N; i++) {
            if (check[i] == false) {
                isPass = false;
            }
        }

        if (!isPass) {
            return;
        }

        int sumTrue = 0;
        int sumFalse = 0;
        for (int i = 1; i <= N; i++) {
            if (point[i] == true) {
                sumTrue += section[i];
            } else {
                sumFalse += section[i];
            }
        }

        if (minDist > abs(sumTrue - sumFalse)) {
            for (int i = 1; i <= N; i++) {
                if (point[i] == true) {
                    cout << i << " ";
                }
            }
            cout << endl;
            for (int i = 1; i <= N; i++) {
                if (point[i] == false) {
                    cout << i << " ";
                }
            }
            cout << endl;

            minDist = abs(sumTrue - sumFalse);
        }
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (map[node][i] == 1 && point[i] == false) {
            point[i] = true;
            choose(i, num, cnt + 1);
            point[i] = false;
        }
    }
}

int main(void) {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> section[i];
    }

    for (int i = 1; i <= N; i++) {
        int m;
        cin >> m;

        for (int j = 0; j < m; j++) {
            int adjacent;
            cin >> adjacent;
            map[i][adjacent] = 1;
        }
    }

    for (int i = 1; i <= N / 2; i++) {
        for (int j = 1; j <= N; j++) {
            point[j] = true;
            choose(j, i, 1);
            point[j] = false;
        }
    }

    if (minDist == INF) {
        cout << -1 << endl;
    } else
        cout << minDist << endl;

    return 0;
}