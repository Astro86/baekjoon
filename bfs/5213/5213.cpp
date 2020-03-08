#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int n;
pair<int, int> map[505][1010];
bool check[505][1010];
pair<int, int> trace[505][1010];
int traceY, traceX;
int maxIndex = 0;
int minNum = 0;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

struct point {
    int y;
    int x;
    int num;
};

int main(void) {
    cin >> n;

    int x, y;
    int num = 1;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < 2 * n; j += 2) {
                cin >> x >> y;
                map[i][j] = {num, x};
                map[i][j + 1] = {num, y};
                num++;
            }
        } else {
            for (int j = 1; j < 2 * n - 1; j += 2) {
                cin >> x >> y;
                map[i][j] = {num, x};
                map[i][j + 1] = {num, y};
                num++;
            }
        }
    }
    num--;
    queue<point> q;
    q.push({0, 0, 1});
    q.push({0, 1, 1});
    check[0][0] = true;
    check[0][1] = true;

    while (!q.empty()) {
        int cntY = q.front().y;
        int cntX = q.front().x;
        int cntNum = q.front().num;
        q.pop();

        // cout << cntY << ", " << cntX << " " << cntNum << endl;

        int cntIndex = map[cntY][cntX].first;
        int cntValue = map[cntY][cntX].second;

        if (cntIndex > maxIndex) {
            // cout << cntY << ", " << cntX << endl;
            maxIndex = cntIndex;
            minNum = cntNum;
            traceY = cntY, traceX = cntX;
        }

        for (int i = 0; i < 4; i++) {
            int ny = cntY + dy[i];
            int nx = cntX + dx[i];

            if (0 <= ny && ny < n && 0 <= nx && nx < 2 * n && map[ny][nx].second != 0) {
                int nextIndex = map[ny][nx].first;
                int nextValue = map[ny][nx].second;

                if (cntValue == nextValue && check[ny][nx] == false) {
                    check[ny][nx] = true;
                    trace[ny][nx] = {cntY, cntX};
                    q.push({ny, nx, cntNum + 1});

                    int nextnextIndex = map[ny][nx + 1].first;
                    if (nextnextIndex == nextIndex && check[ny][nx + 1] == false) {
                        check[ny][nx + 1] = true;
                        trace[ny][nx + 1] = {ny, nx};
                        q.push({ny, nx + 1, cntNum + 1});
                    }

                    nextnextIndex = map[ny][nx - 1].first;
                    if (nextnextIndex == nextIndex && check[ny][nx - 1] == false) {
                        check[ny][nx - 1] = true;
                        trace[ny][nx - 1] = {ny, nx};
                        q.push({ny, nx - 1, cntNum + 1});
                    }
                }
            }
        }
    }

    cout << minNum << '\n';

    stack<int> st;
    st.push(map[traceY][traceX].first);
    while (!(traceY == 0 && traceX == 0)) {
        pair<int, int> pre = trace[traceY][traceX];
        int preY = pre.first;
        int preX = pre.second;
        int preIndex = map[preY][preX].first;

        if (st.top() != preIndex) {
            st.push(preIndex);
        }
        traceY = preY;
        traceX = preX;
    }

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}