#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define INF 987654321

int N;
int map[22][22];
int startY, startX;
int totalTime = 0;
struct shark {
    int y;
    int x;
    int size;
    int eat;
};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue<shark> q;
vector<vector<pair<int, int>>> fishes(10);
vector<vector<bool>> Ate(10);
int fishNum;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    } else {
        return a.first < b.first;
    }
}

int bfs(int y, int x, int fishY, int fishX, int size) {
    struct point {
        int y;
        int x;
        int dist;
    };
    vector<vector<bool>> check(N, vector<bool>(N, false));

    queue<point> q;
    q.push({y, x, 0});
    check[y][x] = true;

    int Mindist = INF;

    while (!q.empty()) {
        int cntY = q.front().y;
        int cntX = q.front().x;
        int cntDist = q.front().dist;
        q.pop();

        if (cntY == fishY && cntX == fishX) {
            return cntDist;
        }

        for (int i = 0; i < 4; i++) {
            int ny = cntY + dy[i];
            int nx = cntX + dx[i];

            if (0 <= ny && ny < N && 0 <= nx && nx < N) {
                if (check[ny][nx] == false && map[ny][nx] <= size) {
                    check[ny][nx] = true;
                    q.push({ny, nx, cntDist + 1});
                }
            }
        }
    }

    return Mindist;
}

pair<int, int> calDist(int size, int y, int x) {
    int Mindist = INF;
    int fishSize = 0;
    int index = 0;
    pair<int, int> point;

    // 9할 필요 없었고 6까지 해도 충분 했을 듯...
    if (size > 9) {
        size = 9;
    }

    // 1 ~ size까지의 물고기크기 (물고기 최대크기는 6까지임)
    for (int i = 1; i < size; i++) {
        int cntSize = i;

        for (int j = 0; j < fishes[cntSize].size(); j++) {
            // 아직 해당 물고기를 안먹었으면 dfs를 이용해 거리를 계산해준다.
            // 좌표 평면 거리(y2-y1) + (x2 - x1)를 통해 계산을 안하는 이유는 가다가 막히는 경우가 생기기 때문이다.
            if (Ate[cntSize][j] == false) {
                int d = bfs(y, x, fishes[cntSize][j].first, fishes[cntSize][j].second, size);

                // 아기상어가 갈 수 없을 경우, 건너뛴다.
                if (d == INF) {
                    continue;
                }

                // 최소 거리와 비교해준다.
                if (Mindist > d) {
                    Mindist = d;
                    fishSize = cntSize;
                    index = j;
                    point = {fishes[cntSize][j].first, fishes[cntSize][j].second};
                    //거리가 같을 경우
                } else if (Mindist == d) {
                    if (!cmp(point, fishes[cntSize][j])) {
                        fishSize = cntSize;
                        index = j;
                        point = fishes[cntSize][j];
                    }
                }
            }
        }
    }
    return {fishSize, index};
}

int dist(int fishY, int fishX, int y, int x) {
    return abs(fishY - y) + abs(fishX - x);
}

int main(void) {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];

            if (map[i][j] == 9) {
                startY = i;
                startX = j;
                map[i][j] = 0;
            } else {
                if (map[i][j] != 0) {
                    // map[i][j]는 물고기의 크기이다.
                    // fish는 물고기 크기에 따른 물고기의 좌표들을 저장하기 위한 배열
                    fishes[map[i][j]].push_back({i, j});
                    // Ate는 해당 물고기가 먹혔는지 안먹혔는지를 확인하기 위한 배열
                    Ate[map[i][j]].push_back(false);
                    fishNum++;
                }
            }
        }
    }

    for (int i = 1; i < 10; i++) {
        sort(fishes[i].begin(), fishes[i].end(), cmp);
    }

    q.push({startY, startX, 2, 0});
    pair<int, int> fishPoint;

    while (!q.empty()) {
        int cntY = q.front().y;
        int cntX = q.front().x;
        int cntSize = q.front().size;
        int cntEat = q.front().eat;
        q.pop();

        if (fishNum > 0) {
            // 현재 상어와 먹을 수 있는 물고기의 좌표를 알아낸다.
            fishPoint = calDist(cntSize, cntY, cntX);

            // 상어가 먹을 수 있는 물고기가 존재하지 않을 경우 나간다.
            if (fishPoint.first == 0 && fishPoint.second == 0) {
                break;
            }

            // 상어가 먹을 물고기가 존재하는 경우, 그 물고기를 먹고 물고기 갯수를 줄인다.
            Ate[fishPoint.first][fishPoint.second] = true;
            fishNum--;

            // 상어와 물고기와의 거리를 계산한다.
            pair<int, int> fish = fishes[fishPoint.first][fishPoint.second];
            int d = bfs(cntY, cntX, fish.first, fish.second, cntSize);

            // 상어가 먹은 물고기의 갯수를 늘려준다.
            cntEat++;
            // 만일 먹은 물고기 갯수와 상어의 크기가 같다면 상어의 크기를 늘려주고, 먹은 갯수를 초기화 해준다.
            if (cntEat == cntSize) {
                cntSize++;
                cntEat = 0;
            }

            // 물고기를 먹으러 간 거리만큼 시간을 더해준다.
            totalTime += d;
            q.push({fish.first, fish.second, cntSize, cntEat});
        }
    }

    cout << totalTime << endl;
}