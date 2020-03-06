#include <iostream>
#include <queue>
using namespace std;

int T;
int w, h;
char map[1100][1100];
bool check[1100][1100];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool escape(queue<pair<int, int>>& q, int n)
{
    while (n--) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        if (y == h - 1 || x == w - 1 || x == 0 || y == 0) {
            return true;
        }

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (map[ny][nx] == '.' && check[ny][nx] == false) {
                check[ny][nx] = true;
                q.push({ ny, nx });
            }
        }
    }

    return false;
}

void fires(queue<pair<int, int>>& fire, int n)
{
    while (n--) {
        int y = fire.front().first;
        int x = fire.front().second;
        fire.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (0 <= ny && ny < h && 0 <= nx && nx < w) {
                if (map[ny][nx] == '.') {
                    map[ny][nx] = '*';
                    fire.push({ ny, nx });
                }
            }
        }
    }
}

int main(void)
{
    cin >> T;

    while (T--) {
        cin >> w >> h;
        queue<pair<int, int>> q;
        queue<pair<int, int>> fire;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                map[i][j] = 0;
                check[i][j] = false;
            }
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> map[i][j];

                if (map[i][j] == '@') {
                    map[i][j] = '.';
                    q.push({ i, j });
                    check[i][j] = true;
                }

                if (map[i][j] == '*') {
                    fire.push({ i, j });
                }
            }
        }

        int num = 0;
        bool isPass = false;
        while (!q.empty()) {
            num++;
            int q_size = q.size();
            int fire_size = fire.size();

            fires(fire, fire_size);
            isPass = escape(q, q_size);

            if (isPass) {
                cout << num << '\n';
                break;
            }
        }

        if (!isPass) {
            cout << "IMPOSSIBLE" << '\n';
        }
    }

    return 0;
}