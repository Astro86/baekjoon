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

    if (size > 9) {
        size = 9;
    }

    for (int i = 1; i < size; i++) {
        int cntSize = i;

        for (int j = 0; j < fishes[cntSize].size(); j++) {
            if (Ate[cntSize][j] == false) {
                int d = bfs(y, x, fishes[cntSize][j].first, fishes[cntSize][j].second, size);

                if (Mindist > d) {
                    Mindist = d;
                    fishSize = cntSize;
                    index = j;
                    point = {fishes[cntSize][j].first, fishes[cntSize][j].second};
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
                    fishes[map[i][j]].push_back({i, j});
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
            fishPoint = calDist(cntSize, cntY, cntX);
            if (fishPoint.first == 0 && fishPoint.second == 0) {
                break;
            }
            Ate[fishPoint.first][fishPoint.second] = true;
            fishNum--;

            pair<int, int> fish = fishes[fishPoint.first][fishPoint.second];
            int d = bfs(cntY, cntX, fish.first, fish.second, cntSize);

            if (d == INF) {
                break;
            }

            cntEat++;
            if (cntEat == cntSize) {
                cntSize++;
                cntEat = 0;
            }

            totalTime += d;
            q.push({fish.first, fish.second, cntSize, cntEat});
        }
    }

    cout << totalTime << endl;
}