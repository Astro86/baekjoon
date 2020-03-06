#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int t;
int n;
int startX, startY;
int convenX[101];
int convenY[101];
int destX, destY;

int dis(int x, int X, int y, int Y)
{
    return abs(x - X) + abs(y - Y);
}

int main(void)
{
    cin >> t;

    while (t--) {
        cin >> n;

        cin >> startX >> startY;
        for (int i = 0; i < n; i++) {
            cin >> convenX[i] >> convenY[i];
        }
        cin >> destX >> destY;

        vector<bool> check(n, false);
        queue<pair<int, int>> q;
        q.push({ startX, startY });

        bool isPass = true;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (dis(destX, x, destY, y) <= 1000) {
                cout << "happy" << '\n';
                isPass = false;
                break;
            }

            for (int i = 0; i < n; i++) {
                int nextX = convenX[i];
                int nextY = convenY[i];

                if (dis(x, nextX, y, nextY) <= 1000 && check[i] == false) {
                    check[i] = true;
                    q.push({ nextX, nextY });
                }
            }
        }

        if (isPass)
            cout << "sad" << '\n';
    }
    return 0;
}