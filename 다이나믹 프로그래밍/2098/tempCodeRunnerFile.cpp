#include <bits/stdc++.h>
using namespace std;

#define INF 987654321

int n;
int Map[16][16];
int dp[16][1 << 16];

int TSP(int cnt, int check) {
    if (check == (1 << n) - 1) {
        if (dp[cnt][0] == 0) {
            return INF;
        } else {
            return Map[cnt][0];
        }
    }

    int& result = dp[cnt][check];
    if (result != -1) {
        return result;
    }
    result = INF;

    for (int i = 0; i < n; i++) {
        if (check & (1 << i) || Map[cnt][i] == 0)
            continue;

        int value = Map[cnt][i] + TSP(i, check + (1 << i));
        result = min(result, value);
    }

    return result;
}

int main(void) {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> Map[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << 16); j++) {
            dp[i][j] = -1;
        }
    }

    int answer = TSP(0, 1);
    cout << answer << '\n';
    return 0;
}