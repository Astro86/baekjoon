#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define node 2001
#define INF 100000000

// 테스트 케이스 개수
int t;
// 정점의 개수, 간선의 개수, 예상 목적지 수
int v_num, e_num, d_num;
// 시작 정점, 중간에 거쳐가는 정점들
int start_node, g, h;
// 그래프를 저장하기 위한 vector
vector<vector<pair<int, int>>> vtx;

vector<int> dijkstra(int start_node)
{
    // 최단거리를 저장하기 위한 배열
    vector<int> dist(node, INF);
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
            }
        }
    }
    return dist;
}

int main(void)
{
    cin >> t;
    while (t--)
    {
        vtx = vector<vector<pair<int, int>>>(node);

        cin >> v_num >> e_num >> d_num;
        cin >> start_node >> g >> h;
        for (int i = 0; i < e_num; i++)
        {
            int a, b, w;
            cin >> a >> b >> w;
            vtx[a].push_back({b, w});
            vtx[b].push_back({a, w});
        }

        vector<int> dest;
        for (int i = 0; i < d_num; i++)
        {
            int temp;
            cin >> temp;
            dest.push_back(temp);
        }

        vector<int> dist_s = dijkstra(start_node);
        vector<int> dist_g = dijkstra(g);
        vector<int> dist_h = dijkstra(h);

        vector<int> dest_node;

        for (int i = 0; i < dest.size(); i++)
        {
            int d = dest[i];

            // start_node -> g -> h -> destination
            int min_dist1 = dist_s[g] + dist_g[h] + dist_h[d];
            // start_node -> h -> g -> destination
            int min_dist2 = dist_s[h] + dist_h[g] + dist_g[d];
            if (dist_s[d] == min(min_dist1, min_dist2))
            {
                dest_node.push_back(d);
            }
        }

        sort(dest_node.begin(), dest_node.end());
        for (int i = 0; i < dest_node.size(); i++)
        {
            cout << dest_node[i] << " ";
        }
        cout << '\n';
    }

    return 0;
}