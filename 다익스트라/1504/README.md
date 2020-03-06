# 백준 1504 - 특정한 최단 경로

[1504 - 특정한 최단 경로](https://www.acmicpc.net/problem/1504)

![](1504m.png)

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define node 801
#define INF 2000000000
// 정점의 개수 n 간선의 개수 e
int n, e;
// 중간에 거치는 노드
int a, b;
vector<pair<int, int>> vtx[node];
int dist[node];
int min_dist;
int total_dist;

void dijkstra(int start_node)
{
    min_dist = INF;
    for (int i = 0; i <= n; i++)
    {
        dist[i] = INF;
    }
    dist[start_node] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start_node});

    while (!pq.empty())
    {
        int iCost = pq.top().first;
        int Cur_node = pq.top().second;
        pq.pop();

        if (dist[Cur_node] < iCost)
            continue;

        for (int i = 0; i < vtx[Cur_node].size(); i++)
        {
            int next_node = vtx[Cur_node][i].first;
            int next_cost = iCost + vtx[Cur_node][i].second;

            if (dist[next_node] > next_cost)
            {
                dist[next_node] = next_cost;
                pq.push({next_cost, next_node});
                if (min_dist > next_cost)
                {
                    min_dist = next_cost;
                }
            }
        }
    }
}

int main(void)
{
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int s, e, w;
        cin >> a >> b >> w;
        vtx[a].push_back({b, w});
        vtx[b].push_back({a, w});
    }
    cin >> a >> b;

    // 1 -> a
    // 1 -> b
    dijkstra(1);
    long long dist1_a = dist[a];
    long long dist1_b = dist[b];

    // a -> b
    // a -> n
    dijkstra(a);
    long long dista_b = dist[b];
    long long dista_n = dist[n];

    // b -> a
    // b -> n
    dijkstra(b);
    long long distb_a = dist[a];
    long long distb_n = dist[n];

    long long total_dist = min(dist1_a + dista_b + distb_n, dist1_b + distb_a + dista_n);
    if (total_dist >= INF)
    {
        cout << "-1" << '\n';
    }
    else
        cout << total_dist << '\n';

    return 0;
}
```
