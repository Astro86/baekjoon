#include <iostream>
#include <queue>
using namespace std;

int n;
// int arr[10001][10001];
vector<pair<int, int>> arr[10001];
int maxValue;

int main(void)
{
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x, y, w;
        cin >> x >> y >> w;

        arr[x].push_back({ y, w });
        arr[y].push_back({ x, w });
    }

    for (int i = 1; i <= n; i++) {
        bool check[10001];
        queue<pair<int, int>> q;

        for (int j = 0; j < 10001; j++) {
            check[j] = false;
        }

        q.push({ i, 0 });
        check[i] = true;

        while (!q.empty()) {
            int cnt = q.front().first;
            int value = q.front().second;
            q.pop();

            if (maxValue < value) {
                maxValue = value;
            }

            for (int j = 0; j < arr[cnt].size(); j++) {
                int next = arr[cnt][j].first;
                int weight = arr[cnt][j].second;

                if (check[next] == false) {
                    check[next] = true;
                    q.push({ next, value + weight });
                }
            }
        }
    }

    cout << maxValue << '\n';
}