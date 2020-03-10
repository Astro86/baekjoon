#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;
vector<vector<pair<int, int>>> map;
int startPoint, endPoint;

bool BFS(int limit) {
    queue<int> q;
    vector<bool> check(N + 1, false);

    q.push(startPoint);
    check[startPoint] = true;

    while (!q.empty()) {
        int cnt = q.front();
        q.pop();

        if (cnt == endPoint) {
            return true;
        }

        for (int i = 0; i < map[cnt].size(); i++) {
            int next = map[cnt][i].first;
            int weight = map[cnt][i].second;

            if (weight >= limit && check[next] == false) {
                check[next] = true;
                q.push(next);
            }
        }
    }

    return false;
}

int main(void) {
    cin >> N >> M;
    map = vector<vector<pair<int, int>>>(N + 1);
    int maxWeight = 0;

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        if (c > maxWeight) {
            maxWeight = c;
        }

        map[a].push_back({b, c});
        map[b].push_back({a, c});
    }

    cin >> startPoint >> endPoint;

    int low = 0;
    int high = maxWeight;
    while (low <= high) {
        int mid = (low + high) / 2;

        // wieght <= mid ?
        if (BFS(mid)) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << high << endl;
}
