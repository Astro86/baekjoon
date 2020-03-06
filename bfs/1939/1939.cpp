#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;
int start, finish;
vector<bool> check;
vector<vector<pair<int, int>>> map;
vector<vector<pair<int, int>>> bridge;

bool BFS(int cost)
{
    queue<int> q;
    q.push(start);
    check[start] = true;

    while (!q.empty()) {
        int cnt = q.front();
        q.pop();

        if (cnt == finish) {
            return true;
        }

        for (int i = 0; i < map[cnt].size(); i++) {
            int next = map[cnt][i].first;
            int nextCost = map[cnt][i].second;

            if (check[next] == false && cost <= nextCost) {
                check[next] = true;
                q.push(next);
            }
        }
    }

    return false;
}

int main(void)
{
    cin >> N >> M;
    map = vector<vector<pair<int, int>>>(N + 1);
    int maxBridge = 0;

    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;

        map[A].push_back({ B, C });
        map[B].push_back({ A, C });
        maxBridge = max(maxBridge, C);
    }

    cin >> start >> finish;

    int low = 0, high = maxBridge;
    while (low <= high) {
        check = vector<bool>(N + 1, false);

        int mid = (low + high) / 2;
        if (BFS(mid)) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << high << '\n';
    return 0;
}