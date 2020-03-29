#include <bits/stdc++.h>
using namespace std;

#define MAX 55
#define INF 987654321

int lab[MAX][MAX];
int copied_lab[MAX][MAX];
int lab_size;
int virus_num;
vector<pair<int, int>> virus_point;
vector<vector<int>> arr_active_virus;
bool check[MAX][MAX];
int virus[MAX];
int minValue = INF;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

struct Point {
    int y;
    int x;
    int num;
};

bool isAllVirus() {
    for (int i = 0; i < lab_size; i++) {
        for (int j = 0; j < lab_size; j++) {
            if (lab[i][j] == 0 && check[i][j] == false) {
                return false;
            }
        }
    }

    return true;
}

void chooseVirus(int num, int index) {
    if (num == virus_num) {
        vector<int> v(virus_point.size());

        for (int i = 0; i < virus_point.size(); i++) {
            v[i] = virus[i];
        }
        arr_active_virus.push_back(v);
        return;
    }

    for (int i = index; i < virus_point.size(); i++) {
        virus[i] = 1;
        chooseVirus(num + 1, i + 1);
        virus[i] = 0;
    }
}

void bfs(int index) {
    queue<Point> q;
    memset(check, false, sizeof(check));
    vector<int> active_virus = arr_active_virus[index];

    for (int i = 0; i < active_virus.size(); i++) {
        if (active_virus[i] == 1) {
            q.push({virus_point[i].first, virus_point[i].second, 0});
            check[virus_point[i].first][virus_point[i].second] = true;
        }
    }

    int cnt = 0;
    while (!q.empty()) {
        int cntY = q.front().y;
        int cntX = q.front().x;
        int cntNum = q.front().num;
        q.pop();

        if (cnt < cntNum && lab[cntY][cntX] == 0) {
            cnt = cntNum;
        }

        for (int i = 0; i < 4; i++) {
            int ny = cntY + dy[i];
            int nx = cntX + dx[i];

            if (0 <= ny && ny < lab_size && 0 <= nx && nx < lab_size) {
                if (check[ny][nx] == false && lab[ny][nx] == 0) {
                    check[ny][nx] = true;
                    q.push({ny, nx, cntNum + 1});
                } else if (check[ny][nx] == false && lab[ny][nx] == 2) {
                    check[ny][nx] = true;
                    q.push({ny, nx, cntNum + 1});
                }
            }
        }
    }
    if (isAllVirus())
        minValue = min(minValue, cnt);
}

int main(void) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> lab_size >> virus_num;

    for (int i = 0; i < lab_size; i++) {
        for (int j = 0; j < lab_size; j++) {
            cin >> lab[i][j];

            if (lab[i][j] == 2) {
                virus_point.push_back({i, j});
            }
        }
    }

    chooseVirus(0, 0);
    for (int i = 0; i < arr_active_virus.size(); i++) {
        bfs(i);
    }

    if (minValue == INF)
        cout << -1 << '\n';
    else
        cout << minValue << '\n';
    return 0;
}
