#include <bits/stdc++.h>
using namespace std;

int N, M, H;
int Map[33][11];
int min_value = INT_MAX;

bool isAllI() {
    for (int i = 1; i <= N; i++) {
        int cnt_node = i;

        for (int j = 1; j <= H; j++) {
            if (cnt_node <= N && Map[j][cnt_node] == 1)
                cnt_node = cnt_node + 1;
            else if (cnt_node - 1 >= 1 && Map[j][cnt_node - 1] == 1)
                cnt_node = cnt_node - 1;
        }

        if (cnt_node != i) {
            return false;
        }
    }
    return true;
}

void dfs(int height, int num) {
    if (num > 3) {
        return;
    }

    if (isAllI()) {
        min_value = min(min_value, num);
        return;
    }

    for (int i = height; i <= H; i++) {
        for (int j = 1; j <= N; j++) {
            if (Map[i][j] == 0 && Map[i][j - 1] == 0 && Map[i][j + 1] == 0) {
                Map[i][j] = 1;
                dfs(i, num + 1);
                Map[i][j] = 0;
            }
        }
    }
}

int main(void) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N >> M >> H;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        Map[a][b] = 1;
    }

    dfs(1, 0);
    if (min_value == INT_MAX)
        cout << -1 << '\n';
    else
        cout << min_value << '\n';
    return 0;
}