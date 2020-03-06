#include <iostream>
#include <queue>
#include <vector>
// #include <functional>
using namespace std;

#define INF 1000000000
#define SIZE 20001

int v_num, e_num, start_node;
vector<pair<int, int>> v[SIZE];
int dist[SIZE];

void dijkstra()
{
    for (int i = 1; i <= v_num; i++)
        dist[i] = INF;
    dist[start_node] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start_node});

    while (!pq.empty())
    {
        int iCost = pq.top().first;
        int Cur_node = pq.top().second;
        pq.pop();

        // 더 이상 최단거리가 아닐 경우
        if (dist[Cur_node] < iCost)
            continue;
        for (int i = 0; i < v[Cur_node].size(); i++)
        {
            int next_node = v[Cur_node][i].first;
            int next_cost = iCost + v[Cur_node][i].second;

            if (dist[next_node] > next_cost)
            {
                dist[next_node] = next_cost;
                pq.push({next_cost, next_node});
            }
        }
    }
    for (int i = 1; i <= v_num; i++)
    {
        if (dist[i] != INF)
        {
            cout << dist[i] << endl;
        }
        else
        {
            cout << INF << endl;
        }
    }
}

int main(void)
{
    cin >> v_num >> e_num >> start_node;

    for (int i = 0; i <= e_num; i++)
    {
        int s, e, w;
        cin >> s >> e >> w;
        v[s].push_back({e, w});
    }

    dijkstra();
}