#include <iostream>
using namespace std;

int N;
long long dp[110][10];
long long value = 1000000000;

int main(void) {
    cin >> N;

    dp[1][0] = 0;
    for (int i = 1; i <= 9; i++) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= N; i++) {
        dp[i][0] = dp[i - 1][1] % value;
        for (int j = 1; j <= 8; j++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1] % value;
        }
        dp[i][9] = dp[i - 1][8] % value;
    }

    // for (int i = 0; i <= 9; i++)
    //     cout << dp[N][i] << " ";
    // }

    long long sum = 0;
    for (int i = 0; i <= 9; i++) {
        sum += dp[N][i];
    }

    cout << sum % value << '\n';

    return 0;
}