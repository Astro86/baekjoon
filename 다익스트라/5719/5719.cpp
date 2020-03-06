#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;
int start, destination;
vector<vector<pair<int, int>>> map;
vector<vector<pair<int, int>>> trace;
vector<vector<bool>> visited;
int minValue = 1000000000;
int result = 1000000000;

vector<int> dijkstra(int start, int vertex)
{
    vector<int> distance(vertex, 1000000000);
    distance[start] = 0;

    priority_queue<pair<int, int>> pq;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int cntVertex = pq.top().second;
        pq.pop();

        if (distance[cntVertex] < cost) {
            continue;
        }

        for (int i = 0; i < map[cntVertex].size(); i++) {
            int next = map[cntVertex][i].first;
            int nextWeight = cost + map[cntVertex][i].second;

            if (map[cntVertex][i].second == -1) {
                continue;
            }

            if (distance[next] > nextWeight) {
                distance[next] = nextWeight;
                pq.push({ -nextWeight, next });

                trace[next].clear();
                trace[next].push_back({ cntVertex, nextWeight });
            } else if (distance[next] == nextWeight) {
                trace[next].push_back({ cntVertex, nextWeight });
            }
        }
    }
    return distance;
}

void bfs(int destination)
{
    queue<int> q;
    q.push(destination);

    while (!q.empty()) {
        int cntVertex = q.front();
        q.pop();

        for (int i = 0; i < trace[cntVertex].size(); i++) {
            int pre = trace[cntVertex][i].first;

            if (visited[cntVertex][pre]) {
                continue;
            }

            for (int i = 0; i < map[pre].size(); i++) {
                if (map[pre][i].first == cntVertex) {
                    map[pre][i].second = -1;
                }
            }
            q.push(pre);
        }
    }
}

int main(void)
{
    while (true) {
        cin >> N >> M;
        cin >> start >> destination;
        if (N == 0 && M == 0)
            break;

        visited = vector<vector<bool>>(N + 1, vector<bool>(N + 1, false));
        trace = vector<vector<pair<int, int>>>(N + 1);
        map = vector<vector<pair<int, int>>>(N + 1);

        for (int i = 0; i < M; i++) {
            int a, b, w;
            cin >> a >> b >> w;

            map[a].push_back({ b, w });
        }
        dijkstra(start, N);
        bfs(destination);
        vector<int> result = dijkstra(start, N);

        if (result[destination] == 1000000000) {
            cout << -1 << '\n';
        } else {
            cout << result[destination] << '\n';
        }
    }
    return 0;
}